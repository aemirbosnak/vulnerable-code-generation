//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    char input[MAX_SIZE];

    // Dynamically allocate memory for the first node
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    // Insert the first node
    printf("Enter a name: ");
    scanf("%s", head->name);

    // Create a loop to insert more nodes
    while (1) {
        printf("Enter another name (optional): ");
        scanf("%s", input);

        // If the input is not empty, insert a new node
        if (input[0] != '\0') {
            // Allocate memory for the new node
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->next = NULL;

            // Copy the name of the new node from the input
            strcpy(newNode->name, input);

            // Insert the new node after the last node
            head->next = newNode;
            head = newNode;
        }

        // Break out of the loop if the user enters an empty input
        else {
            break;
        }
    }

    // Print the names of all the nodes
    printf("The names of the nodes are: ");
    Node* current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }

    return 0;
}