//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: retro
/*
 * A retro-style linked list example program
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent the linked list
struct LinkedList {
    struct Node *head;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node in the linked list
void insertNode(struct LinkedList *list, int data) {
    struct Node *node = newNode(data);
    node->next = list->head;
    list->head = node;
}

// Function to print the linked list
void printList(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to delete a node from the linked list
void deleteNode(struct LinkedList *list, int data) {
    struct Node *node = list->head;
    struct Node *prev = NULL;
    while (node != NULL && node->data != data) {
        prev = node;
        node = node->next;
    }
    if (node == NULL) {
        return;
    }
    if (prev == NULL) {
        list->head = node->next;
    } else {
        prev->next = node->next;
    }
    free(node);
}

int main() {
    struct LinkedList list = {NULL};
    insertNode(&list, 10);
    insertNode(&list, 20);
    insertNode(&list, 30);
    insertNode(&list, 40);
    insertNode(&list, 50);
    printList(&list);
    deleteNode(&list, 30);
    printList(&list);
    return 0;
}