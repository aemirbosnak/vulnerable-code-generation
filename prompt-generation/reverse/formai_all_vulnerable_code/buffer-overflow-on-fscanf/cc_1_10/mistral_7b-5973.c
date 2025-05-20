//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 100
#define WORD_LENGTH_MAX 50

char dictionary[DICTIONARY_SIZE][WORD_LENGTH_MAX];
int dictionary_index = 0;

void load_dictionary(FILE *fp) {
    char word[WORD_LENGTH_MAX];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[dictionary_index], word);
        dictionary_index++;
    }
}

int is_word_in_dictionary(char *word) {
    for (int i = 0; i < dictionary_index; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_word(char *word) {
    if (is_word_in_dictionary(word)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is not in the dictionary. Maybe it's a new word?\n", word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the dictionary file.\n");
        return 1;
    }

    load_dictionary(fp);
    fclose(fp);

    check_word(argv[1]);

    return 0;
}