//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: accurate
/*
 * Linked List Operations Example Program
 *
 * Created by [Your Name]
 *
 * Demonstrates how to perform basic operations on a linked list in C
 *
 * Compile with: gcc -o linked_list_operations linked_list_operations.c
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list nodes
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the linked list
struct LinkedList {
    struct Node* head;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* node = createNode(data);
    node->next = list->head;
    list->head = node;
}

// Insert a node at the end of the linked list
void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* node = createNode(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Delete the node at the beginning of the linked list
void deleteAtBeginning(struct LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    struct Node* node = list->head;
    list->head = list->head->next;
    free(node);
}

// Delete the node at the end of the linked list
void deleteAtEnd(struct LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }
    struct Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Search for a node with the given data in the linked list
struct Node* search(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print the linked list
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList list;
    list.head = NULL;

    insertAtBeginning(&list, 1);
    insertAtBeginning(&list, 2);
    insertAtEnd(&list, 3);
    insertAtEnd(&list, 4);

    printList(&list);

    deleteAtBeginning(&list);
    printList(&list);

    deleteAtEnd(&list);
    printList(&list);

    struct Node* node = search(&list, 3);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node with data 3 not found\n");
    }

    return 0;
}