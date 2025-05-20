//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to load dictionary into memory
void load_dictionary(char **dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(fp, "%s", dictionary[word_count])!= EOF) {
        word_count++;
    }

    fclose(fp);
}

// Function to check if a word is in the dictionary
bool is_word_in_dictionary(char *word, char **dictionary) {
    int i = 0;
    while (dictionary[i]!= NULL) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
        i++;
    }

    return false;
}

// Function to suggest corrections for a misspelled word
void suggest_corrections(char *word, char **corrections) {
    int i = 0;
    while (corrections[i]!= NULL) {
        printf("%s\n", corrections[i]);
        i++;
    }
}

// Function to check spelling of a sentence
void check_spelling(char *sentence, char **dictionary, char **corrections) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!is_word_in_dictionary(word, dictionary)) {
            suggest_corrections(word, corrections);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char *sentence = "The quick brown fox jumps over the lazy dog.";
    char *corrections[MAX_WORDS];

    char **dictionary = malloc(MAX_WORDS * sizeof(char *));
    load_dictionary(dictionary);

    check_spelling(sentence, dictionary, corrections);

    free(dictionary);
    return 0;
}