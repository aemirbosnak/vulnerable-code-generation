//Falcon-180B DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    memset(wordFrequencies, 0, sizeof(WordFrequency) * MAX_WORDS);

    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Maximum number of words reached\n");
            break;
        }
    }

    fclose(file);
}

void sortWords(WordFrequency* wordFrequencies) {
    int i, j;
    char temp[MAX_WORD_LENGTH];

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = 0; j < MAX_WORDS - i - 1; j++) {
            if (wordFrequencies[j].frequency < wordFrequencies[j + 1].frequency) {
                strcpy(temp, wordFrequencies[j].word);
                strcpy(wordFrequencies[j].word, wordFrequencies[j + 1].word);
                strcpy(wordFrequencies[j + 1].word, temp);
                wordFrequencies[j].frequency ^= wordFrequencies[j + 1].frequency;
                wordFrequencies[j + 1].frequency ^= wordFrequencies[j].frequency;
                wordFrequencies[j].frequency ^= wordFrequencies[j + 1].frequency;
            }
        }
    }
}

void printWords(WordFrequency* wordFrequencies) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    WordFrequency wordFrequencies[MAX_WORDS];

    readWords(argv[1], wordFrequencies);
    sortWords(wordFrequencies);
    printWords(wordFrequencies);

    return 0;
}