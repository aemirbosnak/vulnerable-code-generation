//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *inputFile = NULL;
    char inputFileName[100];
    char line[1000];
    int lineNumber = 0;
    int wordCount = 0;
    WordFrequency words[MAX_WORDS];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", inputFileName);
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        lineNumber++;

        // Convert line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Count words in line
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int wordLength = strlen(word);
            if (wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }
            strncpy(words[wordCount].word, word, wordLength);
            words[wordCount].count = 1;
            wordCount++;
            word = strtok(NULL, " ");
        }
    }

    // Print word frequency table
    printf("Line Number\tWord\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d\t%s\t%d\n", lineNumber, words[i].word, words[i].count);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}