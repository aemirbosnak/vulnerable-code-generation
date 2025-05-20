//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char** argv) {
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency words[MAX_NUM_WORDS];
    memset(words, 0, sizeof(WordFrequency) * MAX_NUM_WORDS);

    while (fscanf(inputFile, "%s", buffer)!= EOF) {
        int wordLength = strlen(buffer);
        if (wordLength >= MIN_WORD_LENGTH) {
            char* wordCopy = strdup(buffer);
            for (int i = 0; i < wordLength; i++) {
                wordCopy[i] = tolower(wordCopy[i]);
            }
            int wordIndex = 0;
            while (wordIndex < numWords && strcmp(words[wordIndex].word, wordCopy)!= 0) {
                wordIndex++;
            }
            if (wordIndex == numWords) {
                if (numWords == MAX_NUM_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    fclose(inputFile);
                    return 1;
                }
                strcpy(words[numWords].word, wordCopy);
                words[numWords].frequency = 1;
                numWords++;
            } else {
                words[wordIndex].frequency++;
            }
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    fclose(inputFile);
    return 0;
}