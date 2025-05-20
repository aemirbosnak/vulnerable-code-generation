//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main(int argc, char *argv[]) {

    char input_text[1000];
    int num_words = 0;
    int i, j, k;
    int word_count = 0;
    int word_lengths[MAX_WORD_LENGTH] = {0};
    char *word_list[MAX_WORDS] = {NULL};
    int word_freq[MAX_WORDS] = {0};

    printf("Enter a string of text: ");
    fgets(input_text, 1000, stdin);

    // Clean up input text
    input_text[strcspn(input_text, "\n")] = '\0';

    // Split input into words
    char *token = strtok(input_text, " ");
    while (token != NULL) {
        // Trim word of non-alphanumeric characters
        for (i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                memmove(&token[i], &token[i + 1], strlen(token) - i);
            }
        }

        // Convert to lowercase
        for (j = 0; j < strlen(token); j++) {
            token[j] = tolower(token[j]);
        }

        // Add word to array and update count
        if (strlen(token) > 0) {
            if (num_words < MAX_WORDS) {
                word_list[num_words] = malloc(sizeof(char) * (strlen(token) + 1));
                strcpy(word_list[num_words], token);
                num_words++;
            }
            for (k = 0; k < num_words; k++) {
                if (strcmp(word_list[k], token) == 0) {
                    word_freq[k]++;
                    word_count++;
                    break;
                }
            }
        }

        token = strtok(NULL, " ");
    }

    // Update word length count
    for (i = 0; i < num_words; i++) {
        int word_length = strlen(word_list[i]);
        if (word_length < MAX_WORD_LENGTH) {
            word_lengths[word_length]++;
        } else {
            word_lengths[MAX_WORD_LENGTH - 1]++;
        }
    }

    // Output results
    printf("\nWord Frequencies\n----------------\n");
    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", word_list[i], word_freq[i]);
    }
    printf("\n");
    printf("Total words: %d\n", word_count);

    printf("\nWord Length Frequencies\n-----------------------\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%2d letters: %d\n", i, word_lengths[i]);
    }

    // Free memory
    for (i = 0; i < num_words; i++) {
        free(word_list[i]);
    }

    return 0;
}