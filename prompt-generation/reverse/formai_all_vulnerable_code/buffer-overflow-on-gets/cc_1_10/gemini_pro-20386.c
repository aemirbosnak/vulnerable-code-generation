//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node in a linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Create a new node
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a node into a linked list
void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Find a node in a linked list
node *find_node(node *head, char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Count the number of words in a string
int count_words(char *string) {
    int count = 0;
    char *token = strtok(string, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Count the frequency of words in a string
void count_word_frequency(char *string, node **head) {
    char *token = strtok(string, " ");
    while (token != NULL) {
        node *node = find_node(*head, token);
        if (node == NULL) {
            node = create_node(token);
            insert_node(head, node);
        } else {
            node->count++;
        }
        token = strtok(NULL, " ");
    }
}

// Print the frequency of words in a linked list
void print_word_frequency(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the memory allocated for a linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Create a linked list to store the word frequencies
    node *head = NULL;

    // Count the frequency of words in the string
    count_word_frequency(string, &head);

    // Print the frequency of words in the linked list
    print_word_frequency(head);

    // Free the memory allocated for the linked list
    free_list(head);

    return 0;
}