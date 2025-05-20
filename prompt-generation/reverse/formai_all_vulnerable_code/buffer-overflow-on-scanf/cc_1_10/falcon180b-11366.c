//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// The structure to store word frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(char *filename, WordFrequency *wordFrequencies) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordIndex >= MAX_WORDS) {
            printf("Error: too many unique words in file.\n");
            exit(1);
        }

        strcpy(wordFrequencies[wordIndex].word, word);
        wordFrequencies[wordIndex].frequency = 1;
        wordIndex++;
    }

    fclose(file);
}

void printWordFrequencies(WordFrequency *wordFrequencies) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    char filename[100];
    WordFrequency wordFrequencies[MAX_WORDS];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    readWords(filename, wordFrequencies);

    qsort(wordFrequencies, MAX_WORDS, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    printWordFrequencies(wordFrequencies);

    return 0;
}