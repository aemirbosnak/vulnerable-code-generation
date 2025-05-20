//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    int i, j, k;
    FILE *inputFile;
    char word[MAX_WORD_LENGTH];
    char *token;
    int wordCount = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        for (j = 0; j < numWords; j++) {
            if (strcmp(word, input[j]) == 0) {
                wordFrequencies[j].frequency++;
                break;
            }
        }

        if (j == numWords) {
            strcpy(input[numWords], word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            fclose(inputFile);
            exit(1);
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Spam words:\n");
    for (i = 0; i < numWords; i++) {
        if (wordFrequencies[i].frequency >= 3) {
            printf("%s\n", wordFrequencies[i].word);
        }
    }

    return 0;
}