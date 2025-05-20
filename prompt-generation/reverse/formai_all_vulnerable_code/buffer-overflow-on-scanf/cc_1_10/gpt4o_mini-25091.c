//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define BUFFER_SIZE 1024

// Function prototypes
void countWordsInLine(const char *line, int *wordCount);
int isDelimiter(char ch);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    char buffer[BUFFER_SIZE];
    int totalWords = 0;

    // Artistic introductory message
    printf("***************************************\n");
    printf("*    Welcome to the C Word Count    *\n");
    printf("*           Tool - By Your Name      *\n");
    printf("***************************************\n");
    
    // Prompting user for the filename
    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Reading the file line by line
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        int wordCount = 0;
        countWordsInLine(buffer, &wordCount);
        totalWords += wordCount;
    }

    // Closing the file
    fclose(file);

    // Displaying total count of words
    printf("Total number of words in '%s': %d\n", filename, totalWords);
    return EXIT_SUCCESS;
}

// Function to count words in a single line
void countWordsInLine(const char *line, int *wordCount) {
    int inWord = 0;  // To track if we are inside a word
    const char *ptr = line;

    // Traverse each character in the line
    while (*ptr) {
        if (isDelimiter(*ptr)) {
            if (inWord) {
                (*wordCount)++;  // A complete word ended
                inWord = 0;      // Reset inWord flag
            }
        } else {
            inWord = 1;  // We are inside a word
        }
        ptr++;
    }

    // If the line ends with a word, count it
    if (inWord) {
        (*wordCount)++;
    }
}

// Function to check if a character is a word delimiter
int isDelimiter(char ch) {
    return isspace(ch) || ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}