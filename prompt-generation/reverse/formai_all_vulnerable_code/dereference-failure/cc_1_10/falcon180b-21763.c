//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};
//Linked List structure
struct LinkedList{
    struct Node* head;
};

//Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to create a new linked list
struct LinkedList* createLinkedList(){
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    return newList;
}

//Function to add a node at the end of the linked list
void addNode(struct LinkedList* list, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = list->head;
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to print the linked list
void printList(struct LinkedList* list){
    struct Node* temp = list->head;
    printf("Linked List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main(){
    struct LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printList(list);
    return 0;
}