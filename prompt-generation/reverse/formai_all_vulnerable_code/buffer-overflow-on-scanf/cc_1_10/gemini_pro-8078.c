//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    // Positive words
    [0] = 1,
    [1] = 2,
    [2] = 3,
    // Negative words
    [3] = -1,
    [4] = -2,
    [5] = -3
};

// Define the list of positive and negative words
char *positive_words[] = {
    "good",
    "great",
    "excellent"
};

char *negative_words[] = {
    "bad",
    "terrible",
    "awful"
};

// Calculate the sentiment score for a given text
int calculate_sentiment(char *text) {
    // Initialize the sentiment score to 0
    int sentiment = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");

    // Iterate over the words in the text
    while (token != NULL) {
        // Find the index of the word in the list of positive words
        int positive_index = -1;
        for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_index = i;
                break;
            }
        }

        // Find the index of the word in the list of negative words
        int negative_index = -1;
        for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_index = i;
                break;
            }
        }

        // If the word is in the list of positive words, add its sentiment score to the total
        if (positive_index != -1) {
            sentiment += sentiment_scores[positive_index];
        }

        // If the word is in the list of negative words, add its sentiment score to the total
        else if (negative_index != -1) {
            sentiment += sentiment_scores[negative_index];
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment;
}

int main() {
    // Get the text to analyze from the user
    char text[1024];
    printf("Enter the text to analyze: ");
    scanf("%s", text);

    // Calculate the sentiment score for the text
    int sentiment = calculate_sentiment(text);

    // Print the sentiment score
    printf("The sentiment score for the text is: %d\n", sentiment);

    return 0;
}