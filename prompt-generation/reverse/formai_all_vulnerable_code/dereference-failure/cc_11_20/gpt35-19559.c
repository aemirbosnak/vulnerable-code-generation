//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 100

// Structure to hold dictionary words
struct dict_word {
    char *word;
};

int main(void) {
    // Open dictionary file
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        fprintf(stderr, "Error opening dictionary file.");
        return 1;
    }

    // Load dictionary into memory
    struct dict_word dictionary[DICTIONARY_SIZE];
    char dictionary_word[MAX_WORD_LENGTH];
    int dictionary_word_count = 0;
    while (fgets(dictionary_word, sizeof(dictionary_word), dictionary_file)) {
        // Remove trailing newline character
        dictionary_word[strcspn(dictionary_word, "\n")] = 0;

        // Add word to dictionary
        dictionary[dictionary_word_count].word = malloc(strlen(dictionary_word) + 1);
        strcpy(dictionary[dictionary_word_count++].word, dictionary_word);
    }
    fclose(dictionary_file);

    // Prompt user for input
    char input[MAX_WORD_LENGTH];
    printf("Enter text to check spelling: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    // Process input
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    char c;
    int i, j, k;
    for (i = 0; i < strlen(input); i++) {
        c = input[i];
        if (isalpha(c) || (word_length > 0 && isdigit(c))) {
            word[word_length++] = c;
        } else {
            // Check if word is in dictionary
            if (word_length > 0) {
                int found = 0;
                for (j = 0; j < dictionary_word_count; j++) {
                    if (strcmp(word, dictionary[j].word) == 0) {
                        found = 1;
                        break;
                    }
                }

                // If word is not in dictionary, suggest corrections
                if (!found) {
                    printf("Incorrect spelling: %s\n", word);
                    printf("Possible corrections:\n");

                    // Replace each letter with every other letter in the alphabet
                    for (j = 0; j < word_length; j++) {
                        for (k = 0; k < 26; k++) {
                            char original_char = word[j];
                            word[j] = 'a' + k;
                            for (int l = 0; l < dictionary_word_count; l++) {
                                if (strcmp(word, dictionary[l].word) == 0) {
                                    printf("- %s\n", word);
                                }
                            }
                            word[j] = original_char;
                        }
                    }
                    printf("\n");
                }

                word_length = 0;
            }
        }
    }

    // Free memory used by dictionary
    for (i = 0; i < dictionary_word_count; i++) {
        free(dictionary[i].word);
    }

    return 0;
}