//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
    // Create an array of positive and negative words
    char *positive_words[] = {"good", "great", "awesome", "excellent", "superb"};
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "disgusting"};

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");

    // Loop through the words in the text
    while (token != NULL) {
        // Check if the word is a positive word
        for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment_score++;
                break;
            }
        }

        // Check if the word is a negative word
        for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                sentiment_score--;
                break;
            }
        }

        // Get the next word in the text
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment_score;
}

// Main function
int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text you want to analyze: ");
    gets(text);

    // Perform sentiment analysis on the text
    int sentiment_score = sentiment_analysis(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}