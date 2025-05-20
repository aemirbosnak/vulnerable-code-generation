//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 50
#define MAX_SUBJECT_SIZE 100
#define MAX_MESSAGE_SIZE 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_SIZE];
    char email[MAX_NAME_SIZE];
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, char* name, char* email);
void printList(Node* node);
void sendMessage(Node* node, char* subject, char* message);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "John", "john@example.com");
    addNode(&head, "Jane", "jane@example.com");

    // Print the list
    printf("Mailing List:\n");
    printList(head);

    // Send a message to everyone on the list
    char subject[MAX_SUBJECT_SIZE] = "A Love Letter";
    char message[MAX_MESSAGE_SIZE] = "My dearest love, I cannot express in words how much you mean to me. You are the sun that brightens my day and the moon that guides me through the night. With every beat of my heart, I feel closer to you. Thank you for being a part of my life.\n\nWith love,\nJohn";
    sendMessage(head, subject, message);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%s (%s)\n", node->name, node->email);
        node = node->next;
    }
}

// Function to send a message to everyone on the list
void sendMessage(Node* node, char* subject, char* message) {
    while (node!= NULL) {
        printf("Sending message to %s (%s)\n", node->name, node->email);
        // Code to send email goes here
        node = node->next;
    }
}