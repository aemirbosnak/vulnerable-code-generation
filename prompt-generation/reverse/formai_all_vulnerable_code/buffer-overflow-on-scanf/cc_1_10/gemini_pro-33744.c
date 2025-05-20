//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentiment analysis tool

// Define the sentiment scores for each word
const int sentiment_scores[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 2,  // "great"
    [2] = 3,  // "excellent"
    [3] = 4,  // "amazing"
    [4] = 5,  // "awesome"

    // Negative words
    [5] = -1, // "bad"
    [6] = -2, // "terrible"
    [7] = -3, // "horrible"
    [8] = -4, // "awful"
    [9] = -5  // "dreadful"
};

// Calculate the sentiment score for a given text
int calculate_sentiment_score(char *text) {
    // Tokenize the text into words
    char *tokens[100];
    int num_tokens = tokenize(text, tokens, 100);

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_tokens; i++) {
        // Find the index of the word in the sentiment_scores array
        int index = -1;
        for (int j = 0; j < 10; j++) {
            if (strcmp(tokens[i], sentiment_scores[j]) == 0) {
                index = j;
                break;
            }
        }

        // If the word is not found, skip it
        if (index == -1) {
            continue;
        }

        // Add the sentiment score for the word to the total sentiment score
        sentiment_score += sentiment_scores[index];
    }

    // Return the total sentiment score
    return sentiment_score;
}

// Tokenize a string into an array of words
int tokenize(char *text, char *tokens[], int max_tokens) {
    // Create a temporary copy of the text
    char *text_copy = strdup(text);

    // Split the text into tokens using strtok
    char *token = strtok(text_copy, " ");
    int num_tokens = 0;
    while (token != NULL && num_tokens < max_tokens) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Free the temporary copy of the text
    free(text_copy);

    // Return the number of tokens
    return num_tokens;
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text to analyze: ");
    scanf("%s", text);

    // Calculate the sentiment score for the text
    int sentiment_score = calculate_sentiment_score(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}