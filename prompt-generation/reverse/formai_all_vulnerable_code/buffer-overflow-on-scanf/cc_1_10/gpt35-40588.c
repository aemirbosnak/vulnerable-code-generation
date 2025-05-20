//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

//structure to represent a node in the linked list
struct Node{
    int data;           //data stored in the node
    struct Node* next;  //pointer to the next node in the linked list
};

//function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));    //allocate memory for new node
    newNode->data = newData;        //assign data to the new node
    newNode->next = *headRef;       //link new node to the current head node
    *headRef = newNode;             //make the new node as the head node
}

//function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));    //allocate memory for new node
    newNode->data = newData;        //assign data to the new node
    newNode->next = NULL;           //set next of new node to null
    
    if(*headRef == NULL){           //if linked list is empty
        *headRef = newNode;         //make the new node as the head node
        return;
    }
    
    struct Node* currentNode = *headRef;
    while(currentNode->next != NULL){   //traverse the linked list till last node is reached
        currentNode = currentNode->next;
    }
    
    currentNode->next = newNode;    //make the new node as the last node
}

//function to delete a node from the linked list
void deleteNode(struct Node** headRef, int key){
    struct Node* currentNode = *headRef;
    struct Node* prevNode = NULL;
    
    //if head node itself needs to be deleted
    if(currentNode != NULL && currentNode->data == key){
        *headRef = currentNode->next;      //change head node
        free(currentNode);          //free old head node
        return;
    }
    
    //search for the key to be deleted and keep track of previous node
    while(currentNode != NULL && currentNode->data != key){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    //if key was not present in linked list
    if(currentNode == NULL){
        return;
    }
    
    prevNode->next = currentNode->next;    //unlink the node to be deleted from the linked list
    free(currentNode);          //free memory of the node to be deleted
}

//function to print the linked list
void printList(struct Node* head){
    struct Node* currentNode = head;
    while(currentNode != NULL){
        printf("%d->", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

//main function
int main(){
    int choice, data;
    struct Node* head = NULL;   //initialize head node as null
    
    //display menu to user
    while(1){
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Delete node\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);    //call function to insert node at beginning
                printf("Node inserted successfully at beginning!\n");
                break;
                
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);      //call function to insert node at end
                printf("Node inserted successfully at end!\n");
                break;
                
            case 3:
                printf("Enter node data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);    //call function to delete a node
                printf("Node deleted successfully!\n");
                break;
                
            case 4:
                printf("Linked List: ");
                printList(head);    //call function to print linked list
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);    //exit the program
                break;
                
            default:
                printf("Invalid choice. Please try again!\n");
        }
    }
    
    return 0;
}