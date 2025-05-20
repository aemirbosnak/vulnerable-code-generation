//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define NUM_SENTIMENTS 4

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    char sentiment[MAX_WORD_LENGTH];
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"happy", 1}, {"sad", -1}, {"angry", -1}, {"neutral", 0}};

void initializeSentimentAnalysis(void) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        sentiments[i].value = 0;
    }
}

void analyzeSentiment(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        bool found = false;
        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(word, sentiments[i].sentiment) == 0) {
                sentiments[i].value++;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < NUM_SENTIMENTS; i++) {
                if (sentiments[i].value == 0) {
                    strcpy(sentiments[i].sentiment, word);
                    sentiments[i].value++;
                    break;
                }
            }
        }
        word = strtok(NULL, " ");
    }
}

void printSentimentAnalysis(void) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, sentiments[i].value);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    initializeSentimentAnalysis();
    analyzeSentiment(sentence);
    printSentimentAnalysis();

    return 0;
}