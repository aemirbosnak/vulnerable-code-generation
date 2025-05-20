//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// A structure to hold a word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void to_lowercase(char *str);
int search_word(WordCount *words, int num_words, const char *word);
void add_word(WordCount *words, int *num_words, const char *word);
void print_word_counts(WordCount *words, int num_words);

int main() {
    WordCount words[MAX_WORDS];
    int num_words = 0;
    char buffer[MAX_WORD_LENGTH];

    printf("Welcome to the Word Frequency Counter!\n");
    printf("Please enter your text (end with Ctrl+D):\n");

    // Read words from standard input
    while (scanf("%s", buffer) != EOF) {
        to_lowercase(buffer); // Convert the word to lowercase
        add_word(words, &num_words, buffer); // Add it to the list or update its count
    }

    // Print the counts of each word
    print_word_counts(words, num_words);

    return 0;
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to search for a word in the word array
int search_word(WordCount *words, int num_words, const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to add a new word or update the count of an existing word
void add_word(WordCount *words, int *num_words, const char *word) {
    int index = search_word(words, *num_words, word);
    if (index != -1) {
        words[index].count++; // Increment count if word exists
    } else {
        strcpy(words[*num_words].word, word); // Copy the word
        words[*num_words].count = 1; // Initialize count
        (*num_words)++; // Increment the number of unique words
    }
}

// Function to print all word counts
void print_word_counts(WordCount *words, int num_words) {
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}