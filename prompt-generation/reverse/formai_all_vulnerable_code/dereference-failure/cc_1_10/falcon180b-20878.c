//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 4

// Sentiment labels
char *sentiments[NUM_SENTIMENTS] = {"Positive", "Negative", "Neutral", "Mixed"};

struct SentimentAnalysisResult {
    char *text;
    int sentimentIndex;
};

int getSentimentIndex(char *sentiment) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment, sentiments[i]) == 0) {
            return i;
        }
    }
    return -1; // Sentiment not found
}

char *preprocessText(char *text) {
    int length = strlen(text);
    char *preprocessedText = malloc(length + 1);
    int j = 0;

    // Remove punctuation and convert to lowercase
    for (int i = 0; i < length; i++) {
        if (!ispunct(text[i])) {
            preprocessedText[j++] = tolower(text[i]);
        }
    }
    preprocessedText[j] = '\0';

    return preprocessedText;
}

int main() {
    char inputText[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to analyze: ");
    fgets(inputText, MAX_SENTENCE_LENGTH, stdin);

    // Remove newline character from input
    inputText[strcspn(inputText, "\n")] = '\0';

    char *preprocessedText = preprocessText(inputText);
    int sentimentIndex = getSentimentIndex(preprocessedText);

    printf("Sentiment analysis result: %s (%d)\n", preprocessedText, sentimentIndex);

    return 0;
}