//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure
struct node {
    int data;
    struct node* next;
};

// Linked list structure
struct linked_list {
    struct node* head;
};

// Create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Append a node to the end of the list
void append_node(struct linked_list* list, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = list->head;
    if (temp == NULL) {
        list->head = new_node;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Search for a value in the list
int search_value(struct linked_list* list, int value) {
    struct node* temp = list->head;
    while (temp!= NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Print the list
void print_list(struct linked_list* list) {
    struct node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new linked list
    struct linked_list list;
    list.head = NULL;

    // Append some nodes to the list
    append_node(&list, 10);
    append_node(&list, 20);
    append_node(&list, 30);
    append_node(&list, 40);

    // Print the list
    printf("Initial list:\n");
    print_list(&list);

    // Search for a value in the list
    int value = 30;
    int result = search_value(&list, value);
    if (result == 1) {
        printf("Value %d found in the list\n", value);
    }
    else {
        printf("Value %d not found in the list\n", value);
    }

    // Free memory
    struct node* temp = list.head;
    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}