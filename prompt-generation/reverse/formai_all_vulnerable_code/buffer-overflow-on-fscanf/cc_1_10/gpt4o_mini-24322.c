//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "The realm of files cannot be traversed: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*word_count]) != EOF && *word_count < DICTIONARY_SIZE) {
        (*word_count)++;
    }

    fclose(file);
}

int check_spelling(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // found the word in dictionary
        }
    }
    return 0; // word not found
}

void spell_check_file(const char *filename, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "The scroll of text could not be unearthed: %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("Let's begin the grand spell-checking adventure within the tome: %s\n", filename);
    printf("Beware! Unfamiliar words shall be revealed:\n");

    while (fscanf(file, "%s", word) != EOF) {
        if (!check_spelling(word, dictionary, word_count)) {
            printf("- The word '%s' was lost in the enchanted forest of language.\n", word);
        }
    }

    fclose(file);
}

void display_usage() {
    printf("Welcome, brave soul to the Spell Check realm!\n");
    printf("Usage: ./spellcheck <dictionary_file> <text_file>\n");
    printf("Your missives shall be scrutinized for errant words!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int word_count = 0;

    load_dictionary(argv[1], dictionary, &word_count);
    spell_check_file(argv[2], dictionary, word_count);

    printf("The spell-checking quest is at an end! Proceed with your newfound knowledge.\n");
    return EXIT_SUCCESS;
}