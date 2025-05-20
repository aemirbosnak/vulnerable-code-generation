//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        // Remove newline character
        line[strlen(line) - 1] = '\0';

        // Check if the word is already in the dictionary
        int i;
        for (i = 0; i < dictionary_size; i++) {
            if (strcmp(line, dictionary[i].word) == 0) {
                dictionary[i].count++;
                break;
            }
        }

        // If the word is not in the dictionary, add it
        if (i == dictionary_size) {
            strcpy(dictionary[dictionary_size].word, line);
            dictionary[dictionary_size].count = 1;
            dictionary_size++;
        }
    }

    fclose(file);
}

int check_spelling(char *word) {
    int i;
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Load the dictionary
    load_dictionary("dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(word);

    // Print the result
    if (is_correct) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is not spelled correctly.\n", word);
    }

    return 0;
}