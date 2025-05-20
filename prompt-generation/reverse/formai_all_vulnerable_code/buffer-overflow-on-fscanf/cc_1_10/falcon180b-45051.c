//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", buffer)!= EOF) {
        char* word = strtok(buffer, " \t\n\r\f\v.,;:!?()[]{}<>");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORD_LENGTH && word[i]!= '\0'; i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int wordIndex = 0;
            while (wordIndex < numWords && strcmp(words[wordIndex].word, word)!= 0) {
                wordIndex++;
            }
            if (wordIndex == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[numWords].word, word);
                words[numWords].frequency = 1;
                numWords++;
            } else {
                words[wordIndex].frequency++;
            }
            word = strtok(NULL, " \t\n\r\f\v.,;:!?()[]{}<>");
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}