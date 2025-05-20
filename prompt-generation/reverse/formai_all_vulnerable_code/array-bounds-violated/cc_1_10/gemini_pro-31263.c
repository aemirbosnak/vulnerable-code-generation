//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words;

int load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_WORD_LEN + 1];
    while (fgets(line, MAX_WORD_LEN + 1, fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (num_words < MAX_WORDS) {
            strcpy(dictionary[num_words].word, line);
            dictionary[num_words].count = 0;
            num_words++;
        }
    }

    fclose(fp);

    return 0;
}

int check_spelling(const char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s dictionary.txt text.txt\n", argv[0]);
        return 1;
    }

    if (load_dictionary(argv[1]) != 0) {
        printf("Error loading dictionary.\n");
        return 1;
    }

    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        char *word = strtok(line, " ,.;:\"'?!");
        while (word != NULL) {
            if (!check_spelling(word)) {
                printf("Misspelled word: %s\n", word);
            }
            word = strtok(NULL, " ,.;:\"'?!");
        }
    }

    fclose(fp);

    return 0;
}