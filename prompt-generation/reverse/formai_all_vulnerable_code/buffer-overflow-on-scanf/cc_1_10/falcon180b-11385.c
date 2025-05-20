//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE* file, WordFrequency words[], int* numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }

    *numWords = i;
}

void printWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file;
    char filename[100];
    WordFrequency words[MAX_WORDS];
    int numWords;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readWords(file, words, &numWords);
    fclose(file);

    printf("Enter minimum frequency: ");
    int minFreq;
    scanf("%d", &minFreq);

    int count = 0;
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency >= minFreq) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
            count++;
        }
    }

    if (count == 0) {
        printf("No words found with frequency >= %d.\n", minFreq);
    }

    return 0;
}