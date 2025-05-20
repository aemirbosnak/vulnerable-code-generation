//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentiment analysis engine
typedef struct {
    int positive;
    int negative;
    int neutral;
} Sentiment;

// Initialize sentiment engine
Sentiment sentiment_init() {
    Sentiment sentiment;
    sentiment.positive = 0;
    sentiment.negative = 0;
    sentiment.neutral = 0;
    return sentiment;
}

// Analyze sentiment of a string
Sentiment sentiment_analyze(char *string) {
    Sentiment sentiment = sentiment_init();

    // Tokenize string into words
    char *tokens[100];
    int token_count = 0;
    char *token = strtok(string, " ");
    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " ");
    }

    // Analyze each word
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i], "good") == 0 || strcmp(tokens[i], "great") == 0 || strcmp(tokens[i], "awesome") == 0) {
            sentiment.positive++;
        } else if (strcmp(tokens[i], "bad") == 0 || strcmp(tokens[i], "terrible") == 0 || strcmp(tokens[i], "awful") == 0) {
            sentiment.negative++;
        } else {
            sentiment.neutral++;
        }
    }

    return sentiment;
}

// Print sentiment analysis results
void sentiment_print(Sentiment sentiment) {
    printf("Positive: %d\n", sentiment.positive);
    printf("Negative: %d\n", sentiment.negative);
    printf("Neutral: %d\n", sentiment.neutral);
}

// Main program
int main() {
    // Get input string from user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Analyze sentiment of input string
    Sentiment sentiment = sentiment_analyze(input);

    // Print sentiment analysis results
    sentiment_print(sentiment);

    return 0;
}