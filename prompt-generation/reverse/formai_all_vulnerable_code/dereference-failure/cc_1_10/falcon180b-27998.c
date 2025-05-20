//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    WordFrequency* words;
    int numWords;
} Sentiment;

void initializeSentiment(Sentiment* sentiment) {
    sentiment->words = (WordFrequency*) malloc(sizeof(WordFrequency) * MAX_WORD_LENGTH);
    sentiment->numWords = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        sentiment->words[i].count = 0;
    }
}

void freeSentiment(Sentiment* sentiment) {
    free(sentiment->words);
}

void addWord(Sentiment* sentiment, const char* word) {
    for (int i = 0; i < sentiment->numWords; i++) {
        if (strcmp(sentiment->words[i].word, word) == 0) {
            sentiment->words[i].count++;
            return;
        }
    }
    if (sentiment->numWords >= MAX_WORD_LENGTH) {
        return;
    }
    strcpy(sentiment->words[sentiment->numWords].word, word);
    sentiment->words[sentiment->numWords].count = 1;
    sentiment->numWords++;
}

void printSentiment(Sentiment* sentiment) {
    for (int i = 0; i < sentiment->numWords; i++) {
        printf("%s: %d\n", sentiment->words[i].word, sentiment->words[i].count);
    }
}

int main() {
    Sentiment sentiment;
    initializeSentiment(&sentiment);

    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        char* token = strtok(sentence, " ");
        while (token!= NULL) {
            addWord(&sentiment, token);
            token = strtok(NULL, " ");
        }
    }

    printSentiment(&sentiment);
    freeSentiment(&sentiment);

    return 0;
}