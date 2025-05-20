//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

// Function to determine if the given character is a word delimiter
int is_word_delimiter(char ch) {
    return isspace(ch) || ch == ',' || ch == '.' || ch == ';' || ch == '!' || ch == '?' || ch == '\n';
}

// Function to count words in a given string
int count_words_in_string(const char *str) {
    int count = 0;
    int in_word = 0; // A flag to determine if we are currently in a word

    while (*str) {
        if (is_word_delimiter(*str)) {
            if (in_word) {
                count++; // We were in a word, so we count it!
                in_word = 0; // Set the flag back to not in a word
            }
        } else {
            in_word = 1; // We found a non-delimiter character, we are in a word
        }
        str++;
    }

    // If the last character was part of a word, we need to count that too
    if (in_word) {
        count++;
    }

    return count; // Return the total word count
}

// Main function to handle the file input and orchestrate the counting
int main() {
    char filename[MAX_FILENAME_LENGTH];
    char buffer[BUFFER_SIZE];
    FILE *file;
    int total_words = 0;

    // Greet the user
    printf("🚀 Welcome to the Word Count Tool! 🚀\n");
    printf("Please enter the filename you want to analyze: ");
    scanf("%s", filename);

    // Attempt to open the specified file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("🚫 Failed to open the file. Please check the filename and try again.");
        return 1; // Exit with error code
    }

    // Read the file line by line and count words
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        total_words += count_words_in_string(buffer);
    }

    // Close the file
    fclose(file);

    // Display the total word count
    printf("🎉 Total word count in '%s': %d words! 🎉\n", filename, total_words);

    return 0; // Successful execution
}