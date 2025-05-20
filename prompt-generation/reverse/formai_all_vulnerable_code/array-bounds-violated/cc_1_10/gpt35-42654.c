//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input text
#define MAX_LEN 1000

// Define the threshold of positive and negative sentiments
#define THRESHOLD_POS 0.6
#define THRESHOLD_NEG -0.6

int main() {
    // Define the input text variable
    char input_text[MAX_LEN];

    // Prompt the user to enter the text to analyze
    printf("Enter the text to analyze: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Remove the trailing newline character
    if (input_text[strlen(input_text) - 1] == '\n') {
        input_text[strlen(input_text) - 1] = '\0';
    }

    // Define the sentiment score variable
    float sentiment_score = 0.0;

    // Define the positive and negative word dictionaries
    char* positive_words[] = {"good", "great", "excellent", "positive", "fantastic"};
    int num_positive_words = sizeof(positive_words) / sizeof(positive_words[0]);
    char* negative_words[] = {"bad", "terrible", "negative", "awful", "horrible"};
    int num_negative_words = sizeof(negative_words) / sizeof(negative_words[0]);

    // Tokenize the input text into individual words
    char* token = strtok(input_text, " ");

    while (token != NULL) {
        // Check if the token is a positive word
        for (int i = 0; i < num_positive_words; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment_score += 1.0;
                break;
            }
        }

        // Check if the token is a negative word
        for (int i = 0; i < num_negative_words; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                sentiment_score -= 1.0;
                break;
            }
        }

        // Move to the next token
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score, on a scale of -1 to 1
    sentiment_score /= strlen(input_text);

    // Print the sentiment score
    printf("Sentiment score: %f\n", sentiment_score);

    // Determine the sentiment label
    if (sentiment_score > THRESHOLD_POS) {
        printf("Sentiment label: Positive\n");
    } else if (sentiment_score < THRESHOLD_NEG) {
        printf("Sentiment label: Negative\n");
    } else {
        printf("Sentiment label: Neutral\n");
    }

    return 0;
}