#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length(node* head); {
		int count = 0; //counts the number of nodes
		while (head != NULL) { //if its not null
			count++; // it'll increment 
			head = head->next; //point to next node
		}
	return count;
	}
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head); //gets the length of the list
	char* str = (char*)malloc((len + 1) *sizeof(char)); //allocates memory
	int i = 0;
	while(head = NULL) {
		str[i] = head->letter; //points to the string 
		head = head->next; //points to next
		i++;
	}
	str[i] = '\0'; //null terminator
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
node* newNode = (node*)malloc(sizeof(node)); //allocates memory
newNode->letter = c; //sets the char in new node
newNode->next = NULL; //new node points to last
if(*pHead == NULL) { //if null, node becomes head
*pHead = newNode;
}
else {
	node* temp = *pHead;
	while (temp->next != NULL) {
		temp = temp->next; //traverses the list
	}
	temp->next =newNode; //add new node at the end
}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while (*pHead != NULL) {
		node* temp = *pHead; //temp pointer for head
		*pHead = (*pHead)->next; //moves head to next node
		free(temp); //frees the memory 
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}