//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function declarations
void countWordsLinesChars(const char *filename, int *wordCount, int *lineCount, int *charCount);
void displayCounts(int wordCount, int lineCount, int charCount);

int main() {
    char filename[256];
    int wordCount = 0, lineCount = 0, charCount = 0;

    // Welcome message
    printf("Welcome to the C Word Count Tool!\n");
    printf("I'm curious about the file you'd like to analyze.\n");

    // Prompt user for filename
    printf("Please enter the path to your text file: ");
    scanf("%s", filename);

    // Count words, lines, and characters
    countWordsLinesChars(filename, &wordCount, &lineCount, &charCount);

    // Display the results
    displayCounts(wordCount, lineCount, charCount);

    return 0;
}

void countWordsLinesChars(const char *filename, int *wordCount, int *lineCount, int *charCount) {
    FILE *file = fopen(filename, "r"); // Let's open the file
    if (file == NULL) {
        fprintf(stderr, "Oops! I couldn't open the file %s. Does it exist?\n", filename);
        exit(EXIT_FAILURE);
    }

    char ch;
    int inWord = 0;

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        (*charCount)++; // Increment character count

        if (ch == '\n') {
            (*lineCount)++; // Increment line count on new line character
        }

        // Check for word boundaries
        if (isspace(ch)) {
            if (inWord) {
                (*wordCount)++; // We've reached the end of a word
                inWord = 0;     // Reset inWord flag
            }
        } else {
            inWord = 1; // We're in a word
        }
    }

    // If the file does not end with a newline, we can have a last word
    if (inWord) {
        (*wordCount)++;
    }

    fclose(file); // Close the file after reading
}

void displayCounts(int wordCount, int lineCount, int charCount) {
    // Inquiring about the results
    printf("Here are the results of the analysis:\n");
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);
    printf("Total characters (including spaces): %d\n", charCount);
    printf("Isn't it fascinating to see how many elements are in your file?\n");
}