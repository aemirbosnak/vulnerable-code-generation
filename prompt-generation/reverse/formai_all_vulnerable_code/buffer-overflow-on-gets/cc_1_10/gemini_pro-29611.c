//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 1000

// Create a struct to store the word and its count
typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

// Create an array to store the words and their counts
word_count word_counts[MAX_WORDS_IN_SENTENCE];

// Get the number of words in a sentence
int get_num_words(char *sentence) {
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }
    return num_words;
}

// Get the index of a word in the array of words
int get_word_index(char *word) {
    for (int i = 0; i < MAX_WORDS_IN_SENTENCE; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Increment the count of a word
void increment_word_count(char *word) {
    int index = get_word_index(word);
    if (index == -1) {
        // The word is not in the array, so add it
        strcpy(word_counts[MAX_WORDS_IN_SENTENCE].word, word);
        word_counts[MAX_WORDS_IN_SENTENCE].count = 1;
    } else {
        // The word is already in the array, so increment its count
        word_counts[index].count++;
    }
}

// Print the words and their counts
void print_word_counts() {
    for (int i = 0; i < MAX_WORDS_IN_SENTENCE; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

// Get a sentence from the user
char *get_sentence() {
    char *sentence = malloc(1000);
    printf("Enter a sentence: ");
    gets(sentence);
    return sentence;
}

// Main function
int main() {
    char *sentence = get_sentence();
    int num_words = get_num_words(sentence);

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        increment_word_count(word);
        word = strtok(NULL, " ");
    }

    print_word_counts();

    return 0;
}