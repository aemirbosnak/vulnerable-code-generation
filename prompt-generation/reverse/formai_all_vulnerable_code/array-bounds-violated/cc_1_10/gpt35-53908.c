//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define list of positive and negative words
char* positiveWords[] = {"happy", "joy", "love", "excitement", "fun", "celebration"};
char* negativeWords[] = {"hate", "sad", "angry", "depression", "violence", "harm"};

// Function to calculate sentiment score
int calculateSentimentScore(char* sentence) {
    int sentimentScore = 0;
    char* word = strtok(sentence, " ");

    while (word != NULL) {
        // Check if word is positive or negative
        for (int i = 0; i < 6; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore++;
            } else if (strcmp(word, negativeWords[i]) == 0) {
                sentimentScore--;
            }
        }

        word = strtok(NULL, " ");
    }

    return sentimentScore;
}

// Main function to take input and output sentiment score
int main() {
    char input[1000];
    int sentimentScore;

    printf("Welcome to the Sentiment Analysis tool!\n");
    printf("Enter a sentence to analyze: ");
    fgets(input, 1000, stdin);
    
    // Remove newline character at end of input
    int length = strlen(input) - 1;
    if (input[length] == '\n') {
        input[length] = '\0';
    }

    sentimentScore = calculateSentimentScore(input);

    if (sentimentScore > 0) {
        printf("\nYour sentence has a POSITIVE sentiment score of %d!\n", sentimentScore);
    } else if (sentimentScore == 0) {
        printf("\nYour sentence has a NEUTRAL sentiment score of 0.\n");
    } else {
        printf("\nYour sentence has a NEGATIVE sentiment score of %d.\n", sentimentScore);
    }

    return 0;
}