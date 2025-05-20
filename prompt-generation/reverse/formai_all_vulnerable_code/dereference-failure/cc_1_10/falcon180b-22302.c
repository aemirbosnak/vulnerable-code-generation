//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for a linked list
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Function to initialize a linked list
void init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Function to add a node to the end of the linked list
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

// Function to remove a node from the linked list
void remove_node(List* list, int data) {
    Node* current_node = list->head;
    Node* prev_node = NULL;

    while (current_node!= NULL && current_node->data!= data) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prev_node == NULL) {
        list->head = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }

    if (current_node == list->tail) {
        list->tail = prev_node;
    }

    free(current_node);
    list->size--;
}

// Function to print the linked list
void print_list(List* list) {
    Node* current_node = list->head;

    printf("Linked List:\n");
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse_list(List* list) {
    Node* current_node = list->head;
    Node* prev_node = NULL;
    Node* next_node = NULL;

    while (current_node!= NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    list->head = prev_node;
}

int main() {
    List my_list;
    init_list(&my_list);

    add_node(&my_list, 1);
    add_node(&my_list, 2);
    add_node(&my_list, 3);
    add_node(&my_list, 4);
    add_node(&my_list, 5);

    printf("Original List:\n");
    print_list(&my_list);

    remove_node(&my_list, 3);

    printf("List after removing node with data 3:\n");
    print_list(&my_list);

    reverse_list(&my_list);

    printf("List after reversing:\n");
    print_list(&my_list);

    return 0;
}