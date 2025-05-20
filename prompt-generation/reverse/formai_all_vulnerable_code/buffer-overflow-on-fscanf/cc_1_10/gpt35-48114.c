//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a data structure to store word frequency
typedef struct word_freq {
    char *word;
    int freq;
} word_freq_t;

// Function to compare two words by their frequency
int compare_words(const void *a, const void *b) {
    const word_freq_t *word1 = (const word_freq_t *) a;
    const word_freq_t *word2 = (const word_freq_t *) b;
    return word2->freq - word1->freq;
}

int main() {
    char *input_file = "input.txt";
    int max_words = 10000; // Maximum number of words to read

    // Read input file
    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", input_file);
        return 1;
    }

    // Allocate memory for words
    char **words = (char **) malloc(max_words * sizeof(char *));
    int num_words = 0;

    // Read words from file
    char *word = (char *) malloc(255 * sizeof(char));
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        // Add word to array
        words[num_words] = strdup(word);
        num_words++;

        // Check if array needs to be resized
        if (num_words >= max_words) {
            max_words *= 2;
            words = (char **) realloc(words, max_words * sizeof(char *));
        }
    }
    free(word);
    fclose(fp);

    // Allocate memory for word frequency
    word_freq_t *word_freq = (word_freq_t *) malloc(num_words * sizeof(word_freq_t));
    int num_word_freq = 0;

    // Count word frequency
    for (int i = 0; i < num_words; i++) {
        // Check if word already exists in word frequency
        int j;
        for (j = 0; j < num_word_freq; j++) {
            if (strcmp(words[i], word_freq[j].word) == 0) {
                word_freq[j].freq++;
                break;
            }
        }

        // Add new word to word frequency if not found
        if (j == num_word_freq) {
            word_freq[j].word = words[i];
            word_freq[j].freq = 1;
            num_word_freq++;
        }
    }

    // Sort word frequency by frequency
    qsort(word_freq, num_word_freq, sizeof(word_freq_t), compare_words);

    // Print word frequency
    printf("Word Frequency:\n");
    for (int i = 0; i < num_word_freq; i++) {
        printf("%-20s %d\n", word_freq[i].word, word_freq[i].freq);
    }

    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(word_freq);

    return 0;
}