//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_frequency;

int compare_words(const void *a, const void *b) {
    word_frequency *wa = (word_frequency *)a;
    word_frequency *wb = (word_frequency *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    FILE *fp;
    char *filename = "input.txt";
    char buffer[MAX_WORD_LENGTH];
    word_frequency words[MAX_WORDS];
    int num_words = 0;

    // Open the input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file and count the words
    while (fscanf(fp, "%s", buffer) != EOF) {
        // Remove punctuation and convert to lowercase
        int i = 0;
        while (buffer[i] != '\0') {
            if (ispunct(buffer[i])) {
                buffer[i] = '\0';
            } else {
                buffer[i] = tolower(buffer[i]);
                i++;
            }
        }

        // Check if the word is already in the list
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, buffer) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it
        if (!found) {
            words[num_words].word = strdup(buffer);
            words[num_words].count = 1;
            num_words++;
        }
    }

    // Close the input file
    fclose(fp);

    // Sort the words by frequency in descending order
    qsort(words, num_words, sizeof(word_frequency), compare_words);

    // Print the words and their frequencies
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free the memory allocated for the words
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return EXIT_SUCCESS;
}