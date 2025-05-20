//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
};

// Function to create a new node
struct node* createNode(char* data, int size) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a string in a linked list
int search(struct node* head, char* searchString) {
    struct node* currNode = head;
    while (currNode!= NULL) {
        if (strstr(currNode->data, searchString)!= NULL) {
            printf("String found in node with data: %s\n", currNode->data);
            return TRUE;
        }
        currNode = currNode->next;
    }
    printf("String not found in any node.\n");
    return FALSE;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* currNode = head;
    while (currNode!= NULL) {
        printf("Data: %s\tSize: %d\n", currNode->data, currNode->size);
        currNode = currNode->next;
    }
}

// Main function
int main() {
    // Create a linked list with 3 nodes
    struct node* head = NULL;
    head = createNode("Hello, World!", 13);
    head->next = createNode("This is a test.", 16);
    head->next->next = createNode("The quick brown fox jumps over the lazy dog.", 32);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Search for a string in the linked list
    char searchString[] = "test";
    search(head, searchString);

    // Search for a string not in the linked list
    char searchString2[] = "not found";
    search(head, searchString2);

    return 0;
}