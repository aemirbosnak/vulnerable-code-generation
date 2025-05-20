//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a structure for a linked list
typedef struct linkedList {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node to the end of a linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (temp == NULL) {
        list->head = newNode;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to print a linked list
void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a node in a linked list
bool searchNode(LinkedList* list, int data) {
    Node* temp = list->head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to delete a node from a linked list
void deleteNode(LinkedList* list, int data) {
    Node* temp = list->head;
    if (temp!= NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    Node* nextNode = temp->next;
    free(temp);
    temp = nextNode;
    while (temp!= NULL) {
        if (temp->data == data) {
            temp = temp->next;
            free(nextNode);
            list->size--;
            return;
        }
        nextNode = temp;
        temp = temp->next;
    }
}

// Function to reverse a linked list
void reverseLinkedList(LinkedList* list) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    printLinkedList(list);
    printf("Size: %d\n", list->size);
    deleteNode(list, 3);
    printLinkedList(list);
    printf("Size: %d\n", list->size);
    reverseLinkedList(list);
    printLinkedList(list);
    printf("Size: %d\n", list->size);
    free(list->head);
    free(list);
    return 0;
}