//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

int main(int argc, char* argv[]) {
    FILE* input_file;
    char word_buffer[MAX_WORD_LENGTH];
    int word_count = 0, unique_words = 0;
    word_t words[MAX_WORDS];
    int i, j, k, max_count;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error opening %s\n", argv[1]);
        return 1;
    }

    while (fscanf(input_file, "%s", word_buffer) > 0) {
        // Remove any non-alphabetic characters from the word
        for (i = 0; i < strlen(word_buffer); i++) {
            if (!isalpha(word_buffer[i])) {
                // Shift all subsequent characters left
                for (j = i+1; j < strlen(word_buffer); j++) {
                    word_buffer[j-1] = word_buffer[j];
                }
                // Decrement the offset for the next character
                i--;
            }
            // Convert the character to lowercase
            word_buffer[i] = tolower(word_buffer[i]);
        }

        // Look for the word in the existing list of words
        for (i = 0; i < word_count; i++) {
            if (strcmp(word_buffer, words[i].word) == 0) {
                // Increment the count for the existing word
                words[i].count++;
                break;
            }
        }

        // If the word wasn't found, add a new entry to the list
        if (i == word_count) {
            strcpy(words[i].word, word_buffer);
            words[i].count = 1;
            word_count++;
            unique_words++;
        }
    }

    // Find the most common word(s)
    max_count = words[0].count;
    for (i = 1; i < word_count; i++) {
        if (words[i].count > max_count) {
            max_count = words[i].count;
        }
    }
    printf("The most common word(s):\n");
    for (i = 0; i < word_count; i++) {
        if (words[i].count == max_count) {
            printf("%s (%d)\n", words[i].word, words[i].count);
        }
    }

    // Print the list of words and their frequencies, sorted by frequency
    printf("\nList of words and their frequencies:\n");
    for (i = 0; i < unique_words; i++) {
        int max_index = -1;
        max_count = -1;
        for (j = 0; j < word_count; j++) {
            if (words[j].count > max_count && words[j].count != -1) {
                max_count = words[j].count;
                max_index = j;
            }
        }
        printf("%s: %d\n", words[max_index].word, words[max_index].count);
        words[max_index].count = -1;
    }

    fclose(input_file);
    return 0;
}