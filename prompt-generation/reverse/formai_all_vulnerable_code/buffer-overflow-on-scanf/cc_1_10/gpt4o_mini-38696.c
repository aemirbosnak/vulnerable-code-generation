//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void countWords(const char *text, int *wordCount, int *lineCount) {
    int inWord = 0;  // flag to track if we're inside a word
    *wordCount = 0;
    *lineCount = 0;

    // Loop through each character in the text
    while (*text) {
        // Check for new line character
        if (*text == '\n') {
            (*lineCount)++;
            inWord = 0;  // reset inWord when encountering a new line
        }
        // Check if current character is a space or a word boundary
        if (isspace(*text) || ispunct(*text)) {
            if (inWord) {  // We're closing a word
                (*wordCount)++;
                inWord = 0;  // Reset
            }
        } else {
            inWord = 1;  // We're inside a word
        }
        text++;
    }
    // Last word case, if the string doesn't end with a space or punctuation
    if (inWord) {
        (*wordCount)++;
    }
}

void displayCounts(int wordCount, int lineCount) {
    printf("Wow! You have %d words and %d lines!\n", wordCount, lineCount);
    printf("That's quite a lot of content! Keep it coming!\n");
}

int main() {
    char *filename;
    FILE *file;
    char buffer[MAX_LENGTH];
    int totalWordCount = 0, totalLineCount = 0;

    printf("Surprise! Let's count words in a text file!\n");
    
    // Get filename from user
    filename = (char *)malloc(100 * sizeof(char));
    if (!filename) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    printf("Please enter the filename (with .txt extension): ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        free(filename);
        return 1;
    }

    // Read the file line by line and count words
    while (fgets(buffer, MAX_LENGTH, file) != NULL) {
        int wordCount = 0, lineCount = 0;
        countWords(buffer, &wordCount, &lineCount);
        totalWordCount += wordCount;
        totalLineCount += lineCount;
    }

    // Close the file
    fclose(file);
    free(filename);

    // Display total counts
    displayCounts(totalWordCount, totalLineCount);

    return 0;
}