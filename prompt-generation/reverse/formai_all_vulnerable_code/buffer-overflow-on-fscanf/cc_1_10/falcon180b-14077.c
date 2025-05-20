//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*) a;
    WordFrequency* wordB = (WordFrequency*) b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE* file, WordFrequency* words, int* numWords) {
    char word[MAX_WORD_LENGTH];
    int wordLength;

    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);

        // Convert word to lowercase
        for (int i = 0; i < wordLength; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is already in the array
        int index = 0;
        while (index < *numWords && strcmp(words[index].word, word)!= 0) {
            index++;
        }

        // If word is not in the array, add it
        if (index == *numWords) {
            if (*numWords >= MAX_WORDS) {
                printf("Error: maximum number of words reached\n");
                exit(1);
            }
            strcpy(words[*numWords].word, word);
            (*numWords)++;
        } else {
            // If word is already in the array, increment its frequency
            words[index].frequency++;
        }
    }
}

void sortWords(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readFile(file, words, &numWords);
    sortWords(words, numWords);
    printWords(words, numWords);

    fclose(file);
    return 0;
}