//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
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
    char inputBuffer[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount wordList[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Read input file and count words
    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        strcpy(word, inputBuffer);
        wordCount++;
    }
    fclose(inputFile);

    // Sort words alphabetically
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(wordList[i].word, wordList[j].word) > 0) {
                WordCount temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }

    // Print sorted word list
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}