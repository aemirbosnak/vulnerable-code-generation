//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 200

// Structure to hold sentiment data
typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentimentScore;
} SentimentWord;

// Function to load sentiment words from a file
int loadSentimentWords(const char *filename, SentimentWord *sentimentWords) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s %d", sentimentWords[count].word, &sentimentWords[count].sentimentScore) != EOF) {
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }
    
    fclose(file);
    return count;
}

// Function to perform sentiment analysis
int analyzeSentiment(const char *text, SentimentWord *sentimentWords, int numSentimentWords) {
    char *token;
    int sentimentValue = 0;
    char textCopy[MAX_TEXT_LENGTH];

    // Copy text to modify it
    strncpy(textCopy, text, sizeof(textCopy));
    textCopy[sizeof(textCopy) - 1] = '\0';

    // Tokenize the text
    token = strtok(textCopy, " ");
    while (token != NULL) {
        for (int i = 0; i < numSentimentWords; i++) {
            if (strcasecmp(token, sentimentWords[i].word) == 0) {
                sentimentValue += sentimentWords[i].sentimentScore;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return sentimentValue;
}

// Function to categorize the overall sentiment
const char* categorizeSentiment(int score) {
    if (score > 0) {
        return "Positive";
    } else if (score < 0) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

// Main function
int main() {
    char text[MAX_TEXT_LENGTH];
    SentimentWord sentimentWords[MAX_WORDS];
    int numSentimentWords;

    // Load the sentiment words from a file
    numSentimentWords = loadSentimentWords("sentiment_words.txt", sentimentWords);
    if (numSentimentWords < 0) {
        return EXIT_FAILURE;
    }

    // Input loop for analyzing multiple texts
    while (1) {
        printf("Enter text for sentiment analysis (type 'exit' to quit): ");
        fgets(text, sizeof(text), stdin);
        
        // Remove the newline character
        text[strcspn(text, "\n")] = 0;

        // Check for exit condition
        if (strcasecmp(text, "exit") == 0) {
            break;
        }

        // Analyze the sentiment of the entered text
        int sentimentScore = analyzeSentiment(text, sentimentWords, numSentimentWords);
        const char *sentimentCategory = categorizeSentiment(sentimentScore);

        // Print the results
        printf("Sentiment Score: %d\n", sentimentScore);
        printf("Sentiment Category: %s\n", sentimentCategory);
    }

    return EXIT_SUCCESS;
}