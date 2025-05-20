//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_SIZE 50000

// Function prototypes
void load_dictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int *n);
int binary_search(char dictionary[][MAX_WORD_LENGTH], int n, const char *word);
void spell_check(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int n);
void print_suggestions(char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int n, const char *misspelled_word);
void to_lowercase(char *str);

int main(int argc, char *argv[]) {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int word_count = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1], dictionary, &word_count);
    spell_check(argv[2], dictionary, word_count);

    return EXIT_SUCCESS;
}

void load_dictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*n]) == 1) {
        (*n)++;
    }
    fclose(file);
}

void spell_check(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation, convert to lowercase
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        to_lowercase(word);

        if (binary_search(dictionary, n, word) == -1) {
            printf("Misspelled word: %s\n", word);
            print_suggestions(dictionary, n, word);
        }
    }
    fclose(file);
}

int binary_search(char dictionary[][MAX_WORD_LENGTH], int n, const char *word) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(dictionary[mid], word);
        if (cmp == 0) {
            return mid; // word found
        }
        if (cmp < 0) {
            left = mid + 1; // search in right half
        } else {
            right = mid - 1; // search in left half
        }
    }
    return -1; // word not found
}

void print_suggestions(char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int n, const char *misspelled_word) {
    printf("Suggestions: ");
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(dictionary[i], misspelled_word, 2) == 0 && strcmp(dictionary[i], misspelled_word) != 0) {
            printf("%s ", dictionary[i]);
            count++;
        }
        if (count == 5) break; // Limit suggestions to 5
    }
    if(count == 0) {
        printf("(No suggestions available)");
    }
    printf("\n");
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}