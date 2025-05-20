//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_WORD_LENGTH 100

// Function declarations
void display_help();
int count_words_in_file(const char *filename);
int is_word_char(char c);
void reset_word_count(int *count);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int word_count = count_words_in_file(argv[i]);
        if (word_count != -1) {
            printf("File: %s | Word Count: %d\n", argv[i], word_count);
        } else {
            printf("Error: Could not read file %s\n", argv[i]);
        }
    }

    return 0;
}

// Function to display help message
void display_help() {
    printf("Usage: wordcount [file1 file2 ...]\n");
    printf("Count the number of words in the specified files.\n");
    printf("A word is defined as a sequence of alphanumeric characters.\n");
}

// Function to count words in a file
int count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1; // File couldn't be opened
    }

    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];
    int in_word = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        if (is_word_char(buffer[0])) {
            if (!in_word) {
                in_word = 1; // we are in a word
                word_count++;
            }
        } else {
            in_word = 0; // we are outside of a word
        }
    }

    fclose(file);
    return word_count;
}

// Function to determine if a character is part of a word
int is_word_char(char c) {
    return isalpha(c) || isdigit(c) || c == '\'' || c == '-';
}