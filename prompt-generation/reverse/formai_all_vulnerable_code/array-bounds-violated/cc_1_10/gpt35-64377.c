//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

// For simplicity, we'll use an array of strings to store the dictionary words
char dictionary[MAX_NUM_WORDS][MAX_WORD_LEN];
int num_words = 0;

void read_dictionary_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: could not open dictionary file '%s'\n", filename);
        exit(1);
    }

    // Read each line of the dictionary file and store the words in the dictionary array
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, f)) {
        // Remove newline character at end of line if it exists
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }

        // Convert all letters to lowercase for case-insensitive comparison
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Copy the lowercase word into the dictionary array
        strncpy(dictionary[num_words], line, MAX_WORD_LEN);
        num_words++;
    }

    fclose(f);
}

int in_dictionary(const char* word) {
    // Check if the given word is in the dictionary
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void check_spelling(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: could not open input file '%s'\n", filename);
        exit(1);
    }

    // Read each word from the input file and check if it is in the dictionary
    char word[MAX_WORD_LEN];
    while (fscanf(f, "%s", word) != EOF) {
        // Remove any non-alphabetic characters from the word
        int len = strlen(word);
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word[j++] = tolower(word[i]);
            }
        }
        word[j] = '\0';

        if (!in_dictionary(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(f);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <input file>\n", argv[0]);
        exit(1);
    }

    read_dictionary_file(argv[1]);
    check_spelling(argv[2]);

    return 0;
}