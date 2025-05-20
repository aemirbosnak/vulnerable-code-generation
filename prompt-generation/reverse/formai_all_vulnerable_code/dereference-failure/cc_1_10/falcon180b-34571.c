//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Joy", 1},
    {"Sadness", -1},
    {"Anger", -1},
    {"Fear", -1},
    {"Surprise", 1},
    {"Disgust", -1}
};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(char *sentence) {
    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        return -1;
    }

    int sentiment_score = 0;
    char *token;
    token = strtok(sentence, " ");
    while (token!= NULL) {
        int sentiment_index = get_sentiment_index(token);
        if (sentiment_index!= -1) {
            sentiment_score += sentiments[sentiment_index].value;
        }
        token = strtok(NULL, " ");
    }

    return sentiment_score;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char *sentence = argv[1];
    int sentiment_score = analyze_sentiment(sentence);

    if (sentiment_score == -1) {
        printf("Sentence is too long.\n");
    } else {
        printf("Sentiment score: %d\n", sentiment_score);
    }

    return 0;
}