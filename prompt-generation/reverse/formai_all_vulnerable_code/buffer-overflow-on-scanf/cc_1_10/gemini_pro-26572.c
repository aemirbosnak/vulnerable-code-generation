//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int sentimentScores[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 1,  // "great"
    [2] = 1,  // "excellent"
    [3] = 1,  // "amazing"
    [4] = 1,  // "wonderful"

    // Negative words
    [5] = -1, // "bad"
    [6] = -1, // "terrible"
    [7] = -1, // "awful"
    [8] = -1, // "horrible"
    [9] = -1, // "dreadful"
};

// Get the sentiment score for a given word
int getSentimentScore(const char *word) {
    // Linear search for the word in the sentimentScores array
    for (int i = 0; i < sizeof(sentimentScores) / sizeof(int); i++) {
        if (strcmp(word, sentimentScores[i]) == 0) {
            return sentimentScores[i];
        }
    }

    // Word not found in the sentimentScores array
    return 0;
}

// Analyze the sentiment of a given text
int analyzeSentiment(const char *text) {
    // Tokenize the text into words
    char *words[100];
    int numWords = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word and sum them up
    int sentimentScore = 0;
    for (int i = 0; i < numWords; i++) {
        sentimentScore += getSentimentScore(words[i]);
    }

    return sentimentScore;
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text to analyze: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    int sentimentScore = analyzeSentiment(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentimentScore);

    return 0;
}