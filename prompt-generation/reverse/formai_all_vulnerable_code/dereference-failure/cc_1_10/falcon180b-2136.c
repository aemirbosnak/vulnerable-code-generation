//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Node structure for linked list
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

//Function to insert a node at the end of the list
void insertNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    //If the list is empty
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    //Inserting the new node at the end
    temp->next = newNode;
    newNode->next = NULL;
}

//Function to search for an element in the list
struct Node* searchList(struct Node* head, int data){
    struct Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Function to delete a node from the list
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    //If the list is empty
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    //If the node to be deleted is the first node
    if(temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    //If the node is not found
    if(temp == NULL){
        return;
    }
    //Deleting the node
    prev->next = temp->next;
    free(temp);
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
    //Inserting elements into the list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);
    //Printing the list
    printList(head);
    //Searching for an element in the list
    struct Node* result = searchList(head, 30);
    if(result!= NULL){
        printf("Element found\n");
    }
    else{
        printf("Element not found\n");
    }
    //Deleting an element from the list
    deleteNode(&head, 20);
    //Printing the updated list
    printList(head);
    return 0;
}