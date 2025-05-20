//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_WORDS 100
#define MIN_SENTIMENT_SCORE 1
#define MAX_SENTIMENT_SCORE 5

// Structure to hold word sentiment score
typedef struct {
    char word[50];
    int score;
} Sentiment;

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to load sentiments from a file
int loadSentiments(Sentiment sentiments[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open sentiments file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiments[count].word, &sentiments[count].score) != EOF) {
        toLowerCase(sentiments[count].word);
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to get sentiment score of a phrase
int getSentimentScore(const char *phrase, Sentiment sentiments[], int sentimentCount) {
    int totalScore = 0;
    char *token;
    char tempPhrase[MAX_BUFFER];

    // Copy phrase to a temporary buffer to tokenize
    strcpy(tempPhrase, phrase);
    token = strtok(tempPhrase, " ");

    // Analyze each word in the phrase
    while (token != NULL) {
        toLowerCase(token);
        for (int i = 0; i < sentimentCount; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                totalScore += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return totalScore;
}

// Function to classify the sentiment score
const char *classifySentiment(int score) {
    if (score >= MIN_SENTIMENT_SCORE && score <= MAX_SENTIMENT_SCORE) {
        if (score <= 2) {
            return "Negative";
        } else if (score <= 4) {
            return "Neutral";
        } else {
            return "Positive";
        }
    }
    return "Unknown";
}

// Function to read input from user
void readInput(char *buffer, int length) {
    printf("Enter a phrase to analyze: ");
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove the newline character
}

int main() {
    Sentiment sentiments[MAX_WORDS];
    int sentimentCount;
    char buffer[MAX_BUFFER];

    // Load sentiment data from a file
    sentimentCount = loadSentiments(sentiments, "sentiments.txt");
    if (sentimentCount < 0) {
        return EXIT_FAILURE;
    }

    // Prompt user for input
    readInput(buffer, MAX_BUFFER);

    // Calculate sentiment score
    int score = getSentimentScore(buffer, sentiments, sentimentCount);
    const char *sentimentClassification = classifySentiment(score);

    // Display results
    printf("Sentiment score: %d\n", score);
    printf("Sentiment classification: %s\n", sentimentClassification);

    return EXIT_SUCCESS;
}