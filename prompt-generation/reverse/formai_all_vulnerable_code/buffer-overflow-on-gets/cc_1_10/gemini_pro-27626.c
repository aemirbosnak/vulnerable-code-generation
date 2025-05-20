//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a node for the linked list
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *next;
} node;

// Create a linked list to store the words and their counts
node *head = NULL;

// Function to add a word to the linked list
void add_word(char *word) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));

    // Copy the word into the new node
    strcpy(new_node->word, word);

    // Initialize the count to 1
    new_node->count = 1;

    // Add the new node to the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to find a word in the linked list
node *find_word(char *word) {
    // Start at the beginning of the linked list
    node *current = head;

    // Loop through the linked list until we find the word
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // We found the word
            return current;
        }

        // Move to the next node
        current = current->next;
    }

    // We did not find the word
    return NULL;
}

// Function to increment the count of a word in the linked list
void increment_count(node *word) {
    // Increment the count of the word
    word->count++;
}

// Function to print the linked list
void print_list() {
    // Start at the beginning of the linked list
    node *current = head;

    // Loop through the linked list until we reach the end
    while (current != NULL) {
        // Print the word and its count
        printf("%s: %d\n", current->word, current->count);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Get the input text from the user
    char input[1000];
    printf("Enter the text to analyze: ");
    gets(input);

    // Tokenize the input text into words
    char *token = strtok(input, " ");

    // Loop through the words in the input text
    while (token != NULL) {
        // Find the word in the linked list
        node *word = find_word(token);

        // If the word is not in the linked list, add it
        if (word == NULL) {
            add_word(token);
        } else {
            // Increment the count of the word
            increment_count(word);
        }

        // Get the next word from the input text
        token = strtok(NULL, " ");
    }

    // Print the linked list
    print_list();

    return 0;
}