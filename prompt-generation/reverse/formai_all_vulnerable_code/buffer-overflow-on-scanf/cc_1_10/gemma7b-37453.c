//Gemma-7B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct node {
    char name[MAX_BUFFER_SIZE];
    struct node* next;
} node;

int main() {
    node* head = NULL;
    char input[MAX_BUFFER_SIZE];

    printf("Welcome to the C System Administration Simulator!\n");
    printf("Please enter the command: ");

    // Get the user input
    scanf("%s", input);

    // Create a new node if the command is "add"
    if (strcmp(input, "add") == 0) {
        node* newNode = (node*)malloc(sizeof(node));

        printf("Enter the node name: ");
        scanf("%s", newNode->name);

        newNode->next = head;
        head = newNode;
    }

    // Print the list of nodes if the command is "list"
    else if (strcmp(input, "list") == 0) {
        node* current = head;

        printf("List of nodes:\n");
        while (current) {
            printf("%s\n", current->name);
            current = current->next;
        }
    }

    // Delete a node if the command is "delete"
    else if (strcmp(input, "delete") == 0) {
        node* current = head;
        node* previous = NULL;

        printf("Enter the node name to delete: ");
        scanf("%s", input);

        // Search for the node to delete
        while (current) {
            if (strcmp(current->name, input) == 0) {
                break;
            }
            previous = current;
            current = current->next;
        }

        // If the node was found, delete it
        if (previous) {
            previous->next = current->next;
            free(current);
        } else {
            printf("Node not found.\n");
        }
    }

    // Exit the program
    else if (strcmp(input, "exit") == 0) {
        printf("Goodbye.\n");
        exit(0);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}