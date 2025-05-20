//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    char buffer[MAX_BUFFER_SIZE];
    Node* head = NULL;
    int i = 0;

    printf("Enter C Syntax: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the input string
    for (i = 0; buffer[i] != '\0'; i++) {
        // Identify keywords and operators
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            // Insert a node for keywords
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        } else if (buffer[i] >= '0' && buffer[i] <= '9') {
            // Insert a node for numbers
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        } else if (buffer[i] == '+') {
            // Insert a node for addition operator
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        } else if (buffer[i] == '-') {
            // Insert a node for subtraction operator
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        } else if (buffer[i] == '*') {
            // Insert a node for multiplication operator
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        } else if (buffer[i] == '/') {
            // Insert a node for division operator
            Node* newNode = malloc(sizeof(Node));
            newNode->data = buffer[i];
            newNode->next = head;
            head = newNode;
        }
    }

    // Print the parsed nodes
    Node* current = head;
    printf("Parsed nodes:\n");
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}