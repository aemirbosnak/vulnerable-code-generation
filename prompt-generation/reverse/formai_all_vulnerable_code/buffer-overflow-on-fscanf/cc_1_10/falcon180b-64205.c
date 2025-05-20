//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    FILE *inputFile;
    char inputString[MAX_WORD_LENGTH];
    char delimiters[] = ",.!?;:-_\"'";
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        int i;
        char *word = strtok(inputString, delimiters);

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }

                words[numWords].word = strdup(word);
                words[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, delimiters);
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}