//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount *wordCounts) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]); // Convert to lowercase
        }
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                break;
            }
        }
        if (j == MAX_WORDS) {
            strcpy(wordCounts[j].word, word);
            wordCounts[j].count = 1;
        }
    }
}

void writeWords(FILE *file, WordCount *wordCounts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            fprintf(file, "%s %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    WordCount wordCounts[MAX_WORDS];
    readWords(inputFile, wordCounts);
    writeWords(outputFile, wordCounts);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}