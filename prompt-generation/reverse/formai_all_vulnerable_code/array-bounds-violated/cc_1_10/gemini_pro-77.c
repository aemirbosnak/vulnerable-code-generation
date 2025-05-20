//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

bool load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return false;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) > 0) {
            strcpy(dictionary[num_words].word, line);
            dictionary[num_words].count = 0;
            num_words++;
        }
    }

    fclose(fp);

    return true;
}

bool is_word_in_dictionary(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return true;
        }
    }

    return false;
}

void spell_check(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        char *word = strtok(line, " ,;:.!?");
        while (word != NULL) {
            if (!is_word_in_dictionary(word)) {
                printf("Misspelled word: %s\n", word);
            }

            word = strtok(NULL, " ,;:.!?");
        }
    }

    fclose(fp);
}

int main() {
    if (!load_dictionary("dictionary.txt")) {
        printf("Error loading dictionary\n");
        return 1;
    }

    spell_check("document.txt");

    return 0;
}