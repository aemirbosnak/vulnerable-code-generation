//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom linked list node structure to store word and its count
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Function to create a new node and initialize its fields
node_t *create_node(char *word) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Error allocating memory for new node");
        return NULL;
    }

    new_node->word = strdup(word);
    if (new_node->word == NULL) {
        perror("Error allocating memory for word");
        free(new_node);
        return NULL;
    }

    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a word into the linked list in sorted order (lexicographically)
void insert_word(node_t **head, char *word) {
    node_t *new_node = create_node(word);
    if (new_node == NULL) {
        return;
    }

    // If the list is empty or the new word should be inserted at the beginning
    if (*head == NULL || strcmp(new_node->word, (*head)->word) < 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list and find the correct insertion point
    node_t *current = *head;
    while (current->next != NULL && strcmp(new_node->word, current->next->word) > 0) {
        current = current->next;
    }

    // Insert the new node after the current node
    new_node->next = current->next;
    current->next = new_node;
}

// Function to free the memory allocated for a linked list
void free_list(node_t *head) {
    while (head != NULL) {
        node_t *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

// Function to count the words in a text file and store them in a linked list
node_t *count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    node_t *head = NULL;
    char word[1024];

    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        int i = 0;
        while (word[i] != '\0') {
            word[i] = tolower(word[i]);
            if (!isalnum(word[i])) {
                word[i] = '\0';
            }
            i++;
        }

        // Skip empty strings and strings with non-alphanumeric characters
        if (strlen(word) == 0) {
            continue;
        }

        // Insert the word into the linked list
        insert_word(&head, word);
    }

    fclose(file);
    return head;
}

// Function to print the word count linked list
void print_word_count(node_t *head) {
    int total_words = 0;
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->count);
        total_words += head->count;
        head = head->next;
    }

    printf("\nTotal words: %d\n", total_words);
}

// Main function to read input from the user and process the word count
int main() {
    char filename[1024];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    node_t *head = count_words(filename);
    if (head == NULL) {
        fprintf(stderr, "Error counting words\n");
        return EXIT_FAILURE;
    }

    print_word_count(head);
    free_list(head);

    return EXIT_SUCCESS;
}