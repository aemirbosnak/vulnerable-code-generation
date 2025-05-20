//FormAI DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>   //for standard input/output functions
#include <stdlib.h>  //for malloc function

struct Node {         //define a structure called Node
    int data;         //an integer data
    struct Node* next;//a Node pointer to point to next Node
};

typedef struct Node* pNode;  //define a new data type pNode which is a pointer to a Node

void Insert(pNode *head, int value);    //function to insert a new Node at the beginning of the list
void Append(pNode *head, int value);    //function to insert a new Node at the end of the list
void Delete(pNode *head, int value);    //function to delete a Node from the list
void PrintList(pNode head);             //function to print the contents of the list
void Reverse(pNode *head);              //function to reverse the list

int main()  //main function
{
    pNode head = NULL; //initialize head pointer to NULL
    int choice, value;

    do {
        printf("\nMENU\n");
        printf("1. Insert Node\n");
        printf("2. Append Node\n");
        printf("3. Delete Node\n");
        printf("4. Print List\n");
        printf("5. Reverse List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            Insert(&head, value);   //call Insert function
            break;

        case 2:
            printf("Enter the value to be appended: ");
            scanf("%d", &value);
            Append(&head, value);   //call Append function
            break;

        case 3:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            Delete(&head, value);   //call Delete function
            break;

        case 4:
            PrintList(head);        //call PrintList function
            break;

        case 5:
            Reverse(&head);         //call Reverse function
            break;

        case 6:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;   //Exit the program
}

void Insert(pNode *head, int value)
{
    pNode newNode = (pNode)malloc(sizeof(struct Node));   //allocate memory for new Node
    newNode->data = value;  //set the value of the new Node
    newNode->next = *head;  //point the next pointer of the new Node to the current head Node
    *head = newNode;        //set the head pointer to the new Node
    printf("Node with value %d was inserted.\n", value);
}

void Append(pNode *head, int value)
{
    pNode newNode = (pNode)malloc(sizeof(struct Node));   //allocate memory for new Node
    newNode->data = value;          //set the value of the new Node
    newNode->next = NULL;           //set the next pointer of the new Node to NULL

    if (*head == NULL) {            //if LinkedList is empty
        *head = newNode;            //set the head pointer to the new Node
    }
    else {
        pNode lastNode = *head;     //initialize lastNode pointer to head
        while (lastNode->next != NULL) {    //traverse through the LinkedList to find the last Node
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;   //set the next pointer of the last Node to the new Node
    }
    printf("Node with value %d was appended.\n", value);
}

void Delete(pNode *head, int value)
{
    if (*head == NULL) {    //if LinkedList is empty
        printf("LinkedList is empty. Nothing to delete.\n");
        return;
    }

    pNode temp = *head;     //initialize a temporary pointer to head

    if ((*head)->data == value) {   //if the value to be deleted is found at the head
        *head = temp->next;         //set the head pointer to the next Node
        free(temp);                 //free the memory allocated for the deleted Node
        printf("Node with value %d was deleted.\n", value);
        return;
    }

    while (temp->next != NULL && temp->next->data != value) { //traverse through the LinkedList to find the Node with the value to be deleted
        temp = temp->next;
    }

    if (temp->next == NULL) {   //if the value to be deleted is not found in the list
        printf("The value %d was not found in the list.\n", value);
        return; 
    }
    
    pNode deletedNode = temp->next;     //store the Node to be deleted in a temporary pointer
    temp->next = deletedNode->next;     //set the next pointer of the previous Node to the next Node of the deleted Node
    free(deletedNode);                  //free the memory allocated for the deleted Node
    printf("Node with value %d was deleted.\n", value);
}

void PrintList(pNode head)
{
    if (head == NULL) { //if LinkedList is empty
        printf("LinkedList is empty.\n");
        return;
    }

    printf("LinkedList: ");
    pNode temp = head;  //initialize a temporary pointer to head

    while (temp != NULL) {  //traverse through the LinkedList and print the values of the Nodes
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse(pNode *head)
{
    if (*head == NULL) {    //if LinkedList is empty
        printf("LinkedList is empty. Nothing to reverse.\n");
        return; 
    }

    pNode prevNode = NULL;  //initialize a previous Node pointer to NULL
    pNode currentNode = *head;  //initialize a current Node pointer to head
    pNode nextNode = NULL;  //initialize a next Node pointer to NULL

    while (currentNode != NULL) {   //traverse through the LinkedList and reverse the pointers of the Nodes
        nextNode = currentNode->next;   //store the next Node in the temporary pointer nextNode
        currentNode->next = prevNode;   //reverse the next pointer of the current Node
        prevNode = currentNode;         //set the previous Node pointer to the current Node
        currentNode = nextNode;         //set the current Node pointer to the next Node
    }
    *head = prevNode;   //set the head pointer to the last Node in the LinkedList
    printf("LinkedList has been reversed.\n");
}