//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove the newline character from the end of the line.
        line[strlen(line) - 1] = '\0';

        // Copy the word into the dictionary.
        strcpy(dictionary[dictionary_size].word, line);

        // Initialize the word count to 0.
        dictionary[dictionary_size].count = 0;

        // Increment the dictionary size.
        dictionary_size++;
    }

    fclose(fp);
}

int is_word_in_dictionary(char *word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

void check_spelling(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening text file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove the newline character from the end of the line.
        line[strlen(line) - 1] = '\0';

        // Split the line into words.
        char *words[MAX_WORD_LENGTH];
        int num_words = 0;
        char *word = strtok(line, " ");
        while (word != NULL) {
            words[num_words++] = word;
            word = strtok(NULL, " ");
        }

        // Check the spelling of each word.
        for (int i = 0; i < num_words; i++) {
            if (!is_word_in_dictionary(words[i])) {
                printf("The word '%s' is not in the dictionary.\n", words[i]);
            }
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);

    return 0;
}