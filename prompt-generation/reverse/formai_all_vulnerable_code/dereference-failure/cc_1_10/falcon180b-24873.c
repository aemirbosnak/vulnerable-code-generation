//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
    WordFrequency words[MAX_NUM_WORDS];
} Sentence;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void printFrequencyTable(WordFrequency *frequencyTable, int numWords) {
    qsort(frequencyTable, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", frequencyTable[i].word, frequencyTable[i].frequency);
    }
}

char *getWord(char *sentence, int *index) {
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int wordLength = 0;

    while (isalnum(sentence[*index])) {
        word[wordLength++] = tolower(sentence[*index]);
        (*index)++;
    }

    word[wordLength] = '\0';
    return word;
}

void analyzeSentence(char *sentence, WordFrequency *frequencyTable, int numWords) {
    int index = 0;
    char *word;

    while ((word = getWord(sentence, &index))!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, frequencyTable[i].word) == 0) {
                frequencyTable[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }

            strcpy(frequencyTable[numWords].word, word);
            frequencyTable[numWords].frequency = 1;
            numWords++;
        }

        free(word);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int numWords = 0;
    WordFrequency frequencyTable[MAX_NUM_WORDS];

    char *word = getWord(sentence, &numWords);
    while (word!= NULL) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        strcpy(frequencyTable[numWords].word, word);
        frequencyTable[numWords].frequency = 1;
        numWords++;

        free(word);
        word = getWord(sentence, &numWords);
    }

    analyzeSentence(sentence, frequencyTable, numWords);

    printFrequencyTable(frequencyTable, numWords);

    return 0;
}