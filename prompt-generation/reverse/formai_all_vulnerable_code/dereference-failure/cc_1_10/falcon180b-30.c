//Falcon-180B DATASET v1.0 Category: Database querying ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure for Linked List
struct Node{
    char data[100];
    struct Node* next;
};

//Function prototypes
void addNode(struct Node**, char*);
void printList(struct Node*);
struct Node* search(struct Node*, char*);
void deleteNode(struct Node**, char*);

//Main function
int main(){
    struct Node* head = NULL;

    //Adding nodes to the linked list
    addNode(&head, "John");
    addNode(&head, "Doe");
    addNode(&head, "Jane");
    addNode(&head, "Doe");

    //Printing the linked list
    printf("Linked List: \n");
    printList(head);

    //Searching for a node in the linked list
    struct Node* result = search(head, "Doe");
    if(result!= NULL){
        printf("\nNode found with name: %s\n", result->data);
    }else{
        printf("\nNode not found.\n");
    }

    //Deleting a node from the linked list
    deleteNode(&head, "Doe");

    //Printing the linked list after deletion
    printf("\nLinked List after deletion:\n");
    printList(head);

    return 0;
}

//Function to add a node to the linked list
void addNode(struct Node** headRef, char* newData){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data, newData);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

//Function to print the linked list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

//Function to search for a node in the linked list
struct Node* search(struct Node* head, char* key){
    struct Node* current = head; 

    while(current!= NULL){
        if(strcmp(current->data, key) == 0){
            return current;
        }
        current = current->next;
    }

    return NULL;
}

//Function to delete a node from the linked list
void deleteNode(struct Node** headRef, char* key){
    struct Node* temp = *headRef;
    struct Node* prev;

    if(strcmp(temp->data, key) == 0){
        *headRef = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && strcmp(temp->data, key)!= 0){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}