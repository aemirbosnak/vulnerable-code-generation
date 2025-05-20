//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[WORD_LENGTH];
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

void printWords(WordFrequency* words, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, &numWords);

    sortWords(words, numWords);

    printf("Word frequencies:\n");
    printWords(words, numWords);

    return 0;
}