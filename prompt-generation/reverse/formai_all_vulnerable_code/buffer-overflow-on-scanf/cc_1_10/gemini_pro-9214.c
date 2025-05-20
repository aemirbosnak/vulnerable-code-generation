//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of a word
#define MAX_WORD_SIZE 50

// Define the maximum number of words to count
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct word {
    char *word;
    int count;
} word;

// Define the structure of a word list
typedef struct word_list {
    word *words;
    int size;
} word_list;

// Create a new word list
word_list *new_word_list() {
    word_list *wl = malloc(sizeof(word_list));
    wl->words = malloc(sizeof(word) * MAX_WORDS);
    wl->size = 0;
    return wl;
}

// Add a word to a word list
void add_word(word_list *wl, char *word) {
    // Check if the word is already in the list
    for (int i = 0; i < wl->size; i++) {
        if (strcmp(wl->words[i].word, word) == 0) {
            wl->words[i].count++;
            return;
        }
    }

    // If the word is not in the list, add it
    if (wl->size == MAX_WORDS) {
        printf("Error: Word list is full. Cannot add word '%s'.\n", word);
        return;
    }

    wl->words[wl->size].word = strdup(word);
    wl->words[wl->size].count = 1;
    wl->size++;
}

// Print a word list
void print_word_list(word_list *wl) {
    for (int i = 0; i < wl->size; i++) {
        printf("%s: %d\n", wl->words[i].word, wl->words[i].count);
    }
}

// Free a word list
void free_word_list(word_list *wl) {
    for (int i = 0; i < wl->size; i++) {
        free(wl->words[i].word);
    }
    free(wl->words);
    free(wl);
}

// Count the words in a string
word_list *count_words(char *str) {
    // Create a new word list
    word_list *wl = new_word_list();

    // Tokenize the string
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Convert the token to lowercase
        char *lowercase_token = malloc(strlen(token) + 1);
        for (int i = 0; i < strlen(token); i++) {
            lowercase_token[i] = tolower(token[i]);
        }
        lowercase_token[strlen(token)] = '\0';

        // Add the token to the word list
        add_word(wl, lowercase_token);

        // Free the lowercase token
        free(lowercase_token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the word list
    return wl;
}

// Get the input text from the user
char *get_input_text() {
    // Get the length of the input text
    int length = 0;
    printf("Enter the text to count the words in: ");
    scanf("%d", &length);

    // Allocate memory for the input text
    char *text = malloc(length + 1);

    // Get the input text
    scanf("%s", text);

    // Return the input text
    return text;
}

// Main function
int main() {
    // Get the input text from the user
    char *text = get_input_text();

    // Count the words in the input text
    word_list *wl = count_words(text);

    // Print the word list
    print_word_list(wl);

    // Free the word list
    free_word_list(wl);

    // Free the input text
    free(text);

    return 0;
}