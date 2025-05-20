//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void loveMessage() {
    printf("Welcome to the Romantic Word Frequency Counter!\n");
    printf("Let us count the tender words of love you express.\n");
    printf("Please type your poetic heart out and end your input with EOF (Ctrl+D).\n");
}

void addWordFrequency(WordFrequency *wordFrequencies, int *uniqueCount, const char *word) {
    for (int i = 0; i < *uniqueCount; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            wordFrequencies[i].count++;
            return;
        }
    }
    strcpy(wordFrequencies[*uniqueCount].word, word);
    wordFrequencies[*uniqueCount].count = 1;
    (*uniqueCount)++;
}

int compareFrequency(const void *a, const void *b) {
    return ((WordFrequency *)b)->count - ((WordFrequency *)a)->count;
}

void rippleOutput(WordFrequency *wordFrequencies, int uniqueCount) {
    printf("\nHere lies the beautiful frequency of your words of affection:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    loveMessage();

    WordFrequency wordFrequencies[MAX_WORD_COUNT];
    int uniqueCount = 0;

    char input[MAX_WORD_LENGTH];
    
    while (scanf("%s", input) != EOF) {
        addWordFrequency(wordFrequencies, &uniqueCount, input);
    }

    qsort(wordFrequencies, uniqueCount, sizeof(WordFrequency), compareFrequency);
    rippleOutput(wordFrequencies, uniqueCount);
    
    printf("\nLet the echoes of your sweet words linger in the air.\n");
    printf("May your love forever flourish, like the count of these cherished expressions.\n");

    return 0;
}