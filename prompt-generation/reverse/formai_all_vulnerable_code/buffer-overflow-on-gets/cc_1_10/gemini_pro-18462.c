//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to store the sentiment analysis result
typedef struct {
    int positive;
    int negative;
    int neutral;
} sentiment_result;

// Define a function to perform sentiment analysis on a given string
sentiment_result analyze_sentiment(char *string) {
    // Create a sentiment result struct
    sentiment_result result;

    // Initialize the sentiment result struct
    result.positive = 0;
    result.negative = 0;
    result.neutral = 0;

    // Tokenize the string into words
    char *token = strtok(string, " ");

    // Iterate over the words in the string
    while (token != NULL) {
        // Check if the word is positive or negative
        if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "awesome") == 0) {
            result.positive++;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0) {
            result.negative++;
        } else {
            result.neutral++;
        }

        // Get the next word in the string
        token = strtok(NULL, " ");
    }

    // Return the sentiment result struct
    return result;
}

int main() {
    // Get the input string from the user
    char string[1024];
    printf("Enter a string: ");
    gets(string);

    // Perform sentiment analysis on the input string
    sentiment_result result = analyze_sentiment(string);

    // Print the sentiment result
    printf("Positive: %d\n", result.positive);
    printf("Negative: %d\n", result.negative);
    printf("Neutral: %d\n", result.neutral);

    return 0;
}