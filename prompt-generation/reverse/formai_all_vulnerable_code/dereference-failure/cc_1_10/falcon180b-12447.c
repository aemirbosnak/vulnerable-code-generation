//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char* keyword;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"confused", 0}
};

int analyzeSentiment(char* sentence) {
    int score = 0;
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        char* keyword = sentiments[i].keyword;
        int keywordLength = strlen(keyword);

        while ((sentence = strstr(sentence, keyword))) {
            score += sentiments[i].score;
            sentence += keywordLength;
        }
    }

    return score;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char* sentence = argv[1];
    int sentenceLength = strlen(sentence);

    if (sentenceLength > MAX_SENTENCE_LENGTH) {
        printf("Sentence is too long.\n");
        return 1;
    }

    int score = analyzeSentiment(sentence);

    if (score > 0) {
        printf("The sentiment is positive.\n");
    } else if (score < 0) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }

    return 0;
}