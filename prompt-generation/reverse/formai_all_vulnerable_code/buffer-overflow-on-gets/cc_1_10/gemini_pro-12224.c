//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a word and its frequency
typedef struct {
    char* word;
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structures by frequency
int compare_word_frequency(const void* a, const void* b) {
    const WordFrequency* word_a = (const WordFrequency*)a;
    const WordFrequency* word_b = (const WordFrequency*)b;

    return word_b->frequency - word_a->frequency;
}

// Function to count the frequency of each word in a string
WordFrequency* count_word_frequencies(const char* text) {
    // Allocate memory for the array of WordFrequency structures
    WordFrequency* word_frequencies = malloc(sizeof(WordFrequency) * 1000);

    // Tokenize the string into words
    char* token = strtok((char*)text, " ");
    int word_count = 0;
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(token, word_frequencies[i].word) == 0) {
                word_frequencies[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            word_frequencies[word_count].word = strdup(token);
            word_frequencies[word_count].frequency = 1;
            word_count++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the array by frequency
    qsort(word_frequencies, word_count, sizeof(WordFrequency), compare_word_frequency);

    // Return the array
    return word_frequencies;
}

// Function to print the top 10 most frequent words in a string
void print_top_10_words(const char* text) {
    // Count the word frequencies
    WordFrequency* word_frequencies = count_word_frequencies(text);

    // Print the top 10 most frequent words
    printf("The top 10 most frequent words in the text are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }

    // Free the memory allocated for the array of WordFrequency structures
    for (int i = 0; i < 1000; i++) {
        free(word_frequencies[i].word);
    }
    free(word_frequencies);
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Print the top 10 most frequent words in the text
    print_top_10_words(text);

    return 0;
}