//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE (MAX_WORDS * WORD_LENGTH)

typedef struct Word {
    char word[WORD_LENGTH];
    int is_valid;
} Word;

void load_dictionary(Word *dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char word[WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[i].word, word);
        dictionary[i].is_valid = 1;
        i++;
    }

    fclose(fp);
}

int check_word(Word *dictionary, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return 0;
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char input[100];
    while (1) {
        printf("Enter a word or type 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);

        input[strlen(input) - 1] = '\0'; // Remove newline character

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