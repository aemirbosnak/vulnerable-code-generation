//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *head = NULL;

// Function to create a new node
Node *create_node(char data[]) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_node(char data[]) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the list
void delete_node(char data[]) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search for a node in the list
Node *search_node(char data[]) {
    Node *temp = head;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    return temp;
}

// Function to print the list
void print_list() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_node("hello");
    insert_node("world");
    insert_node("foo");
    insert_node("bar");
    print_list();

    delete_node("world");
    print_list();

    Node *node = search_node("foo");
    if (node!= NULL) {
        printf("Found node: %s\n", node->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}