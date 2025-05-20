//FormAI DATASET v1.0 Category: Linked list operations ; Style: protected
//Program to perform basic Linked List operations in C
#include<stdlib.h>
#include<stdio.h>

//define the node structure
typedef struct node
{
    int data;
    struct node *next;
}node;

//function to insert element at beginning of Linked List
void insertNodeAtBeginning(node **headRef, int data)
{
    node *newNode = (node*)malloc(sizeof(node)); //allocate memory for new node
    newNode->data = data; //store data in new node
    newNode->next = *headRef; //point the next pointer to head of Linked List
    *headRef = newNode; //make the new node as the head of Linked List
    printf("New node with data %d inserted at beginning of list\n", data);
}

//function to insert element at end of Linked List
void insertNodeAtEnd(node **headRef, int data)
{
    node *newNode = (node*)malloc(sizeof(node)); //allocate memory for new node
    newNode->data = data; //store data in new node
    newNode->next = NULL; //point the next pointer to NULL as it is last node
    if(*headRef == NULL) //if Linked List is empty
    {
        *headRef = newNode; //make the new node as the head of Linked List
        printf("New node with data %d inserted at end of list\n", data);
        return;
    }
    node *temp = *headRef; //temporary pointer to traverse the Linked List
    while(temp->next != NULL) //traverse till end of Linked List is reached
    {
        temp = temp->next;
    }
    temp->next = newNode; //point the next pointer of last node to the new node
    printf("New node with data %d inserted at end of list\n", data);
}

//function to delete node with given data from Linked List
void deleteNode(node **headRef, int data)
{
    if(*headRef == NULL) //if Linked List is empty
    {
        printf("Linked List is empty. Cannot delete\n");
        return;
    }
    node *temp = *headRef; //temporary pointer to traverse the Linked List
    if(temp->data == data) //if first node has the data
    {
        *headRef = temp->next; //make second node as the head of Linked List
        free(temp); //free the memory of deleted node
        printf("Node with data %d deleted from list\n", data);
        return;
    }
    node *prev = NULL; //pointer to keep track of previous node
    while(temp != NULL && temp->data != data) //traverse till node with given data is found or end of Linked List is reached
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) //if node with given data is not found
    {
        printf("Node with data %d not found in list\n", data);
        return;
    }
    prev->next = temp->next; //point next pointer of previous node to next node of deleted node
    free(temp); //free the memory of deleted node
    printf("Node with data %d deleted from list\n", data);
}

//function to display the Linked List
void displayList(node *head)
{
    if(head == NULL) //if Linked List is empty
    {
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked List: ");
    while(head != NULL) //traverse till end of Linked List is reached
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    int choice, data;
    do
    {
        printf("Menu:\n1.Insert node at beginning\n2.Insert node at end\n3.Delete node\n4.Display Linked List\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertNodeAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertNodeAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Try again\n");
                break;
        }
    }while(choice != 5);
    return 0;
}