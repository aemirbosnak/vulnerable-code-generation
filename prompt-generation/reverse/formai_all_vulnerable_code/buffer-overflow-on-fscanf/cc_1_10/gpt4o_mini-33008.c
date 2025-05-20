//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_WORDS 10000
#define MAX_LINE_LENGTH 256

char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
int dict_size = 0;

// Function to load dictionary words from a file
int load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        return -1;
    }
    
    while (fscanf(file, "%s", dictionary[dict_size]) != EOF) {
        dict_size++;
        if (dict_size >= MAX_DICTIONARY_WORDS) {
            fprintf(stderr, "Dictionary is full, stopping loading more words.\n");
            break;
        }
    }
    
    fclose(file);
    return 0;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcasecmp(dictionary[i], word) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

// Function to clean and extract words from a line of text
void extract_words(const char *line) {
    char word[MAX_WORD_LENGTH];
    int i = 0, j = 0;

    while (line[i]) {
        if (isalnum(line[i])) {
            word[j++] = tolower(line[i]);
        } else {
            if (j > 0) {
                word[j] = '\0';
                if (!is_word_in_dictionary(word)) {
                    printf("Misspelled word: %s\n", word);
                }
                j = 0;
            }
        }
        i++;
    }
    // Check for the last word in the line
    if (j > 0) {
        word[j] = '\0';
        if (!is_word_in_dictionary(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

// Main function to run the spell checker
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        return 1;
    }

    // Load the dictionary
    if (load_dictionary(argv[1]) != 0) {
        return 1;
    }

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        fprintf(stderr, "Could not open text file %s\n", argv[2]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), text_file)) {
        extract_words(line);
    }

    fclose(text_file);
    return 0;
}