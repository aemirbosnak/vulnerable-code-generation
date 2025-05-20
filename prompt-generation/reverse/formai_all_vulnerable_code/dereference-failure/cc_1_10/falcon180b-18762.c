//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

// Sentiment labels
char *sentiments[NUM_SENTIMENTS] = {"Positive", "Negative", "Neutral", "Happy", "Sad", "Angry"};

// Function to tokenize a sentence into words
void tokenize_sentence(char *sentence, char **tokens) {
    int i = 0;
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    tokens[i] = NULL;
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char *sentence) {
    int score = 0;
    char **tokens = malloc(MAX_SENTENCE_LENGTH * sizeof(char *));

    tokenize_sentence(sentence, tokens);

    for (int i = 0; tokens[i]!= NULL; i++) {
        for (int j = 0; j < NUM_SENTIMENTS; j++) {
            if (strcmp(tokens[i], sentiments[j]) == 0) {
                score += (j + 1);
                break;
            }
        }
    }

    free(tokens);

    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_score = calculate_sentiment_score(sentence);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}