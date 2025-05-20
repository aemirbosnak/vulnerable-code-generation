//FormAI DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 50000

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];
int dictionary_size = 0;

int read_dictionary() {
    char word[MAX_WORD_LEN];
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) return 0;

    while (fscanf(fp, "%s", word) != EOF) {
        if (dictionary_size >= MAX_DICT_WORDS) {
            fclose(fp);
            return 0;
        }
        strcpy(dictionary[dictionary_size++], word);
    }

    fclose(fp);
    return 1; 
}

int is_word_in_dictionary(char *word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    if (! read_dictionary()) {
        printf("Error: Failed to read dictionary file.\n");
        return 1;
    }

    char input[MAX_WORD_LEN];
    printf("Enter a sentence: ");
    while (scanf("%s", input) != EOF) {
        if (! is_word_in_dictionary(input)) {
            printf("Spelling mistake: %s\n", input);
        }
    }

    return 0;
}