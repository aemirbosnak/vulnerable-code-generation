//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *sentiment_dict[] = {
    "positive", "good", "great", "excellent", "amazing",
    "negative", "bad", "terrible", "awful", "horrible"
};

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
    // Tokenize the text
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Count the positive and negative sentiment words
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < sizeof(sentiment_dict) / sizeof(char *); j++) {
            if (strcmp(tokens[i], sentiment_dict[j]) == 0) {
                if (j < 5) {
                    positive_count++;
                } else {
                    negative_count++;
                }
            }
        }
    }

    // Calculate the sentiment score
    int sentiment_score = positive_count - negative_count;

    // Return the sentiment score
    return sentiment_score;
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text: ");
    gets(text);

    // Perform sentiment analysis on the text
    int sentiment_score = sentiment_analysis(text);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Return 0
    return 0;
}