//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTIMENT_WORDS 100
#define MAX_INPUT_LENGTH 200
#define MAX_POSITIVE_WORDS 100
#define MAX_NEGATIVE_WORDS 100

// Structures to store sentiment words
typedef struct {
    char positiveWords[MAX_POSITIVE_WORDS][MAX_WORD_LENGTH];
    int positiveCount;
} PositiveWords;

typedef struct {
    char negativeWords[MAX_NEGATIVE_WORDS][MAX_WORD_LENGTH];
    int negativeCount;
} NegativeWords;

// Function prototypes
int loadWords(const char *filename, char words[][MAX_WORD_LENGTH], int maxWords);
int analyzeSentiment(char *input, PositiveWords *pos, NegativeWords *neg);
void displaySentiment(int score);

int main() {
    PositiveWords posWords;
    NegativeWords negWords;

    // Load positive and negative words from files
    posWords.positiveCount = loadWords("positive.txt", posWords.positiveWords, MAX_POSITIVE_WORDS);
    negWords.negativeCount = loadWords("negative.txt", negWords.negativeWords, MAX_NEGATIVE_WORDS);
    
    char input[MAX_INPUT_LENGTH];
    
    printf("Welcome to the C Sentiment Analysis Tool!\n");
    printf("Please enter a sentence to analyze sentiment:\n");
    
    // Get user input
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Analyze sentiment
    int score = analyzeSentiment(input, &posWords, &negWords);
    
    // Display sentiment result
    displaySentiment(score);
    
    return 0;
}

// Load words from a file into an array
int loadWords(const char *filename, char words[][MAX_WORD_LENGTH], int maxWords) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening word list file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (count < maxWords && fscanf(file, "%s", words[count]) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

// Analyze sentiment based on input
int analyzeSentiment(char *input, PositiveWords *pos, NegativeWords *neg) {
    int score = 0;
    char *token = strtok(input, " \n");
    
    while (token != NULL) {
        // Check for positive words
        for (int i = 0; i < pos->positiveCount; i++) {
            if (strcmp(token, pos->positiveWords[i]) == 0) {
                score++;
                break; // Break to avoid multiple counting
            }
        }
        
        // Check for negative words
        for (int j = 0; j < neg->negativeCount; j++) {
            if (strcmp(token, neg->negativeWords[j]) == 0) {
                score--;
                break; // Break to avoid multiple counting
            }
        }
        
        token = strtok(NULL, " \n");
    }
    
    return score;
}

// Display the sentiment analysis result
void displaySentiment(int score) {
    if (score > 0) {
        printf("The sentiment of your input is positive with a score of %d.\n", score);
    } else if (score < 0) {
        printf("The sentiment of your input is negative with a score of %d.\n", score);
    } else {
        printf("The sentiment of your input is neutral.\n");
    }
}