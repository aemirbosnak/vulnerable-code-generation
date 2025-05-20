//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void addWord(WordFrequency* wordFrequency, char* word) {
    int i;
    for (i = 0; i < wordFrequency->count; i++) {
        if (strcmp(wordFrequency[i].word, word) == 0) {
            wordFrequency[i].count++;
            return;
        }
    }
    if (wordFrequency->count >= MAX_WORDS) {
        printf("Error: Reached maximum number of words.\n");
        exit(1);
    }
    strcpy(wordFrequency[wordFrequency->count].word, word);
    wordFrequency[wordFrequency->count].count = 1;
    wordFrequency->count++;
}

void printWordFrequency(WordFrequency* wordFrequency) {
    int i;
    for (i = 0; i < wordFrequency->count; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }
}

int main() {
    WordFrequency wordFrequency = {0};
    char word[MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH];
    int wordLength;

    printf("Enter words to count their frequency:\n");
    while (scanf("%s", input)!= EOF) {
        wordLength = strlen(input);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
        strcpy(word, input);
        addWord(&wordFrequency, word);
    }

    printWordFrequency(&wordFrequency);

    return 0;
}