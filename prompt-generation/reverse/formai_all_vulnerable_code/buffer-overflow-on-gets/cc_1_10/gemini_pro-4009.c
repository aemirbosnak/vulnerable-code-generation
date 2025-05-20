//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of words in a line
#define MAX_WORDS_IN_LINE 100

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of lines in a file
#define MAX_LINES_IN_FILE 1000

// Define the maximum number of words in a file
#define MAX_WORDS_IN_FILE 10000

// Define the maximum number of characters in a file
#define MAX_CHARACTERS_IN_FILE 100000

// Define the maximum number of unique words in a file
#define MAX_UNIQUE_WORDS_IN_FILE 1000

// Define the maximum number of characters in a unique word
#define MAX_UNIQUE_WORD_LENGTH 100

// Define the maximum number of lines in a file
#define MAX_LINES_IN_FILE 1000

// Define the maximum number of words in a file
#define MAX_WORDS_IN_FILE 10000

// Define the maximum number of characters in a file
#define MAX_CHARACTERS_IN_FILE 100000

// Define the maximum number of unique words in a file
#define MAX_UNIQUE_WORDS_IN_FILE 1000

// Define the maximum number of characters in a unique word
#define MAX_UNIQUE_WORD_LENGTH 100

// Define the maximum number of lines in a file
#define MAX_LINES_IN_FILE 1000

// Define the maximum number of words in a file
#define MAX_WORDS_IN_FILE 10000

// Define the maximum number of characters in a file
#define MAX_CHARACTERS_IN_FILE 100000

// Define the maximum number of unique words in a file
#define MAX_UNIQUE_WORDS_IN_FILE 1000

// Define the maximum number of characters in a unique word
#define MAX_UNIQUE_WORD_LENGTH 100

// Define the maximum number of lines in a file
#define MAX_LINES_IN_FILE 1000

// Define the maximum number of words in a file
#define MAX_WORDS_IN_FILE 10000

// Define the maximum number of characters in a file
#define MAX_CHARACTERS_IN_FILE 100000

// Define the maximum number of unique words in a file
#define MAX_UNIQUE_WORDS_IN_FILE 1000

// Define the maximum number of characters in a unique word
#define MAX_UNIQUE_WORD_LENGTH 100

// Declare the global variables
int total_lines = 0;
int total_words = 0;
int total_characters = 0;
int total_unique_words = 0;
char unique_words[MAX_UNIQUE_WORDS_IN_FILE][MAX_UNIQUE_WORD_LENGTH];

// Declare the main function
int main() {
    // Declare the local variables
    char filename[100];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j, k;

    // Get the filename from the user
    printf("Enter the filename: ");
    gets(filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Increment the total number of lines
        total_lines++;

        // Get the number of words in the line
        i = 0;
        j = 0;
        while (line[i] != '\0') {
            // Skip the whitespace characters
            while (isspace(line[i])) {
                i++;
            }

            // Get the word
            j = 0;
            while (!isspace(line[i]) && line[i] != '\0') {
                word[j] = line[i];
                i++;
                j++;
            }
            word[j] = '\0';

            // Increment the total number of words
            total_words++;

            // Increment the total number of characters
            total_characters += j;

            // Check if the word is unique
            k = 0;
            while (k < total_unique_words) {
                if (strcmp(word, unique_words[k]) == 0) {
                    break;
                }
                k++;
            }
            if (k == total_unique_words) {
                strcpy(unique_words[total_unique_words], word);
                total_unique_words++;
            }
        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_characters);
    printf("Total unique words: %d\n", total_unique_words);

    return 0;
}