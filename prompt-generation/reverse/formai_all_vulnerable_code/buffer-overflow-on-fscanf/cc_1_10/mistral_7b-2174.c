//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[WORD_LENGTH];
    int is_valid;
} word_t;

word_t dictionary[DICTIONARY_SIZE];

void load_dictionary() {
    FILE *fp;
    char filename[] = "dictionary.txt";
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oh dear, could not find the dictionary file!\n");
        exit(1);
    }

    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        i++;
    }

    fclose(fp);

    printf("Wow! Loaded %d words into the dictionary!\n", i);
}

int check_word(char *word) {
    int i;
    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcasecmp(word, dictionary[i].word) == 0) {
            dictionary[i].is_valid = 1;
            return 1;
        }
    }

    return 0;
}

int main() {
    char user_input[WORD_LENGTH];
    int valid_word = 0;

    load_dictionary();

    printf("Hello there, I'm a surprised C Spell checker!\n");
    printf("Please type in a word, and I'll let you know if it's valid!\n");

    while (1) {
        printf("> ");
        fgets(user_input, WORD_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        valid_word = check_word(user_input);

        if (valid_word) {
            printf("Great job! That word is valid!\n");
        } else {
            printf("Oh noes! That word is not in the dictionary!\n");
        }
    }

    return 0;
}