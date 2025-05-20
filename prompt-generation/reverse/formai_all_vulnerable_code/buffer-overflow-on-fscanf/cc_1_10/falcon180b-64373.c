//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = a;
    const WordFrequency* wordB = b;
    
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char* argv[]) {
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    
    char word[MAX_WORD_LENGTH + 1];
    int numWords = 0;
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: reached maximum number of words.\n");
            fclose(inputFile);
            return 2;
        }
        
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
        
        if (i == numWords) {
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }
    }
    
    fclose(inputFile);
    
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
    
    return 0;
}