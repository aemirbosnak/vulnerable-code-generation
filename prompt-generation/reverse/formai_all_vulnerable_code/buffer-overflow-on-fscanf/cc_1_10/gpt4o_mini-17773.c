//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 200

// Structure to hold word and its sentiment score
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} WordSentiment;

// Function prototypes
void loadSentimentWords(const char *filename, WordSentiment *sentimentWords, int *count);
int calculateSentimentScore(const char *text, WordSentiment *sentimentWords, int count);
void analyzeSentiment(const char *text);

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Please enter a sentence or paragraph to analyze its sentiment (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(text, MAX_TEXT_LENGTH, stdin);
        text[strcspn(text, "\n")] = 0; // Remove newline character

        if (strcmp(text, "exit") == 0) {
            printf("Thank you for using the Sentiment Analysis Tool. Goodbye!\n");
            break;
        }

        analyzeSentiment(text);
    }

    return 0;
}

// Function to load sentiment words from a file
void loadSentimentWords(const char *filename, WordSentiment *sentimentWords, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open sentiment words file.\n");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %d", sentimentWords[*count].word, &sentimentWords[*count].score) == 2) {
        (*count)++;
    }

    fclose(file);
}

// Function to calculate the sentiment score of entered text
int calculateSentimentScore(const char *text, WordSentiment *sentimentWords, int count) {
    int score = 0;
    char *token;
    char tempText[MAX_TEXT_LENGTH];

    // Create a modifiable copy of text for tokenization
    strcpy(tempText, text);
    token = strtok(tempText, " ");

    while (token != NULL) {
        for (int i = 0; i < count; i++) {
            if (strcasecmp(token, sentimentWords[i].word) == 0) {
                score += sentimentWords[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return score;
}

// Function to analyze sentiment and provide feedback
void analyzeSentiment(const char *text) {
    WordSentiment sentimentWords[MAX_WORDS];
    int count = 0;

    // Load sentiment words
    loadSentimentWords("sentiment_words.txt", sentimentWords, &count);

    // Calculate sentiment score
    int score = calculateSentimentScore(text, sentimentWords, count);

    // Output the sentiment analysis
    if (score > 0) {
        printf("Sentiment Score: %d (Positive sentiment)\n", score);
    } else if (score < 0) {
        printf("Sentiment Score: %d (Negative sentiment)\n", score);
    } else {
        printf("Sentiment Score: %d (Neutral sentiment)\n", score);
    }
}