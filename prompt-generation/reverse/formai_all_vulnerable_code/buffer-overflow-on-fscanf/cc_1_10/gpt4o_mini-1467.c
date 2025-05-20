//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

char *dictionary[MAX_DICTIONARY_SIZE];
int word_count = 0;

void load_dictionary(const char *filename);
int is_word_in_dictionary(const char *word, int index);
void check_spelling(const char *filename);
void to_lower_case(char *word);

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[word_count]) != EOF) {
        to_lower_case(dictionary[word_count]);
        word_count++;
    }
    fclose(file);
}

int is_word_in_dictionary(const char *word, int index) {
    if (index >= word_count) {
        return 0; // Word not found
    }
    if (strcmp(dictionary[index], word) == 0) {
        return 1; // Word found
    }
    return is_word_in_dictionary(word, index + 1); // Check next word
}

void check_spelling(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file to check spelling.\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        if (!is_word_in_dictionary(word, 0)) {
            printf("Misspelled word: %s\n", word);
        }
    }
    fclose(file);
}

void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);

    return EXIT_SUCCESS;
}