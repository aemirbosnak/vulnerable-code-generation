//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == *numWords) {
            strcpy(words[*numWords].word, word);
            words[*numWords].frequency = 1;
            (*numWords)++;
        }
    }

    fclose(file);
}

void sortWords(WordFrequency* words, int numWords) {
    int i, j;
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printTopWords(WordFrequency* words, int numWords, int numTopWords) {
    printf("Top %d most frequent words:\n", numTopWords);
    for (int i = 0; i < numTopWords && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, &numWords);

    sortWords(words, numWords);

    int numTopWords;
    printf("Enter the number of top words to print: ");
    scanf("%d", &numTopWords);

    printTopWords(words, numWords, numTopWords);

    return 0;
}