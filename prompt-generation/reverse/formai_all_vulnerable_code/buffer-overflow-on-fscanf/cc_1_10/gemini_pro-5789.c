//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 256

typedef struct {
    char *word;
    int count;
} word_frequency;

int compare_word_frequency(const void *a, const void *b) {
    word_frequency *word_a = (word_frequency *)a;
    word_frequency *word_b = (word_frequency *)b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *file;
    char *filename = "input.txt";
    char buffer[MAX_WORD_LENGTH];
    word_frequency word_frequencies[MAX_WORDS];
    int num_words = 0;
    int i, j;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Read the file word by word
    while (fscanf(file, "%s", buffer) != EOF) {
        // Check if the word is already in the frequency table
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_frequencies[i].word, buffer) == 0) {
                word_frequencies[i].count++;
                break;
            }
        }

        // If the word is not in the frequency table, add it
        if (i == num_words) {
            word_frequencies[num_words].word = strdup(buffer);
            word_frequencies[num_words].count = 1;
            num_words++;
        }
    }

    // Close the file
    fclose(file);

    // Sort the frequency table
    qsort(word_frequencies, num_words, sizeof(word_frequency), compare_word_frequency);

    // Print the frequency table
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    // Free the memory allocated for the word frequencies
    for (i = 0; i < num_words; i++) {
        free(word_frequencies[i].word);
    }

    return EXIT_SUCCESS;
}