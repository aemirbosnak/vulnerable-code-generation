//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: futuristic
// Linked List Operations Example Program

#include <stdio.h>
#include <stdlib.h>

// Linked List Node Structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Linked List Structure
typedef struct {
    Node *head;
    Node *tail;
} List;

// Function to create a new node
Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new linked list
List *create_list() {
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to add a node to the beginning of the list
void add_front(List *list, int data) {
    Node *node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
}

// Function to add a node to the end of the list
void add_back(List *list, int data) {
    Node *node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Function to remove a node from the list
void remove_node(List *list, int data) {
    Node *curr = list->head;
    Node *prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return;
    }
    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

// Function to traverse the list
void traverse(List *list) {
    Node *curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    List *list = create_list();
    add_front(list, 1);
    add_front(list, 2);
    add_back(list, 3);
    add_back(list, 4);
    remove_node(list, 2);
    traverse(list);
    return 0;
}