//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Linked List structure definition
typedef struct linked_list {
    Node* head;
} LinkedList;

// Function to create a new node with given data
Node* create_node(char* data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(LinkedList* list, char* data) {
    Node* new_node = create_node(data);
    Node* temp = list->head;
    if (temp == NULL) {
        list->head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to search for a node with given data in the list
Node* search_node(LinkedList* list, char* data) {
    Node* temp = list->head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void print_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    list.head = NULL;

    // Add nodes to the list
    add_node(&list, "apple");
    add_node(&list, "banana");
    add_node(&list, "cherry");
    add_node(&list, "date");

    // Print the list
    print_list(&list);

    // Search for a node
    Node* found_node = search_node(&list, "cherry");
    if (found_node!= NULL) {
        printf("Found node with data: %s\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}