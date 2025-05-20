//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: protected
// Linked list operations example program in a protected style

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Define a list structure
typedef struct list {
    node* head;
    node* tail;
} list;

// Initialize an empty list
list* init_list() {
    list* new_list = malloc(sizeof(list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Insert a new node at the beginning of the list
void insert_head(list* list, int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// Insert a new node at the end of the list
void insert_tail(list* list, int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

// Delete the first node in the list
void delete_head(list* list) {
    node* temp = list->head;
    list->head = temp->next;
    free(temp);
}

// Delete the last node in the list
void delete_tail(list* list) {
    node* temp = list->tail;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        node* curr = list->head;
        while (curr->next != temp) {
            curr = curr->next;
        }
        curr->next = NULL;
        list->tail = curr;
    }
    free(temp);
}

// Search for a node with a given value
node* search(list* list, int data) {
    node* curr = list->head;
    while (curr != NULL) {
        if (curr->data == data) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// Print the list
void print_list(list* list) {
    node* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Create a new list
    list* my_list = init_list();

    // Insert nodes at the beginning and end of the list
    insert_head(my_list, 1);
    insert_tail(my_list, 2);
    insert_head(my_list, 3);
    insert_tail(my_list, 4);
    insert_head(my_list, 5);

    // Delete the first and last node
    delete_head(my_list);
    delete_tail(my_list);

    // Search for a node with value 3
    node* found = search(my_list, 3);
    if (found != NULL) {
        printf("Found node with value %d\n", found->data);
    } else {
        printf("Node with value 3 not found\n");
    }

    // Print the list
    print_list(my_list);

    return 0;
}