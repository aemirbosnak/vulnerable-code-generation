//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = -1,  // "bad"
    [1] = 1,   // "good"
    [2] = -2,  // "terrible"
    [3] = 2,   // "excellent"
    [4] = -3,  // "horrible"
    [5] = 3,   // "amazing"
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(sentiment_scores) / sizeof(int); i++) {
        if (strcmp(word, sentiment_scores[i]) == 0) {
            return sentiment_scores[i];
        }
    }

    return 0;  // Default score for unknown words
}

// Analyze the sentiment of a given text
int analyze_sentiment(char *text) {
    // Tokenize the text into words
    char *token = strtok(text, " ");

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Iterate over the words and add their sentiment scores
    while (token != NULL) {
        sentiment_score += get_sentiment_score(token);
        token = strtok(NULL, " ");
    }

    return sentiment_score;
}

int main() {
    // Get the text from the user
    char text[1024];
    printf("Enter your text: ");
    gets(text);

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}