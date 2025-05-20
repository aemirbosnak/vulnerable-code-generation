//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(char data[]) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to search for a string in a linked list
struct node* search(struct node* head, char searchString[]) {
    // Traverse the linked list until the end or until the string is found
    while (head!= NULL) {
        if (strcmp(head->data, searchString) == 0) {
            return head;
        }
        head = head->next;
    }
    // String not found
    return NULL;
}

// Function to print a linked list
void printList(struct node* head) {
    while (head!= NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a linked list with 5 nodes
    struct node* head = NULL;
    head = newNode("apple");
    head->next = newNode("banana");
    head->next->next = newNode("cherry");
    head->next->next->next = newNode("date");
    head->next->next->next->next = newNode("elderberry");

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Search for a string in the linked list
    char searchString[] = "banana";
    struct node* result = search(head, searchString);

    // Print the search result
    if (result!= NULL) {
        printf("'%s' found at position %d\n", result->data, 1);
    } else {
        printf("'%s' not found\n", searchString);
    }

    return 0;
}