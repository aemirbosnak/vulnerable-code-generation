//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // Max length of a word
#define MAX_WORDS 100 // Max number of words in a file

// Struct for a Word
typedef struct Word {
    char *text;
    int lineNo;
} Word;

int main() {
    FILE *file;
    char fileName[MAX_WORD_LENGTH];
    char buffer[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int wordCount = 0;
    int lineCount = 1;

    printf("Enter the name of file to check: ");
    scanf("%s", fileName);

    // Open the file
    file = fopen(fileName, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    // Loop through each line in the file
    while(fgets(buffer, MAX_WORD_LENGTH, file)) {
        char *p = buffer;

        // Remove trailing \n
        if (p[strlen(p) - 1] == '\n') {
            p[strlen(p) - 1] = '\0';
        }

        // Loop through each word in the line
        while(*p) {
            // Skip whitespace
            while(isspace(*p)) p++;

            // Check for end of line
            if (*p == '\n') break;

            // Save start of word
            char *start = p;

            // Find end of word
            while(isalpha(*p)) p++;

            // Save end of word
            char *end = p;

            // Check if we found a word
            if (start != end) {
                // Allocate memory for the word
                char *word = malloc(end - start + 1);
                strncpy(word, start, end - start);
                word[end - start] = '\0';

                // Save word and line number
                words[wordCount].text = word;
                words[wordCount].lineNo = lineCount;
                wordCount++;
            }
        }

        // Increment line count
        lineCount++;
    }

    // Print out all the words and their line numbers
    for (int i = 0; i < wordCount; i++) {
        printf("%s (line %d)\n", words[i].text, words[i].lineNo);
    }

    // Close the file
    fclose(file);

    return 0;
}