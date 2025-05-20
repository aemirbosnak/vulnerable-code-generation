//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: complete
/*
 * Word Count Tool
 *
 * This program counts the number of words in a text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int count_words(char *str) {
    int words = 0;
    char *p = str;

    // Iterate over the string and count the number of words
    while (*p != '\0') {
        // Check if the current character is a space or a newline
        if (*p == ' ' || *p == '\n') {
            // If it is, increment the word count
            words++;
        }
        p++;
    }

    return words;
}

// Function to print the word count
void print_word_count(int words) {
    printf("Number of words: %d\n", words);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Read the contents of the file into a string
    char *str = malloc(1000);
    fgets(str, 1000, file);
    fclose(file);

    // Count the number of words in the string
    int words = count_words(str);

    // Print the word count
    print_word_count(words);

    // Free the memory allocated for the string
    free(str);

    return 0;
}