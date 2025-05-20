//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to analyze the sentiment of a given text
int analyze_sentiment(char *text) {
    // Initialize the sentiment score
    int sentiment_score = 0;

    // Create an array of positive and negative words
    char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "disgusting"};

    // Tokenize the text
    char *tokens = strtok(text, " ");

    // Loop through the tokens and update the sentiment score
    while (tokens != NULL) {
        // Check if the token is a positive word
        for (int i = 0; i < 5; i++) {
            if (strcmp(tokens, positive_words[i]) == 0) {
                sentiment_score++;
                break;
            }
        }

        // Check if the token is a negative word
        for (int i = 0; i < 5; i++) {
            if (strcmp(tokens, negative_words[i]) == 0) {
                sentiment_score--;
                break;
            }
        }

        // Move to the next token
        tokens = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment_score;
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text: ");
    gets(text);

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Return 0 to indicate successful execution
    return 0;
}