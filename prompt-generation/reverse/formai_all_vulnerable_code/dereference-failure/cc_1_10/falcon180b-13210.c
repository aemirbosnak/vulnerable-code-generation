//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new empty list
List* create_list() {
    List* new_list = (List*)malloc(sizeof(List));
    if (new_list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node to the end of the list
void add_node(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to print the list
void print_list(List* list) {
    Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory used by the list
void free_list(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        Node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    free(list);
}

// Main function
int main() {
    List* list = create_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);
    add_node(list, 5);
    print_list(list);
    free_list(list);
    return 0;
}