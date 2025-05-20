//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The lexicon of emotions
char *emotions[] = {
    "joy", "sadness", "anger", "fear", "surprise", "disgust"
};

// The function to analyze the sentiment of a string
int analyze_sentiment(char *string) {
    // Initialize the sentiment score
    int sentiment_score = 0;

    // Tokenize the string
    char *token = strtok(string, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Check if the token is an emotion
        for (int i = 0; i < 6; i++) {
            if (strcmp(token, emotions[i]) == 0) {
                // Increment the sentiment score based on the emotion
                if (i < 3) {
                    sentiment_score++;
                } else {
                    sentiment_score--;
                }
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment_score;
}

// The main function
int main() {
    // Get the input string
    char *string = malloc(100);
    printf("Enter a string: ");
    scanf("%s", string);

    // Analyze the sentiment of the string
    int sentiment_score = analyze_sentiment(string);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment_score);

    // Free the allocated memory
    free(string);

    return 0;
}