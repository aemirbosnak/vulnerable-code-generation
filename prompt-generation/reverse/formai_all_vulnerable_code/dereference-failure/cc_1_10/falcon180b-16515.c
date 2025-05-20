//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *sentiment;
    double weight;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1.0},
    {"sad", -1.0},
    {"angry", -1.0},
    {"excited", 1.0},
    {"bored", -1.0},
    {"confused", 0.0}
};

double calculateSentimentScore(char *text) {
    double score = 0.0;
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        int found = 0;
        char *token;
        char *pos = strtok_r(text, " ", &pos);

        while (pos!= NULL) {
            token = strtok_r(pos, " ", &pos);

            if (strcmp(token, sentiments[i].sentiment) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            score += sentiments[i].weight;
        }
    }

    return score;
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    double sentimentScore;

    printf("Enter a sentence: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    sentimentScore = calculateSentimentScore(text);

    if (sentimentScore > 0.0) {
        printf("The sentence expresses a positive sentiment.\n");
    } else if (sentimentScore < 0.0) {
        printf("The sentence expresses a negative sentiment.\n");
    } else {
        printf("The sentence expresses a neutral sentiment.\n");
    }

    return 0;
}