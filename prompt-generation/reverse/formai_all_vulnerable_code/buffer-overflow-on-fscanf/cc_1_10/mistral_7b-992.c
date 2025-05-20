//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[WORD_LENGTH];
    bool is_valid;
} Word;

void load_dictionary(Word dictionary[DICTIONARY_SIZE]) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char word[WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[i].word, word);
        dictionary[i].is_valid = true;
        i++;
    }

    fclose(fp);
}

bool is_valid_word(Word dictionary[DICTIONARY_SIZE], char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return false;
}

void check_spelling(Word dictionary[DICTIONARY_SIZE], char *input) {
    char words[10][WORD_LENGTH];
    int word_count = 0;

    char *token = strtok(input, " .,\n");
    while (token != NULL) {
        strcpy(words[word_count], token);
        word_count++;

        token = strtok(NULL, " .,\n");
    }

    for (int i = 0; i < word_count; i++) {
        bool is_valid = is_valid_word(dictionary, words[i]);
        if (!is_valid) {
            printf("Error: %s is not a valid word.\n", words[i]);
        }
    }

    printf("Spelling check completed successfully.\n");
}

int main() {
    Word dictionary[DICTIONARY_SIZE];

    load_dictionary(dictionary);

    char input[100];
    printf("Enter a sentence to check spelling: ");
    scanf("%s", input);

    check_spelling(dictionary, input);

    return 0;
}