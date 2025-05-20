//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;
    
    if(wordA->frequency > wordB->frequency) {
        return -1;
    } else if(wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if(inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordLength;
    int numWords = 0;
    WordFrequency* words = malloc(MAX_WORDS * sizeof(WordFrequency));

    // Read words from input file
    while(fscanf(inputFile, "%s", word)!= EOF) {
        wordLength = strlen(word);
        if(wordLength > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        WordFrequency* foundWord = NULL;
        for(int i = 0; i < numWords; i++) {
            if(strcmp(words[i].word, word) == 0) {
                foundWord = &words[i];
                break;
            }
        }

        if(foundWord == NULL) {
            if(numWords >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }
            strcpy(foundWord->word, word);
            foundWord->frequency = 1;
            numWords++;
        } else {
            foundWord->frequency++;
        }
    }

    fclose(inputFile);

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequencies
    printf("Word\tFrequency\n");
    for(int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    free(words);

    return 0;
}