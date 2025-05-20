//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the linked list structure
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Function prototypes
LinkedList* createLinkedList();
void addNode(LinkedList* list, int data);
void deleteNode(LinkedList* list, int data);
void printLinkedList(LinkedList* list);

int main() {
    LinkedList* myList = createLinkedList();
    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);
    printLinkedList(myList);
    deleteNode(myList, 2);
    printLinkedList(myList);
    return 0;
}

// Create a new linked list
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Add a new node to the end of the list
void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Delete a node with the given data value
void deleteNode(LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    Node* prev = list->head;
    while (prev->next!= NULL && prev->next->data!= data) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        printf("Node not found\n");
        return;
    }
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
    list->size--;
}

// Print the contents of the linked list
void printLinkedList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}