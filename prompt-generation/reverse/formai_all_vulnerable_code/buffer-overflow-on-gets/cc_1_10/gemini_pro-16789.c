//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
// Linus Torvalds style C Sentiment analysis tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// Define a struct to store the sentiment and its score
typedef struct {
    char *sentiment;
    int score;
} sentiment_t;

// Create an array of sentiment and score pairs
sentiment_t sentiments[] = {
    {"positive", 1},
    {"negative", -1},
    {"neutral", 0}
};

// Get the sentiment of a sentence
int get_sentiment(char *sentence) {
    int sentiment_score = 0;

    // Tokenize the sentence
    char *token = strtok(sentence, " ");

    // Iterate over the tokens
    while (token != NULL) {
        // Find the sentiment of the token
        for (int i = 0; i < sizeof(sentiments) / sizeof(sentiment_t); i++) {
            if (strcmp(token, sentiments[i].sentiment) == 0) {
                sentiment_score += sentiments[i].score;
                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return sentiment_score;
}

int main() {
    // Get the sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    gets(sentence);

    // Get the sentiment of the sentence
    int sentiment_score = get_sentiment(sentence);

    // Print the sentiment
    if (sentiment_score > 0) {
        printf("The sentence is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}