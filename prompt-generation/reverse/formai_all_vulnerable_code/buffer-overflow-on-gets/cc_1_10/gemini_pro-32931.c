//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to count
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the node of a linked list
typedef struct node {
    char word[MAX_WORD_LENGTH + 1];  // The word
    int count;                        // The count of the word
    struct node *next;                // The next node
} node_t;

// Define the linked list
typedef struct {
    node_t *head;  // The head of the linked list
    node_t *tail;  // The tail of the linked list
    int size;       // The size of the linked list
} linked_list_t;

// Create a new linked list
linked_list_t *linked_list_new() {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Free a linked list
void linked_list_free(linked_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Insert a word into a linked list
int linked_list_insert(linked_list_t *list, char *word) {
    // Create a new node
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return -1;
    }
    strcpy(node->word, word);
    node->count = 1;
    node->next = NULL;

    // Insert the new node into the linked list
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;

    return 0;
}

// Get the count of a word in a linked list
int linked_list_get_count(linked_list_t *list, char *word) {
    node_t *current = list->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

// Increment the count of a word in a linked list
int linked_list_increment_count(linked_list_t *list, char *word) {
    node_t *current = list->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

// Print the words and counts in a linked list
void linked_list_print(linked_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Main function
int main() {
    // Create a linked list to store the words and counts
    linked_list_t *list = linked_list_new();
    if (list == NULL) {
        return -1;
    }

    // Read the input text
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Tokenize the input text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Convert the token to lowercase
        char *lower_token = strdup(token);
        for (int i = 0; i < strlen(lower_token); i++) {
            lower_token[i] = tolower(lower_token[i]);
        }

        // Insert the token into the linked list
        int count = linked_list_get_count(list, lower_token);
        if (count == 0) {
            linked_list_insert(list, lower_token);
        } else {
            linked_list_increment_count(list, lower_token);
        }

        // Free the token
        free(lower_token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the words and counts
    linked_list_print(list);

    // Free the linked list
    linked_list_free(list);

    return 0;
}