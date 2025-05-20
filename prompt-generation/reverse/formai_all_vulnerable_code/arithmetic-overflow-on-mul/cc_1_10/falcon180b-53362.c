//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char *sentiment;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Positive", 1},
    {"Negative", -1},
    {"Happy", 1},
    {"Sad", -1},
    {"Angry", -1},
    {"Neutral", 0}
};

void tokenize(char *sentence, char **tokens) {
    int i = 0;
    char *token = strtok(sentence, ",.!?;:\"'");

    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.!?;:\"'");
    }

    tokens[i] = NULL;
}

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void countWordFrequencies(char **tokens, int numTokens, WordFrequency *wordFrequencies) {
    for (int i = 0; i < numTokens; i++) {
        char *token = tokens[i];
        token = tolower(token);

        for (int j = 0; j < NUM_SENTIMENTS; j++) {
            if (strcmp(token, sentiments[j].sentiment) == 0) {
                wordFrequencies[j].frequency++;
                break;
            }
        }
    }
}

double calculateSentimentScore(WordFrequency *wordFrequencies) {
    double score = 0.0;

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        score += wordFrequencies[i].frequency * sentiments[i].value;
    }

    return score;
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    char *tokens[MAX_SENTENCE_LENGTH];
    WordFrequency wordFrequencies[NUM_SENTIMENTS];
    Sentiment sentiment;

    printf("Enter a sentence: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);

    tokenize(input, tokens);
    countWordFrequencies(tokens, strlen(input), wordFrequencies);

    sentiment.sentiment = "Neutral";
    sentiment.value = 0;

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            sentiment.sentiment = sentiments[i].sentiment;
            sentiment.value = sentiments[i].value;
            break;
        }
    }

    printf("Sentiment: %s\n", sentiment.sentiment);
    printf("Score: %.2f\n", calculateSentimentScore(wordFrequencies));

    return 0;
}