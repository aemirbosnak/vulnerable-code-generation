//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
/*
 * Word Count Tool
 *
 * This program counts the number of words in a text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    // Check the number of command-line arguments
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", argv[1]);
        return 1;
    }

    // Declare variables
    int word_count = 0;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char *line_ptr = line;
    char *word_ptr = word;

    // Read lines from the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Reset the word pointer
        word_ptr = word;

        // Iterate over the characters in the line
        for (int i = 0; i < strlen(line); i++) {
            // Check if the character is a space or a tab
            if (line[i] == ' ' || line[i] == '\t') {
                // Add the word to the word count
                word_count++;

                // Reset the word pointer
                word_ptr = word;
            } else {
                // Add the character to the word
                *word_ptr++ = line[i];
            }
        }

        // Add the last word to the word count
        word_count++;
    }

    // Close the file
    fclose(file);

    // Print the word count
    printf("Word count: %d\n", word_count);

    return 0;
}