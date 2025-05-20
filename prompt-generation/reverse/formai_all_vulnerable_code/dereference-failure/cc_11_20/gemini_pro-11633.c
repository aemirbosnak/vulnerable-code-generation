//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main(int argc, char *argv[]) {
    // Check for valid input
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Read the file into memory
    char *buffer = malloc(sizeof(char) * MAX_WORDS * MAX_WORD_LENGTH);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        return 1;
    }
    fread(buffer, sizeof(char), MAX_WORDS * MAX_WORD_LENGTH, file);

    // Close the file
    fclose(file);

    // Tokenize the buffer into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    Word word_counts[MAX_WORDS];
    int num_word_counts = 0;
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < num_word_counts; j++) {
            if (strcmp(words[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(word_counts[num_word_counts].word, words[i]);
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }
    }

    // Sort the word counts in descending order
    for (int i = 0; i < num_word_counts - 1; i++) {
        for (int j = i + 1; j < num_word_counts; j++) {
            if (word_counts[i].count < word_counts[j].count) {
                Word temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }

    // Print the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Free the allocated memory
    free(buffer);

    return 0;
}