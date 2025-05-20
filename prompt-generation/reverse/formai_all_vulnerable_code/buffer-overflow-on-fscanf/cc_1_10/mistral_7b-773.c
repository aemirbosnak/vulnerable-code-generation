//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50
#define DICTIONARY_SIZE 1000

typedef struct {
    char word[WORD_SIZE];
    int is_valid;
} Dictionary;

void load_dictionary(Dictionary *dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        fscanf(fp, "%s", dictionary[i].word);
        dictionary[i].is_valid = 1;
    }

    fclose(fp);
}

int check_word(Dictionary *dictionary, char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return 0;
}

int main() {
    Dictionary dictionary[DICTIONARY_SIZE];
    load_dictionary(dictionary);

    char input[100];
    while (1) {
        printf("Enter a word to check (type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int is_valid = check_word(dictionary, input);
        if (is_valid) {
            printf("The word '%s' is valid.\n", input);
        } else {
            printf("The word '%s' is not valid.\n", input);
        }
    }

    return 0;
}