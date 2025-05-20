//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
/*
 * C Sentiment Analysis Tool
 *
 * This program is an example of a sentiment analysis tool
 * written in C. It uses a single-threaded approach and
 * provides a simple command-line interface.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 256
#define NUM_SENTIMENTS 3

// Sentiment dictionary
const char *sentiments[NUM_SENTIMENTS] = {
    "positive",
    "negative",
    "neutral"
};

// Function to calculate sentiment score
int get_sentiment_score(const char *text) {
    int score = 0;

    // Iterate over each word in the text
    for (int i = 0; i < strlen(text); i++) {
        // Check if the word is a sentiment word
        for (int j = 0; j < NUM_SENTIMENTS; j++) {
            if (strcmp(text + i, sentiments[j]) == 0) {
                score += j + 1;
                break;
            }
        }
    }

    return score;
}

// Function to print the sentiment score
void print_sentiment_score(const char *text) {
    int score = get_sentiment_score(text);

    if (score == 0) {
        printf("Neutral\n");
    } else if (score > 0) {
        printf("Positive\n");
    } else {
        printf("Negative\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    print_sentiment_score(argv[1]);

    return 0;
}