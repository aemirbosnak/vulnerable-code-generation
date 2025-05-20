//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct Node{
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head, int data){
    Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to add a node at the end of the list
void append(Node** head, int data){
    Node* node = newNode(data);
    Node* last = *head;

    if(*head == NULL){
        push(head, data);
        return;
    }

    while(last->next!= NULL){
        last = last->next;
    }

    last->next = node;
}

// Function to insert a node after a given position
void insertAfter(Node* prevNode, int data){
    if(prevNode == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }

    Node* node = newNode(data);
    node->next = prevNode->next;
    prevNode->next = node;
}

// Function to delete a node by key
void deleteNode(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;

    if(temp!= NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node not found with the given key");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    Node* head = NULL;

    // Add nodes
    push(&head, 1);
    append(&head, 2);
    insertAfter(head->next, 3);

    // Print list
    printf("List: ");
    printList(head);

    // Delete node
    deleteNode(&head, 2);

    // Print list
    printf("\nList after deleting node with key 2: ");
    printList(head);

    return 0;
}