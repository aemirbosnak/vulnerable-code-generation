//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *name;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS];

void loadSentiments() {
    FILE *file = fopen(SENTIMENT_FILE, "r");

    if (file == NULL) {
        printf("Error loading sentiments file.\n");
        exit(1);
    }

    char line[MAX_SENTENCE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_SENTENCE_LENGTH, file)!= NULL) {
        char *sentimentName = strtok(line, ",");
        int sentimentScore = atoi(strtok(NULL, ","));

        sentiments[i].name = sentimentName;
        sentiments[i].score = sentimentScore;

        i++;
    }

    fclose(file);
}

int analyzeSentence(char *sentence) {
    int totalScore = 0;

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        Sentiment sentiment = sentiments[i];

        char *tokenizedSentence = strtok(sentence, " ");

        while (tokenizedSentence!= NULL) {
            if (strcasecmp(tokenizedSentence, sentiment.name) == 0) {
                totalScore += sentiment.score;
            }

            tokenizedSentence = strtok(NULL, " ");
        }
    }

    return totalScore;
}

int main() {
    loadSentiments();

    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to analyze:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int score = analyzeSentence(sentence);

    if (score > 0) {
        printf("Positive sentence.\n");
    } else if (score < 0) {
        printf("Negative sentence.\n");
    } else {
        printf("Neutral sentence.\n");
    }

    return 0;
}