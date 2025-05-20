//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main() {
    char input[MAX_WORD_LENGTH];
    int word_counts[MAX_WORDS] = {0};
    char *words[MAX_WORDS];
    int total_words = 0;

    // Read input from user
    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Split sentence into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(token); ++i) {
            token[i] = tolower(token[i]);
        }
        // Check if word already exists in array of words
        int existing_index = -1;
        for (int i = 0; i < total_words; ++i) {
            if (strcmp(token, words[i]) == 0) {
                existing_index = i;
                break;
            }
        }
        // Add new word to array of words if it doesn't exist
        if (existing_index == -1) {
            if (total_words >= MAX_WORDS) {
                printf("Error: too many words!");
                return 1;
            }
            words[total_words] = malloc(strlen(token) + 1); // +1 for null terminator
            strcpy(words[total_words], token);
            ++total_words;
        }
        // Increment word count
        ++word_counts[existing_index];
        // Get next word
        token = strtok(NULL, " ");
    }

    // Print results
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < total_words; ++i) {
        printf("%s: %d\n", words[i], word_counts[i]);
        free(words[i]);
    }

    return 0;
}