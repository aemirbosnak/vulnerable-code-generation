//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define sentiment categories
#define POSITIVE 0
#define NEGATIVE 1
#define NEUTRAL 2

int main() {
    // Define words with positive, negative, and neutral sentiment
    char positive_words[10][10] = {"love", "happy", "excited", "amazing", "great", "awesome", "fun", "fantastic", "wonderful", "joyful"};
    char negative_words[10][10] = {"hate", "sad", "angry", "frustrated", "miserable", "terrible", "annoyed", "disappointed", "upset", "depressed"};
    char neutral_words[10][10] = {"neutral", "okay", "fine", "average", "boring", "typical", "indifferent", "plain", "common", "ordinary"};

    // Get user input
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strlen(input) - 1] = '\0';

    // Split input into words
    char *token = strtok(input, " ");

    // Initialize sentiment analysis variables
    int positive_count = 0, negative_count = 0, neutral_count = 0;

    while (token != NULL) {
        // Check if token is in positive_words
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            }
        }

        // Check if token is in negative_words
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }

        // Check if token is in neutral_words
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, neutral_words[i]) == 0) {
                neutral_count++;
            }
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Determine overall sentiment of input
    int sentiment;
    if (positive_count > negative_count && positive_count > neutral_count) {
        sentiment = POSITIVE;
    } else if (negative_count > positive_count && negative_count > neutral_count) {
        sentiment = NEGATIVE;
    } else {
        sentiment = NEUTRAL;
    }

    // Display result
    printf("Sentiment Analysis Result:\n");
    printf("==========================\n");
    printf("Positive Words: %d\n", positive_count);
    printf("Negative Words: %d\n", negative_count);
    printf("Neutral Words: %d\n", neutral_count);

    switch (sentiment) {
        case POSITIVE:
            printf("Overall Sentiment: Positive\n");
            break;
        case NEGATIVE:
            printf("Overall Sentiment: Negative\n");
            break;
        case NEUTRAL:
            printf("Overall Sentiment: Neutral\n");
            break;
    }

    return 0;
}