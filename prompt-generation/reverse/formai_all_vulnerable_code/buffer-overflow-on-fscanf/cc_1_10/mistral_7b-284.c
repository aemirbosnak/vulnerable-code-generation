//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_VALID_WORDS 100

char valid_words[NUM_VALID_WORDS][MAX_WORD_LENGTH];

void initialize_dictionary() {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(valid_words[i], word);
        i++;
    }

    fclose(fp);
}

int is_valid_word(char word[MAX_WORD_LENGTH]) {
    int i;

    for (i = 0; i < NUM_VALID_WORDS; i++) {
        if (strcmp(word, valid_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char user_word[MAX_WORD_LENGTH];
    int word_is_valid;

    initialize_dictionary();

    printf("Welcome to the C Spell Checker!\n");
    printf("Enter a word, or type 'quit' to exit.\n");

    while (1) {
        scanf("%s", user_word);

        if (strcmp(user_word, "quit") == 0) {
            break;
        }

        word_is_valid = is_valid_word(user_word);

        if (word_is_valid) {
            printf("'%s' is a valid word.\n", user_word);
        } else {
            printf("'%s' is not a valid word. Please check your spelling.\n", user_word);
        }
    }

    printf("Goodbye!\n");

    return 0;
}