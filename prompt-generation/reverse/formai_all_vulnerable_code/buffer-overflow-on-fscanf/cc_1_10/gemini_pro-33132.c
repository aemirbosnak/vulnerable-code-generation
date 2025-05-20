//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Sherlock's dictionary
static char *dictionary[MAX_WORDS];

// The corpus of words to be checked
static char *corpus[MAX_WORDS];

// The list of misspelled words
static char *misspelled[MAX_WORDS];

// Initialize the dictionary
void init_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        dictionary[i] = strdup(word);
        i++;
    }

    fclose(fp);
}

// Initialize the corpus
void init_corpus() {
    FILE *fp = fopen("corpus.txt", "r");
    if (fp == NULL) {
        printf("Error opening corpus file.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        corpus[i] = strdup(word);
        i++;
    }

    fclose(fp);
}

// Check the spelling of the words in the corpus
void check_spelling() {
    int i, j;

    for (i = 0; i < MAX_WORDS && corpus[i] != NULL; i++) {
        int found = 0;

        for (j = 0; j < MAX_WORDS && dictionary[j] != NULL; j++) {
            if (strcmp(corpus[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            misspelled[i] = corpus[i];
        }
    }
}

// Print the list of misspelled words
void print_misspelled() {
    int i;

    for (i = 0; i < MAX_WORDS && misspelled[i] != NULL; i++) {
        printf("Misspelled word: %s\n", misspelled[i]);
    }
}

// Main function
int main() {
    init_dictionary();
    init_corpus();
    check_spelling();
    print_misspelled();

    return 0;
}