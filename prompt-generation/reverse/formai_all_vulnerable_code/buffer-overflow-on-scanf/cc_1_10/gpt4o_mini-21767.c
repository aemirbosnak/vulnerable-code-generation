//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char **words;
    int *counts;
    int size;
    int capacity;
} WordFrequencyCounter;

// Function prototypes
WordFrequencyCounter* create_counter();
void destroy_counter(WordFrequencyCounter *counter);
void add_word(WordFrequencyCounter *counter, const char *word);
void print_word_frequencies(const WordFrequencyCounter *counter);
void to_lowercase(char *str);

// Main function
int main() {
    WordFrequencyCounter *counter = create_counter();
    char word[MAX_WORD_LENGTH];

    printf("Enter text (Ctrl+D to end):\n");

    // Read words from standard input
    while (scanf("%s", word) != EOF) {
        to_lowercase(word);
        add_word(counter, word);
    }

    print_word_frequencies(counter);
    destroy_counter(counter);
    return 0;
}

// Function to create a WordFrequencyCounter
WordFrequencyCounter* create_counter() {
    WordFrequencyCounter *counter = malloc(sizeof(WordFrequencyCounter));
    counter->size = 0;
    counter->capacity = INITIAL_CAPACITY;
    counter->words = malloc(counter->capacity * sizeof(char *));
    counter->counts = malloc(counter->capacity * sizeof(int));
    return counter;
}

// Function to free memory used by WordFrequencyCounter
void destroy_counter(WordFrequencyCounter *counter) {
    for (int i = 0; i < counter->size; i++) {
        free(counter->words[i]);
    }
    free(counter->words);
    free(counter->counts);
    free(counter);
}

// Function to add a word to the frequency counter
void add_word(WordFrequencyCounter *counter, const char *word) {
    // Check if we need to increase the capacity
    if (counter->size >= counter->capacity) {
        counter->capacity *= 2;
        counter->words = realloc(counter->words, counter->capacity * sizeof(char *));
        counter->counts = realloc(counter->counts, counter->capacity * sizeof(int));
    }

    // Search for the word in the existing array
    for (int i = 0; i < counter->size; i++) {
        if (strcmp(counter->words[i], word) == 0) {
            counter->counts[i]++;
            return;
        }
    }

    // If not found, add the new word with a count of 1
    counter->words[counter->size] = strdup(word);
    counter->counts[counter->size] = 1;
    counter->size++;
}

// Function to print the word frequencies
void print_word_frequencies(const WordFrequencyCounter *counter) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < counter->size; i++) {
        printf("%s: %d\n", counter->words[i], counter->counts[i]);
    }
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}