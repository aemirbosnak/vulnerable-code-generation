//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

struct node* create_node(char* data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to print linked list
void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to search for a string in linked list
struct node* search_list(struct node* head, char* search_str) {
    while (head!= NULL) {
        if (strcmp(head->data, search_str) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to free memory allocated by linked list
void free_list(struct node* head) {
    while (head!= NULL) {
        free(head->data);
        free(head);
        head = head->next;
    }
}

int main() {
    // Create linked list
    struct node* head = NULL;
    head = create_node("apple");
    head->next = create_node("banana");
    head->next->next = create_node("cherry");
    head->next->next->next = create_node("date");

    // Print linked list
    printf("Original List:\n");
    print_list(head);

    // Search for a string in linked list
    struct node* found_node = search_list(head, "cherry");
    if (found_node!= NULL) {
        printf("Found '%s'\n", found_node->data);
    } else {
        printf("Not found\n");
    }

    // Free memory allocated by linked list
    free_list(head);

    return 0;
}