//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("romeo_and_juliet.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int wordLength = strlen(line);

        for (int i = 0; i < wordLength; i++) {
            if (isalpha(line[i])) {
                strncat(word, &line[i], 1);
            } else {
                word[strlen(word) - 1] = '\0';

                for (int j = 0; j < strlen(word); j++) {
                    word[j] = tolower(word[j]);
                }

                int wordFound = 0;

                for (int k = 0; k < numWords; k++) {
                    if (strcmp(wordFrequencies[k].word, word) == 0) {
                        wordFrequencies[k].frequency++;
                        wordFound = 1;
                        break;
                    }
                }

                if (wordFound == 0) {
                    if (numWords >= MAX_WORDS) {
                        printf("Maximum number of words reached.\n");
                        break;
                    }

                    strcpy(wordFrequencies[numWords].word, word);
                    wordFrequencies[numWords].frequency = 1;
                    numWords++;
                }

                word[0] = '\0';
            }
        }
    }

    fclose(file);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}