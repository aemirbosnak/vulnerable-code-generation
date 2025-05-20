//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

char *dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return;
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        dictionary[num_words++] = strdup(line);
    }

    fclose(fp);
}

int check_spelling(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void spell_check_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int line_num = 1;
    while (fgets(line, 1024, fp) != NULL) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            if (!check_spelling(word)) {
                printf("Misspelled word on line %d: %s\n", line_num, word);
            }

            word = strtok(NULL, " ");
        }

        line_num++;
    }

    fclose(fp);
}

int main() {
    load_dictionary("dictionary.txt");
    spell_check_file("file.txt");

    return 0;
}