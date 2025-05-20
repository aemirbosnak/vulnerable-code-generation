//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: rigorous
/*
 * A rigorous C spell checking program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

int is_word_correct(const char *word) {
    int i, len = strlen(word);
    for (i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_word_in_dictionary(const char *word) {
    FILE *dict;
    char line[MAX_WORD_LEN];
    int found = 0;

    dict = fopen("dictionary.txt", "r");
    if (!dict) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, dict)) {
        if (strcmp(word, line) == 0) {
            found = 1;
            break;
        }
    }

    fclose(dict);
    return found;
}

int main(int argc, char **argv) {
    char word[MAX_WORD_LEN];
    int i, j, len;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        exit(1);
    }

    while (fgets(word, MAX_WORD_LEN, file)) {
        len = strlen(word);
        for (i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        if (!is_word_correct(word)) {
            continue;
        }
        if (!is_word_in_dictionary(word)) {
            printf("%s is not in the dictionary\n", word);
        }
    }

    fclose(file);
    return 0;
}