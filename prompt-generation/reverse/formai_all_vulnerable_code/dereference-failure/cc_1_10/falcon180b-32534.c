//Falcon-180B DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    int freq;
    struct node* next;
} Node;

// Function to create a new node with given data and frequency
Node* createNode(char data[], int freq) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->freq = freq;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in the linked list
void insertNode(Node** head, char data[], int freq) {
    Node* newNode = createNode(data, freq);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse the list to find the correct position to insert the new node
    while (temp!= NULL && temp->freq > freq) {
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp;
    temp = *head;

    // If the new node has the highest frequency, set it as the new head
    if (temp->freq < newNode->freq) {
        newNode->next = temp;
        *head = newNode;
    }

    return;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->data, temp->freq);
        temp = temp->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Insert nodes into the list
    insertNode(&head, "apple", 5);
    insertNode(&head, "banana", 3);
    insertNode(&head, "orange", 7);
    insertNode(&head, "pear", 4);

    // Print the list
    printList(head);

    return 0;
}