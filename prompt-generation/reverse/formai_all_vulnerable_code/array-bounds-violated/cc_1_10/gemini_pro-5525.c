//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline character
        line[strlen(line) - 1] = '\0';

        // Copy word to dictionary
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].count = 0;

        num_words++;
    }

    fclose(fp);
}

int check_spelling(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

void spell_check(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening text file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check spelling
        if (!check_spelling(word)) {
            printf("%s: not found in dictionary\n", word);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s dictionary.txt text.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_dictionary(argv[1]);
    spell_check(argv[2]);

    return EXIT_SUCCESS;
}