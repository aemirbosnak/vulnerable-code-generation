//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Define a Node structure for the hash table
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

// Hash table structure
Node *dictionary[DICTIONARY_SIZE];

// Simple hash function
unsigned int hash(const char *word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash << 5) + *word++;
    }
    return hash % DICTIONARY_SIZE;
}

// Function to insert a word into the hash table
void insert_word(const char *word) {
    unsigned int index = hash(word);
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = dictionary[index];
    dictionary[index] = new_node;
}

// Function to check if a word is in the hash table
int check_word(const char *word) {
    unsigned int index = hash(word);
    Node *current = dictionary[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to read the dictionary from a file
void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(word);
    }

    fclose(file);
}

// Function to clean and normalize words
void normalize_word(char *word) {
    char *ptr = word;
    while (*ptr) {
        *ptr = tolower(*ptr); // Convert to lowercase
        ptr++;
    }
    // Remove punctuation from the end
    if (ptr > word && ispunct(*(ptr - 1))) {
        *(ptr - 1) = '\0';
    }
}

// Main spell checker function
void check_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        normalize_word(word); // Clean the word
        if (!check_word(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);
}

// Main program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the dictionary
    load_dictionary(argv[1]);

    // Check the text for spelling
    check_text(argv[2]);

    return EXIT_SUCCESS;
}