//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate sentiment score
int calculateSentimentScore(char *text) {
    int score = 0;

    // List of positive and negative words
    char positiveWords[10][20] = {"good", "great", "awesome", "amazing", "excellent", "fantastic", "happy", "love", "like", "enjoy"};
    char negativeWords[10][20] = {"bad", "terrible", "awful", "horrible", "dislike", "hate", "angry", "sad", "unhappy", "disappoint"};

    // Count the number of positive and negative words
    int positiveCount = 0, negativeCount = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                positiveCount++;
                break;
            } else if (strcmp(token, negativeWords[i]) == 0) {
                negativeCount++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    // Calculate sentiment score
    score = positiveCount - negativeCount;
    return score;
}

int main() {
    char text[100];

    // Read the text from user input
    printf("Enter any text (maximum 100 characters):\n");
    fgets(text, 100, stdin);

    // Remove new line character
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';

    // Calculate sentiment score
    int sentimentScore = calculateSentimentScore(text);

    // Determine sentiment category based on score
    char *sentimentCategory;
    if (sentimentScore > 0)
        sentimentCategory = "Positive";
    else if (sentimentScore == 0)
        sentimentCategory = "Neutral";
    else
        sentimentCategory = "Negative";

    // Print sentiment score and category
    printf("Sentiment Score: %d\nSentiment Category: %s\n", sentimentScore, sentimentCategory);

    return 0;
}