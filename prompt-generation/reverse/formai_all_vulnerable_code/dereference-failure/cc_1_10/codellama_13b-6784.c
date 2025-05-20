//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
// Cyberpunk Sentiment Analysis Tool
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structures for storing data
typedef struct {
    char* text;
    int sentiment;
} TextData;

typedef struct {
    char* word;
    int sentiment;
} WordData;

// Function for getting user input
char* getInput() {
    char* input = (char*)malloc(sizeof(char) * 256);
    fgets(input, 256, stdin);
    return input;
}

// Function for processing user input
void processInput(char* input) {
    // Split input into words
    char* word = strtok(input, " ");
    while (word != NULL) {
        // Get sentiment of word
        int sentiment = getSentiment(word);
        if (sentiment == 1) {
            // Positive sentiment
            printf("Positive sentiment: %s\n", word);
        } else if (sentiment == -1) {
            // Negative sentiment
            printf("Negative sentiment: %s\n", word);
        } else {
            // Neutral sentiment
            printf("Neutral sentiment: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
}

// Function for getting sentiment of a word
int getSentiment(char* word) {
    // Load sentiment data from file
    FILE* fp = fopen("sentiment.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, 256, fp) != NULL) {
        // Get word and sentiment from line
        char* wordFromLine = strtok(line, " ");
        char* sentimentFromLine = strtok(NULL, " ");
        // Check if word matches
        if (strcmp(word, wordFromLine) == 0) {
            // Word matches, return sentiment
            return atoi(sentimentFromLine);
        }
    }
    // Word not found, return neutral sentiment
    return 0;
}

// Main function
int main() {
    // Get user input
    char* input = getInput();
    // Process input
    processInput(input);
    return 0;
}