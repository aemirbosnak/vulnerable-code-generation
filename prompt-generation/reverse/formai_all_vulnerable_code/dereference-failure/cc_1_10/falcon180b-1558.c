//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of a node
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add a node at the end of the list
void addNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
    }
    else{
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

//Function to delete a node with the given data
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//Function to search for a node with the given data
struct Node* searchNode(struct Node* head, int data){
    struct Node* temp = head;
    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }
    return temp;
}

//Function to print the list
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int choice, data;

    //Menu-driven program to perform various operations on the list
    do{
        printf("Enter your choice:\n");
        printf("1. Add a node\n2. Delete a node\n3. Search for a node\n4. Print the list\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the data for the node to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter the data for the node to be searched: ");
                scanf("%d", &data);
                struct Node* result = searchNode(head, data);
                if(result!= NULL){
                    printf("Node found!\n");
                }
                else{
                    printf("Node not found.\n");
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(1);

    return 0;
}