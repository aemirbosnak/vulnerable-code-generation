//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
} List;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new linked list
List* newList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

// Function to add a node to the end of the linked list
void addNode(List* list, int data) {
    Node* node = newNode(data);
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

// Function to print the linked list
void printList(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    List* list = newList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    printList(list);
    return 0;
}