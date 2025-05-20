//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new linked list
List* create_list() {
    List* new_list = (List*) malloc(sizeof(List));
    if (new_list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Add a node to the end of the linked list
void add_node(List* list, int data) {
    Node* new_node = create_node(data);
    Node* current = list->head;
    if (current == NULL) {
        list->head = new_node;
    } else {
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// Remove a node with the given data from the linked list
void remove_node(List* list, int data) {
    Node* current = list->head;
    Node* previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    list->size--;
}

// Print the contents of the linked list
void print_list(List* list) {
    printf("List contents:\n");
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* my_list = create_list();
    add_node(my_list, 1);
    add_node(my_list, 2);
    add_node(my_list, 3);
    print_list(my_list);
    remove_node(my_list, 2);
    print_list(my_list);
    return 0;
}