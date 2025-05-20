//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Define structure for a node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to add a node at the beginning */
void push(struct Node** start_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *start_ref;
    *start_ref = new_node;
    printf("%d added to the list\n", new_data);
}

/* Function to add a node at the end */
void append(struct Node** start_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *start_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*start_ref == NULL) {
        new_node->next = NULL;
        *start_ref = new_node;
        printf("%d added to the list\n", new_data);
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("%d added to the list\n", new_data);
}

/* Function to add a node after a given position */
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("%d added to the list\n", new_data);
}

/* Function to delete a node with a given data */
void delete_node(struct Node** start_ref, int key) {
    struct Node* temp = *start_ref, *prev;
    if (temp!= NULL && temp->data == key) {
        *start_ref = temp->next;
        free(temp);
        printf("%d deleted from the list\n", key);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list\n", key);
}

/* Function to search for a node with a given data */
struct Node* search_node(struct Node* start, int key) {
    struct Node* current = start;
    while (current!= NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Function to print the list */
void print_list(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* start = NULL;
    push(&start, 10);
    push(&start, 20);
    push(&start, 30);
    append(&start, 40);
    insert_after(search_node(start, 20), 25);
    delete_node(&start, 10);
    delete_node(&start, 30);
    print_list(start);
    return 0;
}