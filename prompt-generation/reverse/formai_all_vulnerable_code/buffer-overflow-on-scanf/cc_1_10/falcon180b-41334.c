//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Function to check if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to count words in a file
int countWords(FILE *file) {
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    bool inWord = false;

    while (fscanf(file, "%s", word)!= EOF) {
        // Check if the word is a valid word
        if (strlen(word) > 0) {
            word[strlen(word) - 1] = '\0'; // Remove any trailing newline character
            if (isLetter(word[0])) {
                wordCount++;
            }
        }

        // Reset the inWord flag for the next word
        inWord = false;
    }

    return wordCount;
}

int main() {
    FILE *file;
    char filename[100];

    // Prompt the user for a filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Count the number of words in the file
    int wordCount = countWords(file);

    // Close the file
    fclose(file);

    // Print the word count
    printf("The file contains %d words.\n", wordCount);

    return 0;
}