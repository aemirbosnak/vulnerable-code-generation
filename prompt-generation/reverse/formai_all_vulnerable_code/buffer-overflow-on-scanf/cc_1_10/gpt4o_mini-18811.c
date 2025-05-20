//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printTitle() {
    printf("=======================================\n");
    printf("    WELCOME TO WORD COUNT TOOL\n");
    printf("=======================================\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the name of the text file to analyze.\n");
    printf("2. The tool will output the word count, line count, and character count.\n");
    printf("=======================================\n");
}

int countWords(const char *filename, int *lineCount, int *charCount) {
    FILE *file;
    char ch;
    int inWord = 0, wordCount = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    while ((ch = fgetc(file)) != EOF) {
        (*charCount)++;
        if (ch == '\n') {
            (*lineCount)++;
        }
        if (isspace(ch)) {
            inWord = 0; // end of a word
        } else {
            if (inWord == 0) {
                wordCount++;
                inWord = 1; // start of a new word
            }
        }
    }

    // To count the last line if it doesn't end with a newline
    if (*charCount > 0 && ch != '\n') {
        (*lineCount)++; 
    }

    fclose(file);
    return wordCount;
}

int main() {
    char filename[100];
    int lineCount = 0, wordCount = 0, charCount = 0;

    printTitle();
    printInstructions();

    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    wordCount = countWords(filename, &lineCount, &charCount);
    
    if (wordCount >= 0) {
        printf("\n=======================================\n");
        printf("Results of '%s':\n", filename);
        printf("Total Lines: %d\n", lineCount);
        printf("Total Words: %d\n", wordCount);
        printf("Total Characters: %d\n", charCount);
        printf("=======================================\n");
    }

    return 0;
}