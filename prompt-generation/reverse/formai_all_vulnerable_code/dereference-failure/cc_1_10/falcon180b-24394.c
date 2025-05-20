//Falcon-180B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    Node *head = NULL;

    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file line by line and add to linked list
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Allocate memory for new node
        Node *new_node = (Node*) malloc(sizeof(Node));
        if (new_node == NULL) {
            printf("Error: Could not allocate memory.\n");
            return 1;
        }

        // Copy line to node data
        new_node->data = strdup(line);

        // Add node to linked list
        new_node->next = head;
        head = new_node;
    }

    // Close file
    fclose(file);

    // Print linked list
    Node *curr_node = head;
    while (curr_node!= NULL) {
        printf("%s\n", curr_node->data);
        curr_node = curr_node->next;
    }

    // Free memory
    curr_node = head;
    while (curr_node!= NULL) {
        free(curr_node->data);
        free(curr_node);
        curr_node = curr_node->next;
    }

    return 0;
}