//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int wordCounts[MAX_WORDS];
int totalWords;

void readWords(char* filename) {
    FILE* file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    char* token;
    int wordIndex = 0;

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        strcpy(words[wordIndex], word);
        wordIndex++;
    }

    fclose(file);
}

void countWords() {
    for (int i = 0; i < totalWords; i++) {
        wordCounts[i] = 0;
    }

    for (int i = 0; i < totalWords; i++) {
        for (int j = 0; j < totalWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCounts[i]++;
            }
        }
    }
}

void printResults() {
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i], wordCounts[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    readWords(argv[1]);
    totalWords = strlen(argv[1]) / 10;

    countWords();
    printResults();

    return 0;
}