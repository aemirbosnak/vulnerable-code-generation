//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Define the structure to hold sentiment words
typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment;  // 1 for positive, -1 for negative
} SentimentWord;

// Function to normalize words to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to read sentiment words from a file into an array
int read_sentiment_words(const char *filename, SentimentWord *sentimentWords) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open sentiment file: %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentimentWords[count].word, &sentimentWords[count].sentiment) != EOF) {
        to_lowercase(sentimentWords[count].word);
        count++;
    }
    fclose(file);
    return count;
}

// Function to analyze the sentiment of a given line of text
int analyze_sentiment(const char *line, SentimentWord *sentimentWords, int wordCount) {
    int totalSentiment = 0;
    char lineCopy[MAX_LINE_LENGTH];
    strcpy(lineCopy, line);

    // Tokenize the line into words
    char *token = strtok(lineCopy, " ,.!?;\n");
    while (token != NULL) {
        to_lowercase(token);
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(token, sentimentWords[i].word) == 0) {
                totalSentiment += sentimentWords[i].sentiment;
                break;
            }
        }
        token = strtok(NULL, " ,.!?;\n");
    }
    return totalSentiment;
}

// Main function that reads input, performs sentiment analysis, and outputs results
int main() {
    SentimentWord sentimentWords[DICTIONARY_SIZE];
    int wordCount = read_sentiment_words("sentiment.txt", sentimentWords);
    
    if (wordCount == 0) {
        fprintf(stderr, "No sentiment words loaded.\n");
        return 1;
    }

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Type your text and press Enter (type 'exit' to quit):\n");

    char inputLine[MAX_LINE_LENGTH];
    while (1) {
        printf("> ");
        fgets(inputLine, sizeof(inputLine), stdin);

        // Remove trailing newline character
        size_t len = strlen(inputLine);
        if (len > 0 && inputLine[len - 1] == '\n') {
            inputLine[len - 1] = '\0';
        }

        // Exit condition
        if (strcmp(inputLine, "exit") == 0) {
            break;
        }

        int sentimentScore = analyze_sentiment(inputLine, sentimentWords, wordCount);
        if (sentimentScore > 0) {
            printf("Positive sentiment with a score of: %d\n", sentimentScore);
        } else if (sentimentScore < 0) {
            printf("Negative sentiment with a score of: %d\n", sentimentScore);
        } else {
            printf("Neutral sentiment with a score of: %d\n");
        }
    }

    printf("Thank you for using the Sentiment Analysis Tool!\n");
    return 0;
}