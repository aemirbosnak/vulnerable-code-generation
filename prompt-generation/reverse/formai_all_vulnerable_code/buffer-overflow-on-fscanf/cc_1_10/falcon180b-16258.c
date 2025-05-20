//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE* file, WordCount* wordCounts, int numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) { // new word
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }
}

void writeWords(FILE* file, WordCount* wordCounts, int numWords) {
    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords = 0;
    readWords(file, wordCounts, numWords);
    fclose(file);
    printf("Total words: %d\n", numWords);
    writeWords(stdout, wordCounts, numWords);
    return 0;
}