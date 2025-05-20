//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a linked list structure
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Initialize an empty linked list
LinkedList* linkedListInit() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Add a node to the end of the linked list
void linkedListAdd(LinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* curr = list->head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    list->size++;
}

// Print the linked list
void linkedListPrint(LinkedList* list) {
    Node* curr = list->head;
    printf("Linked List: ");
    while (curr!= NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void linkedListReverse(LinkedList* list) {
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

// Free the memory used by the linked list
void linkedListFree(LinkedList* list) {
    Node* curr = list->head;
    while (curr!= NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}

// Example usage
int main() {
    LinkedList* list = linkedListInit();
    linkedListAdd(list, 1);
    linkedListAdd(list, 2);
    linkedListAdd(list, 3);
    linkedListPrint(list);
    linkedListReverse(list);
    linkedListPrint(list);
    linkedListFree(list);
    return 0;
}