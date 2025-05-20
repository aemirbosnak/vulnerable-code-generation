//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

// Structure to hold sentiment data
typedef struct {
    char word[MAX_LENGTH];
    int sentiment; // Positive=1, Negative=-1, Neutral=0
} Sentiment;

Sentiment sentiments[MAX_WORDS];
int sentiment_count = 0;

// Function to load sentiment words from a file
void load_sentiments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open sentiment file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentiments[sentiment_count].word, &sentiments[sentiment_count].sentiment) != EOF) {
        sentiment_count++;
    }
    fclose(file);
}

// Function to analyze the sentiment of a given text
int analyze_sentiment(const char *text) {
    char word[MAX_LENGTH];
    int score = 0;
    const char *ptr = text;

    while (sscanf(ptr, "%s", word) > 0) {
        int found = 0;
        for (int i = 0; i < sentiment_count; i++) {
            if (strcmp(word, sentiments[i].word) == 0) {
                score += sentiments[i].sentiment;
                found = 1;
                break;
            }
        }
        // Move pointer to the next word
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        while (*ptr == ' ') ptr++;
    }

    return score;
}

// Main function to demonstrate the sentiment analysis tool
int main() {
    char input_text[1000];

    // Load sentiment words from predefined file
    load_sentiments("sentiment.txt");

    printf("Enter text for sentiment analysis:\n");
    fgets(input_text, sizeof(input_text), stdin);
    
    // Remove newline character
    input_text[strcspn(input_text, "\n")] = 0;

    int sentiment_score = analyze_sentiment(input_text);
    
    printf("Sentiment Analysis Result:\n");
    if (sentiment_score > 0) {
        printf("Overall sentiment: Positive (Score: %d)\n", sentiment_score);
    } else if (sentiment_score < 0) {
        printf("Overall sentiment: Negative (Score: %d)\n", sentiment_score);
    } else {
        printf("Overall sentiment: Neutral (Score: %d)\n", sentiment_score);
    }

    return 0;
}