//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    int count;
    char word[MAX_WORD_LENGTH];
} WordCount;

void countWords(char* sentence, WordCount* wordCounts, int numWordCounts) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWordCounts; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWordCounts) {
            strcpy(wordCounts[numWordCounts - 1].word, word);
            wordCounts[numWordCounts - 1].count = 1;
            numWordCounts++;
        }
        word = strtok(NULL, " ");
    }
}

void printWordCounts(WordCount* wordCounts, int numWordCounts) {
    printf("Word Counts:\n");
    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* fp;
    char ch;
    char sentence[MAX_SENTENCE_LENGTH];
    int sentenceLength = 0;
    int numWordCounts = 0;
    WordCount* wordCounts = (WordCount*) malloc(10 * sizeof(WordCount));

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            sentence[sentenceLength++] = tolower(ch);
        } else if (isspace(ch)) {
            if (sentenceLength > 0) {
                sentence[sentenceLength] = '\0';
                countWords(sentence, wordCounts, numWordCounts);
                sentenceLength = 0;
            }
        } else {
            printf("Error: Invalid character encountered.\n");
            exit(1);
        }
    }

    if (sentenceLength > 0) {
        sentence[sentenceLength] = '\0';
        countWords(sentence, wordCounts, numWordCounts);
    }

    fclose(fp);
    printWordCounts(wordCounts, numWordCounts);

    free(wordCounts);
    return 0;
}