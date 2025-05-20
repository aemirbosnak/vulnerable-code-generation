//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTIMENTS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment; // 1 for positive, -1 for negative
} SentimentWord;

SentimentWord sentimentDictionary[MAX_SENTIMENTS];
int sentimentCount = 0;

// Function to load sentiments from a file
void loadSentimentDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open sentiment file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentimentDictionary[sentimentCount].word, &sentimentDictionary[sentimentCount].sentiment) != EOF) {
        sentimentCount++;
    }
    fclose(file);
}

// Function to analyze sentiment of a given text
int analyzeSentiment(const char *text) {
    char *token;
    int sentimentScore = 0;
    char *textCopy = strdup(text);

    // Tokenizing the input text
    token = strtok(textCopy, " ");
    while (token != NULL) {
        for (int i = 0; i < sentimentCount; i++) {
            if (strcmp(token, sentimentDictionary[i].word) == 0) {
                sentimentScore += sentimentDictionary[i].sentiment;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    free(textCopy);
    return sentimentScore;
}

// Function to display a sentiment score
void displaySentimentScore(int score) {
    if (score > 0) {
        printf("Overall Sentiment: Positive (%d)\n", score);
    } else if (score < 0) {
        printf("Overall Sentiment: Negative (%d)\n", score);
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadSentimentDictionary("sentiment.txt");

    int totalSentiment = 0;
    for (int i = 1; i < argc; i++) {
        totalSentiment += analyzeSentiment(argv[i]);
    }

    displaySentimentScore(totalSentiment);

    return EXIT_SUCCESS;
}