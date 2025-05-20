//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Node {
    char* word;
    struct _Node* next;
} Node;

int main() {
    // Create a linked list to store the words
    Node* head = NULL;
    Node* tail = NULL;

    // Get the input text from the user
    char* input = malloc(1024);
    printf("Enter your text:\n");
    scanf(" %[^\n]", input);

    // Tokenize the input text into words
    char* token = strtok(input, " ");
    while (token != NULL) {
        // Create a new node for the word
        Node* node = malloc(sizeof(Node));
        node->word = strdup(token);
        node->next = NULL;

        // Add the node to the linked list
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the words in the linked list
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Free the memory allocated for the linked list
    current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    // Free the memory allocated for the input text
    free(input);

    return 0;
}