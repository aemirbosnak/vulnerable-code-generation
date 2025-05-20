//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Function prototypes
List* create_list();
void destroy_list(List* list);
void add_node(List* list, int data);
void remove_node(List* list, int data);
void print_list(List* list);

int main() {
    List* list = create_list();

    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);
    add_node(list, 5);

    print_list(list);

    remove_node(list, 3);

    print_list(list);

    destroy_list(list);

    return 0;
}

// Function to create an empty linked list
List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Function to destroy a linked list
void destroy_list(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Function to add a node to the end of the list
void add_node(List* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

// Function to remove a node with the given data from the list
void remove_node(List* list, int data) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == list->tail) {
        list->tail = previous;
    }

    free(current);
    list->size--;
}

// Function to print the list
void print_list(List* list) {
    Node* current = list->head;
    printf("List: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}