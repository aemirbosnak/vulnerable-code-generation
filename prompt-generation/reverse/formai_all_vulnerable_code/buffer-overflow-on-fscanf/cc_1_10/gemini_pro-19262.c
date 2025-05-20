//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Define the maximum number of words in a file
#define MAX_WORDS 10000

// Define a linked list node to store a word and its count
typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    int count;
    struct node *next;
} node_t;

// Function to create a new linked list node
node_t *create_node(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Function to add a word to the linked list
void add_word(node_t **head, char *word) {
    node_t *new_node = create_node(word);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to count the number of words in a file
int count_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    int count = 0;
    while (fscanf(fp, "%s", word) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

// Function to read a file and create a linked list of words
node_t *read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    node_t *head = NULL;
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert the word to lowercase and remove punctuation
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
            if (ispunct(word[i])) {
                word[i] = '\0';
            }
        }

        // Add the word to the linked list
        add_word(&head, word);
    }

    fclose(fp);
    return head;
}

// Function to print the linked list of words
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Function to free the linked list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    // Count the number of words in the file
    int word_count = count_words(filename);
    printf("Word count: %d\n", word_count);

    // Read the file and create a linked list of words
    node_t *head = read_file(filename);

    // Print the linked list of words
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}