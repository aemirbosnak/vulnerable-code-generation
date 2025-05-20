//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

// Function to check if a word is spelled correctly
int check_spell(char* word) {
    // Open the dictionary file
    FILE* dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening dictionary\n");
        exit(1);
    }

    // Convert word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if word is in dictionary
    char dict_word[MAX_WORD_LEN];
    int match = 0;
    while (fscanf(dict, "%s", dict_word) != EOF) {
        if (strcmp(dict_word, word) == 0) {
            match = 1;
            break;
        }
    }

    // Close dictionary file
    fclose(dict);

    // Return result
    return match;
}

int main() {
    // Open the input file
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Open the output file
    FILE* output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Check each word in the input file for spelling errors
    char word[MAX_WORD_LEN];
    while (fscanf(input, "%s", word) != EOF) {
        // Strip punctuation from word
        for (int i = 0; i < strlen(word); i++) {
            if (ispunct(word[i])) {
                memmove(&word[i], &word[i + 1], strlen(word) - i);
            }
        }

        // Check if word is spelled correctly
        if (check_spell(word)) {
            fprintf(output, "%s ", word);
        } else {
            fprintf(output, "[%s] ", word);
        }
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    // Done!
    printf("Spell checking complete\n");

    return 0;
}