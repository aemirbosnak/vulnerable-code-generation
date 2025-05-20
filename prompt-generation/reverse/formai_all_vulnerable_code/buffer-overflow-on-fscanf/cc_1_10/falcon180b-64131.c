//Falcon-180B DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    char inputString[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read in words from the input file
    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        // Convert input string to lowercase
        for (i = 0; inputString[i]!= '\0'; i++) {
            inputString[i] = tolower(inputString[i]);
        }

        // Increment the count for the word in the wordCounts array
        for (i = 0; i < numWords; i++) {
            if (strcmp(inputString, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }

        // If the word is not found in the wordCounts array, add it
        if (i == numWords) {
            strcpy(wordCounts[numWords].word, inputString);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    // Close the input file
    fclose(inputFile);

    // Print out the word counts
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}