//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 512
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

// Structure to hold the sentiment words
typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentimentValue; // 1 for positive, -1 for negative
} SentimentWord;

SentimentWord sentimentList[MAX_WORDS];
int sentimentCount = 0;

// Function to load sentiment words from a file
void loadSentimentWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open sentiment file. Are they trying to hide something?\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(file) && sentimentCount < MAX_WORDS) {
        fscanf(file, "%s %d", sentimentList[sentimentCount].word, &sentimentList[sentimentCount].sentimentValue);
        sentimentCount++;
    }
    fclose(file);
}

// Function to perform sentiment analysis on the input text
int analyzeSentiment(const char *input) {
    char *token;
    int totalSentiment = 0;

    // Tokenize the input string
    char *inputCopy = strdup(input); // Create a mutable copy of the input
    if (inputCopy == NULL) {
        printf("Memory allocation failed. Are they watching us?\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(inputCopy, " ");
    while (token != NULL) {
        for (int i = 0; i < sentimentCount; i++) {
            if (strcasecmp(token, sentimentList[i].word) == 0) {
                totalSentiment += sentimentList[i].sentimentValue;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    free(inputCopy);
    if (totalSentiment > 0) {
        return 1; // Positive sentiment
    } else if (totalSentiment < 0) {
        return -1; // Negative sentiment
    }
    return 0; // Neutral sentiment
}

// Function to read user input and analyze it
void readInputAndAnalyze() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Please enter a sentence for analysis (or type 'exit' to quit):\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        
        // Trim the newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting. But remember, they are always watching...\n");
            break;
        }

        int result = analyzeSentiment(input);
        if (result > 0) {
            printf("Sentiment: Positive\n");
        } else if (result < 0) {
            printf("Sentiment: Negative\n");
        } else {
            printf("Sentiment: Neutral\n");
        }
    }
}

int main() {
    loadSentimentWords("sentiment.txt");  // Example file should contain words and their sentiment values
    readInputAndAnalyze();
    return 0;
}