//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>

// Define a struct to represent a sentiment
typedef struct {
    int positive;
    int negative;
} Sentiment;

// Function to calculate the sentiment of a string
Sentiment analyze_sentiment(char *string) {
    Sentiment sentiment;
    sentiment.positive = 0;
    sentiment.negative = 0;

    // Create an array of positive words
    char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};

    // Create an array of negative words
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "disgusting"};

    // Tokenize the string
    char *token = strtok(string, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Check if the token is a positive word
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment.positive++;
                break;
            }
        }

        // Check if the token is a negative word
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                sentiment.negative++;
                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the sentiment
    return sentiment;
}

// Main function
int main() {
    // Get the input string
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    // Analyze the sentiment of the string
    Sentiment sentiment = analyze_sentiment(string);

    // Print the sentiment
    printf("Positive: %d\n", sentiment.positive);
    printf("Negative: %d\n", sentiment.negative);

    return 0;
}