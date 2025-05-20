//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int length;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*) a;
    const Word* wordB = (const Word*) b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int numWords = 0;
    Word words[MAX_WORDS];
    char word[MAX_WORD_LENGTH + 1];

    // Read words from input file
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            fclose(inputFile);
            return 1;
        }

        words[numWords].length = strlen(word);
        strcpy(words[numWords].word, word);
        numWords++;
    }

    fclose(inputFile);

    // Sort words by length
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print sorted words
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}