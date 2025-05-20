//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for the linked list
typedef struct linkedlist {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append the given data to the end of the linked list
void append_data(LinkedList* list, int data) {
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

// Function to print the contents of the linked list
void print_list(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void free_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        Node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    list->head = NULL;
    list->size = 0;
}

// Function to create a new linked list
LinkedList* create_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

int main() {
    LinkedList* list = create_list();
    append_data(list, 10);
    append_data(list, 20);
    append_data(list, 30);
    print_list(list);
    free_list(list);
    return 0;
}