//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define sentiment score constants
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// Function to get sentiment score based on keywords
int get_sentiment_score(char *text) {
    int score = 0;

    // Define positive and negative keywords
    char *positive_keywords[] = {"happy", "good", "excited", "love"};
    char *negative_keywords[] = {"sad", "bad", "angry", "hate"};

    // Check for positive keywords in text
    for(int i = 0; i < sizeof(positive_keywords) / sizeof(positive_keywords[0]); i++) {
        if(strstr(text, positive_keywords[i])) {
            score += POSITIVE;
        }
    }

    // Check for negative keywords in text
    for(int j = 0; j < sizeof(negative_keywords) / sizeof(negative_keywords[0]); j++) {
        if(strstr(text, negative_keywords[j])) {
            score += NEGATIVE;
        }
    }

    // Return sentiment score based on keyword occurrences
    if(score > 0) {
        return POSITIVE;
    } else if(score < 0) {
        return NEGATIVE;
    } else {
        return NEUTRAL;
    }
}

int main() {
    char text[100];

    // Get user input
    printf("Enter text for sentiment analysis: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input
    int len = strlen(text);
    if(text[len-1] == '\n') {
        text[len-1] = '\0';
    }

    // Get sentiment score and output result
    int sentiment = get_sentiment_score(text);
    if(sentiment == POSITIVE) {
        printf("\nSentiment analysis result: Positive");
    } else if(sentiment == NEGATIVE) {
        printf("\nSentiment analysis result: Negative");
    } else {
        printf("\nSentiment analysis result: Neutral");
    }

    return 0;
}