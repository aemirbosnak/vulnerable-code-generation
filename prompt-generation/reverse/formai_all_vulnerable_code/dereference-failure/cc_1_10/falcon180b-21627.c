//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the linked list
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a new empty linked list
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Add a node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* currNode = list->head;
        while (currNode->next!= NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    list->size++;
}

// Remove a node with the given data from the linked list
void removeNode(LinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->data == data) {
        Node* tempNode = list->head;
        list->head = list->head->next;
        free(tempNode);
        list->size--;
        return;
    }
    Node* currNode = list->head;
    while (currNode->next!= NULL && currNode->next->data!= data) {
        currNode = currNode->next;
    }
    if (currNode->next == NULL) {
        return;
    }
    Node* tempNode = currNode->next;
    currNode->next = currNode->next->next;
    free(tempNode);
    list->size--;
}

// Print the contents of the linked list
void printList(LinkedList* list) {
    Node* currNode = list->head;
    printf("List contents:\n");
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    LinkedList* myList = createLinkedList();
    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);
    printList(myList);
    removeNode(myList, 2);
    printList(myList);
    return 0;
}