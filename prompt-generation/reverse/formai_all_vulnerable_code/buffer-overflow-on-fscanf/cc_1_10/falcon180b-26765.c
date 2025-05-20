//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *inputFile;
    char inputString[MAX_WORD_LENGTH];
    char *token;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read input file and count word frequencies
    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        token = strtok(inputString, ",.?!;:");
        while (token!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
                if (numWords == MAX_WORDS) {
                    printf("Warning: Maximum number of words (%d) reached.\n", MAX_WORDS);
                    break;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Print word frequencies
    printf("Word frequencies:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}