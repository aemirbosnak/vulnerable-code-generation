//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryEntry;

DictionaryEntry dictionary[DICTIONARY_SIZE];
int dict_count = 0;

// Function to load words into the dictionary from a file
void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[dict_count].word) != EOF) {
        dictionary[dict_count].frequency = 0; // Initialize frequency
        dict_count++;

        if (dict_count >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary size exceeded!\n");
            break;
        }
    }
    fclose(file);
}

// Function to make a word lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word exists in the dictionary
int check_in_dictionary(const char *word) {
    for (int i = 0; i < dict_count; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            dictionary[i].frequency++;
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest corrections based on word frequency
void suggest_corrections(const char *word) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dict_count; i++) {
        if (strstr(dictionary[i].word, word) != NULL) {
            printf(" - %s (Frequency: %d)\n", dictionary[i].word, dictionary[i].frequency);
        }
    }
}

// Main function to read a text file and check spelling
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1]);

    FILE *text_file = fopen(argv[2], "r");
    if (!text_file) {
        fprintf(stderr, "Could not open text file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(text_file, "%s", word) != EOF) {
        to_lowercase(word);
        if (!check_in_dictionary(word)) {
            printf("Unknown word: %s\n", word);
            suggest_corrections(word);
        }
    }

    fclose(text_file);
    return EXIT_SUCCESS;
}