//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("%d added to the list.\n", new_data);
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        (*head_ref) = new_node;
        printf("%d added to the list.\n", new_data);
        return;
    }

    struct Node* last = *head_ref;
    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    printf("%d added to the list.\n", new_data);
}

// Function to add a node after a given position
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    printf("%d added to the list after %d.\n", new_data, prev_node->data);
}

// Function to delete a node by key
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node by key
struct Node* search_node(struct Node* head, int key) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void print_list(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    append(&head, 50);
    insert_after(search_node(head, 20), 25);
    print_list(head);
    delete_node(&head, 30);
    print_list(head);
    return 0;
}