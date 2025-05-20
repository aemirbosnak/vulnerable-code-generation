//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
// Unique C Searching Algorithm Example Program

#include <stdio.h>

// Define a struct to represent a node in the list
struct node {
    int data;
    struct node* next;
};

// Define a struct to represent the list
struct list {
    struct node* head;
    struct node* tail;
};

// Function to initialize the list
void init_list(struct list* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to insert a node into the list
void insert_node(struct list* list, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Function to search for a node in the list
int search_node(struct list* list, int data) {
    struct node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current->data;
        }
        current = current->next;
    }
    return -1;
}

// Driver code
int main() {
    struct list list;
    init_list(&list);
    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    insert_node(&list, 5);

    int search_data = 3;
    int search_result = search_node(&list, search_data);
    if (search_result != -1) {
        printf("Found node with data %d\n", search_result);
    } else {
        printf("Node not found\n");
    }

    return 0;
}