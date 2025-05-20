//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list.
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Initialize the linked list.
node_t *head = NULL;

// Insert a new node into the linked list.
void insert(char *word) {
    // Create a new node.
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    // Copy the word into the new node.
    new_node->word = strdup(word);

    // Initialize the count to 1.
    new_node->count = 1;

    // Set the next pointer to NULL.
    new_node->next = NULL;

    // If the linked list is empty, set the head pointer to the new node.
    if (head == NULL) {
        head = new_node;
    } else {
        // Otherwise, add the new node to the end of the linked list.
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Print the linked list.
void print() {
    // Print the header.
    printf("Word\tCount\n");

    // Print each node in the linked list.
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%s\t%d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

// Free the linked list.
void free_list() {
    // Free each node in the linked list.
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    // Set the head pointer to NULL.
    head = NULL;
}

// Main function.
int main() {
    // Get the input text from the user.
    char text[1000];
    printf("Please enter some text: ");
    gets(text);

    // Tokenize the text into words.
    char *words[1000];
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Count the frequency of each word.
    for (int i = 0; i < num_words; i++) {
        insert(words[i]);
    }

    // Print the word frequency table.
    print();

    // Free the linked list.
    free_list();

    return 0;
}