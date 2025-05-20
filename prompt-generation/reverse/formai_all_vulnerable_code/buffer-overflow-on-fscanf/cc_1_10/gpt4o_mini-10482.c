//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1000
#define MAX_TOKEN_LEN 100
#define MAX_SENTIMENT_WORDS 100

// Struct to hold sentiment words
typedef struct {
    char word[MAX_TOKEN_LEN];
    int sentimentValue; // +1 for positive, -1 for negative
} SentimentWord;

// Function to clean and tokenize input text
void tokenize(char *text, char tokens[][MAX_TOKEN_LEN], int *tokenCount) {
    char *token = strtok(text, " ,.!?;:\n");
    *tokenCount = 0;
    while (token != NULL) {
        strncpy(tokens[*tokenCount], token, MAX_TOKEN_LEN - 1);
        tokens[*tokenCount][MAX_TOKEN_LEN - 1] = '\0'; // Ensure null termination
        (*tokenCount)++;
        token = strtok(NULL, " ,.!?;:\n");
    }
}

// Function to load sentiment words from a file
int loadSentimentWords(const char *filename, SentimentWord *sentimentWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open sentiment words file: %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s %d", sentimentWords[count].word, &sentimentWords[count].sentimentValue) == 2) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function for sentiment analysis
int analyzeSentiment(char tokens[][MAX_TOKEN_LEN], int tokenCount, SentimentWord *sentimentWords, int sentimentCount) {
    int totalSentiment = 0;
    
    for (int i = 0; i < tokenCount; i++) {
        for (int j = 0; j < sentimentCount; j++) {
            if (strcmp(tokens[i], sentimentWords[j].word) == 0) {
                totalSentiment += sentimentWords[j].sentimentValue;
                break; // Move to next token after a match
            }
        }
    }
    
    return totalSentiment;
}

// Main function
int main() {
    char text[MAX_TEXT_LEN];
    char tokens[MAX_TEXT_LEN][MAX_TOKEN_LEN];
    int tokenCount = 0;
    
    // Load sentiment words from file
    SentimentWord sentimentWords[MAX_SENTIMENT_WORDS];
    int sentimentCount = loadSentimentWords("sentiment_words.txt", sentimentWords);
    
    if (sentimentCount < 0) {
        return EXIT_FAILURE;
    }
    
    // Input text for sentiment analysis
    printf("Enter text for sentiment analysis:\n");
    if (fgets(text, MAX_TEXT_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Tokenize the input text
    tokenize(text, tokens, &tokenCount);
    
    // Analyze sentiment
    int sentimentScore = analyzeSentiment(tokens, tokenCount, sentimentWords, sentimentCount);
    
    // Display the result
    printf("Sentiment analysis score: %d\n", sentimentScore);
    
    if (sentimentScore > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (sentimentScore < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }
    
    return EXIT_SUCCESS;
}