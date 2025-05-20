//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// The dictionary is an array of strings, each of which is a valid word.
char *dictionary[MAX_WORDS];

// The number of words in the dictionary.
int num_words;

// Function to load the dictionary from a file.
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    // Read the number of words in the dictionary.
    fscanf(fp, "%d", &num_words);

    // Read the words from the dictionary.
    for (int i = 0; i < num_words; i++) {
        dictionary[i] = malloc(MAX_WORD_LENGTH);
        fscanf(fp, "%s", dictionary[i]);
    }

    fclose(fp);
}

// Function to check if a word is in the dictionary.
int is_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to spell check a document.
void spell_check(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening document file");
        exit(1);
    }

    // Read the document line by line.
    char line[1000];
    while (fgets(line, 1000, fp) != NULL) {
        // Split the line into words.
        char *words[100];
        int num_words = 0;
        char *word = strtok(line, " ");
        while (word != NULL) {
            words[num_words++] = word;
            word = strtok(NULL, " ");
        }

        // Check each word in the document.
        for (int i = 0; i < num_words; i++) {
            // Remove any punctuation from the word.
            int len = strlen(words[i]);
            for (int j = 0; j < len; j++) {
                if (!isalpha(words[i][j])) {
                    words[i][j] = '\0';
                }
            }

            // Check if the word is in the dictionary.
            if (!is_word(words[i])) {
                printf("The word \"%s\" is misspelled.\n", words[i]);
            }
        }
    }

    fclose(fp);
}

int main() {
    // Load the dictionary.
    load_dictionary("dictionary.txt");

    // Spell check a document.
    spell_check("document.txt");

    return 0;
}