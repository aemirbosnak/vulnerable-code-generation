//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readResume(char* filename, char resumeText[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(resumeText[wordCount], word);
        wordCount++;
    }
    fclose(file);
}

void countWords(char resumeText[MAX_WORDS][MAX_WORD_LENGTH], WordFrequency frequencies[MAX_WORDS]) {
    int wordCount = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (resumeText[i][0]!= '\0') {
            frequencies[i].word[0] = tolower(resumeText[i][0]);
            frequencies[i].count = 1;
            wordCount++;
        }
    }
}

void printFrequencies(WordFrequency frequencies[MAX_WORDS], int numWords) {
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        if (frequencies[i].count > 0) {
            printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
        }
    }
}

int main() {
    char resumeText[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];
    readResume("resume.txt", resumeText);
    countWords(resumeText, frequencies);
    printFrequencies(frequencies, MAX_WORDS);
    return 0;
}