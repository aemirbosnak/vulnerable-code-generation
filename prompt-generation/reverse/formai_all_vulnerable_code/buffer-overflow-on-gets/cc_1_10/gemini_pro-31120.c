//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the linked list node structure
typedef struct node {
    char* word;
    int count;
    struct node* next;
} node_t;

// Create a new node
node_t* create_node(char* word) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list
void insert_node(node_t** head, node_t* new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

// Search for a node in the linked list
node_t* search_node(node_t* head, char* word) {
    node_t* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Count the number of words in a string
int count_words(char* string) {
    int count = 0;
    char* word = strtok(string, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Print the linked list
void print_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the linked list
void free_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Get the input string
    char* string = (char*)malloc(1000);
    printf("Enter a string: ");
    gets(string);

    // Create a linked list to store the words in the string
    node_t* head = NULL;

    // Split the string into words and count the number of occurrences of each word
    char* word = strtok(string, " ");
    while (word != NULL) {
        node_t* node = search_node(head, word);
        if (node == NULL) {
            node = create_node(word);
            insert_node(&head, node);
        } else {
            node->count++;
        }
        word = strtok(NULL, " ");
    }

    // Print the linked list
    printf("\nWord Count:\n");
    print_list(head);

    // Free the linked list
    free_list(head);

    // Free the input string
    free(string);

    return 0;
}