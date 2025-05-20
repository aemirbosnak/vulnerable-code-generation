//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char *token;
    int wordCount = 0;
    WordFrequency words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        wordCount++;

        if (wordCount > MAX_WORDS) {
            printf("Error: maximum number of words exceeded.\n");
            exit(1);
        }

        token = strtok(inputBuffer, ",.!?;:");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: word length exceeded maximum limit.\n");
                exit(1);
            }

            strcpy(words[wordCount - 1].word, token);
            words[wordCount - 1].frequency++;

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(inputFile);

    qsort(words, wordCount, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}