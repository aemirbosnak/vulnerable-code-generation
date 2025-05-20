//Falcon-180B DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main() {
    FILE *file;
    char ch;
    int inWord = 0;
    char word[MAX_WORD_LENGTH] = "";
    int numWords = 0;
    WordFrequency wordFrequency[MAX_WORDS];

    srand(time(NULL));

    file = fopen("romeo_and_juliet.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            inWord = 1;
            strncat(word, &ch, 1);
        } else {
            inWord = 0;
            if (strlen(word) > 0) {
                numWords++;

                if (numWords >= MAX_WORDS) {
                    break;
                }

                strcpy(wordFrequency[numWords - 1].word, word);
                wordFrequency[numWords - 1].frequency = 1;
                word[0] = '\0';
            }
        }
    }

    if (inWord) {
        strcpy(wordFrequency[numWords - 1].word, word);
        wordFrequency[numWords - 1].frequency = 1;
        numWords++;
    }

    fclose(file);

    printWordFrequency(wordFrequency, numWords);

    return 0;
}