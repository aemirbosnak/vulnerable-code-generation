//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to store the word count and its corresponding word
typedef struct {
    int count;
    char *word;
} WordCount;

// Declare a function to compare two WordCount structs based on their word count
int compareWordCount(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return wc2->count - wc1->count;
}

// Declare a function to count the occurrences of each word in a string
WordCount *countWords(const char *str, int *num_words) {
    // Allocate memory for the array of WordCount structs
    WordCount *word_counts = malloc(sizeof(WordCount) * 1000);

    // Initialize the number of words to 0
    *num_words = 0;

    // Tokenize the string into words
    char *token = strtok(str, " ");

    // Iterate over the words
    while (token != NULL) {
        // Check if the word is already in the array of WordCount structs
        int found = 0;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(token, word_counts[i].word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it to the array
        if (!found) {
            word_counts[*num_words].count = 1;
            word_counts[*num_words].word = malloc(strlen(token) + 1);
            strcpy(word_counts[*num_words].word, token);
            (*num_words)++;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Sort the array of WordCount structs in descending order of word count
    qsort(word_counts, *num_words, sizeof(WordCount), compareWordCount);

    // Return the array of WordCount structs
    return word_counts;
}

// Declare a function to print the word count for each word in an array of WordCount structs
void printWordCounts(WordCount *word_counts, int num_words) {
    // Iterate over the array of WordCount structs
    for (int i = 0; i < num_words; i++) {
        // Print the word and its count
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

// Declare a function to free the memory allocated for the array of WordCount structs
void freeWordCounts(WordCount *word_counts, int num_words) {
    // Iterate over the array of WordCount structs
    for (int i = 0; i < num_words; i++) {
        // Free the memory allocated for the word
        free(word_counts[i].word);
    }

    // Free the memory allocated for the array of WordCount structs
    free(word_counts);
}

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Count the occurrences of each word in the string
    int num_words;
    WordCount *word_counts = countWords(str, &num_words);

    // Print the word count for each word
    printf("Word count:\n");
    printWordCounts(word_counts, num_words);

    // Free the memory allocated for the array of WordCount structs
    freeWordCounts(word_counts, num_words);

    return 0;
}