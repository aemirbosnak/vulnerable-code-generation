//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert all characters in a string to lowercase
void toLowerCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to perform sentiment analysis
int analyzeSentiment(char *text) {
    // Convert text to lowercase
    toLowerCase(text);

    // Count positive and negative words
    int positive = 0;
    int negative = 0;

    // Define dictionary of positive and negative words
    char *posWords[] = {"happy", "joy", "delighted", "excited", "pleased"};
    char *negWords[] = {"sad", "angry", "frustrated", "disappointed", "upset"};

    // Iterate over each word in the text
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = text[i];

        // Check if word is positive or negative
        for (int j = 0; j < 2; j++) {
            int found = 0;
            for (int k = 0; k < 5; k++) {
                if (strstr(posWords[j], c) || strstr(negWords[j], c)) {
                    found = 1;
                    break;
                }
            }

            // If found, increment positive or negative counter
            if (found) {
                if (j == 0) {
                    positive++;
                } else {
                    negative++;
                }
            }
        }
    }

    // Calculate sentiment score
    int score = (positive - negative) / 2;

    // Print sentiment analysis result
    printf("Sentiment Analysis: %d\n", score);

    return score;
}

int main() {
    // Get user input
    char text[100];
    printf("Enter a sentence to analyze: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input
    int len = strlen(text);
    text[len - 1] = '\0';

    // Perform sentiment analysis
    int sentiment = analyzeSentiment(text);

    return 0;
}