//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_WORDS 100
#define MAX_SENTIMENTS 10
#define MAX_WORD_LENGTH 20

// Structure to store sentiment words and their associated scores
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} Sentiment;

// Function prototype declarations
void load_sentiments(const char* filename, Sentiment *sentiments, int *count);
int analyze_sentiment(const char *input, Sentiment *sentiments, int sentiment_count);
void print_sentiment_result(int score);

int main() {
    Sentiment sentiments[MAX_SENTIMENTS];
    int sentiment_count;

    // Load sentiment words and scores
    load_sentiments("sentiments.txt", sentiments, &sentiment_count);

    // Main input loop for sentiment analysis
    while (1) {
        char input[MAX_INPUT];
        printf("Enter a sentence to analyze its sentiment (or 'exit' to quit): ");
        
        // Read user input
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }
        
        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Analyze the sentiment of the input
        int score = analyze_sentiment(input, sentiments, sentiment_count);
        print_sentiment_result(score);
    }
    
    return 0;
}

void load_sentiments(const char* filename, Sentiment *sentiments, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening sentiment file.\n");
        exit(1);
    }

    *count = 0;
    while (fscanf(file, "%s %d", sentiments[*count].word, &sentiments[*count].score) == 2) {
        (*count)++;
        if (*count >= MAX_SENTIMENTS) {
            break; // Avoid exceeding max limits
        }
    }
    fclose(file);
}

int analyze_sentiment(const char *input, Sentiment *sentiments, int sentiment_count) {
    char *token;
    int score = 0;

    // Create a mutable copy of the input string to tokenize
    char *input_copy = strdup(input);

    // Tokenize the input string
    token = strtok(input_copy, " ");
    while (token != NULL) {
        for (int i = 0; i < sentiment_count; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                score += sentiments[i].score; // Update the score based on sentiment
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    free(input_copy); // Free the allocated memory for input copy
    return score; // Return the final sentiment score
}

void print_sentiment_result(int score) {
    if (score > 0) {
        printf("Positive sentiment detected with score: %d\n", score);
    } else if (score < 0) {
        printf("Negative sentiment detected with score: %d\n", score);
    } else {
        printf("Neutral sentiment detected with score: %d\n", score);
    }
}

// End of the mind-bending sentiment analysis tool