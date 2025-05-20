//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT_SCORE 10

typedef struct {
    char *text;
    int sentiment_score;
} SentimentAnalysisResult;

SentimentAnalysisResult analyze_sentiment(char *text) {
    SentimentAnalysisResult result;

    // Initialize the result
    result.text = text;
    result.sentiment_score = 0;

    // Analyze the sentiment of the text
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];

        // Check if the character is a positive word
        if (strcmp(c, "good") == 0 || strcmp(c, "great") == 0 || strcmp(c, "awesome") == 0) {
            result.sentiment_score++;
        }
        // Check if the character is a negative word
        else if (strcmp(c, "bad") == 0 || strcmp(c, "terrible") == 0 || strcmp(c, "awful") == 0) {
            result.sentiment_score--;
        }
    }

    // Return the result
    return result;
}

int main() {
    // Get the text from the user
    char *text = malloc(100);
    printf("Enter the text you want to analyze: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    SentimentAnalysisResult result = analyze_sentiment(text);

    // Print the result
    printf("The sentiment score for the text is: %d\n", result.sentiment_score);

    // Free the memory allocated for the text
    free(text);

    return 0;
}