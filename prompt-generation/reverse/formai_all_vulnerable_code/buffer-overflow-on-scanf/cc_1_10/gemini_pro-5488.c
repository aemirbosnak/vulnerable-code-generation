//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    // Positive words
    [0] = 1, // "good"
    [1] = 1, // "great"
    [2] = 1, // "excellent"
    [3] = 1, // "awesome"
    [4] = 1, // "superb"

    // Negative words
    [5] = -1, // "bad"
    [6] = -1, // "terrible"
    [7] = -1, // "horrible"
    [8] = -1, // "awful"
    [9] = -1, // "dreadful"
};

// Define the number of words in the sentiment dictionary
int num_words = sizeof(sentiment_scores) / sizeof(int);

// Function to analyze the sentiment of a given text
int analyze_sentiment(char *text) {
    // Tokenize the text into words
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_tokens; i++) {
        // Find the index of the word in the sentiment dictionary
        int index = -1;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], sentiment_scores[j]) == 0) {
                index = j;
                break;
            }
        }

        // If the word is found in the dictionary, add its sentiment score to the total
        if (index != -1) {
            sentiment_score += sentiment_scores[index];
        }
    }

    // Return the sentiment score
    return sentiment_score;
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter a text: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}