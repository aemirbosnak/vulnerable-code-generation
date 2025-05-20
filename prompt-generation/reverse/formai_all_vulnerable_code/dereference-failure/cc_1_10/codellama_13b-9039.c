//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: retro
/*
 * Retro Search Algorithm in C
 *
 * A unique C Searching algorithm example program
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to store the data
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct node *insertNodeAtBeginning(struct node *head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct node *insertNodeAtEnd(struct node *head, int data) {
    struct node *newNode = createNode(data);
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to search a node in the list
int searchNode(struct node *head, int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to print the list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a list of numbers
    struct node *head = NULL;
    head = insertNodeAtBeginning(head, 1);
    head = insertNodeAtBeginning(head, 2);
    head = insertNodeAtBeginning(head, 3);
    head = insertNodeAtEnd(head, 4);
    head = insertNodeAtEnd(head, 5);
    head = insertNodeAtEnd(head, 6);

    // Print the list
    printList(head);

    // Search for a node
    int data = 3;
    int found = searchNode(head, data);
    if (found == 1) {
        printf("Node found with data %d\n", data);
    } else {
        printf("Node not found with data %d\n", data);
    }

    // Free the list
    struct node *temp = head;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}