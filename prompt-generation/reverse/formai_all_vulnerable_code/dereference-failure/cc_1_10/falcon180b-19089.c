//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char *word;
    WordFrequency *wordFrequencyTable = (WordFrequency *)malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        numWords = 0;
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                break;
            }
            strcpy(wordFrequencyTable[numWords].word, word);
            wordFrequencyTable[numWords].count = 1;
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].count);
    }

    free(wordFrequencyTable);
    return 0;
}