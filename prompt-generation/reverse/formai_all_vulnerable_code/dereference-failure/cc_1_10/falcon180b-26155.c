//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *sentiment;
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

int analyze_sentiment(char *sentence) {
    int i, j, score = 0;
    int length = strlen(sentence);
    char *token;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        for (j = 0; j < length; j++) {
            if (sentence[j] == sentiments[i].sentiment[j]) {
                score += sentiments[i].score;
            }
        }
    }

    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_score = analyze_sentiment(sentence);

    if (sentiment_score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}