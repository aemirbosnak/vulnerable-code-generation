//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

// Sentiment scores
typedef struct {
    char word[MAX_LENGTH];
    int score; // positive or negative score
} Sentiment;

// Function to read sentiment words from a file
int read_sentiments(const char *filename, Sentiment sentiments[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open sentiment file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiments[count].word, &sentiments[count].score) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to analyze sentiment of the input text
int analyze_sentiment(const char *text, Sentiment sentiments[], int sentiment_count) {
    char *token;
    int total_score = 0;

    // Tokenize the input text
    char *text_copy = strdup(text);
    token = strtok(text_copy, " ");

    while (token != NULL) {
        for (int i = 0; i < sentiment_count; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                total_score += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    free(text_copy);
    return total_score;
}

// Main function
int main() {
    Sentiment sentiments[MAX_LINES];
    int sentiment_count = read_sentiments("sentiments.txt", sentiments);

    if (sentiment_count < 0) {
        return EXIT_FAILURE;
    }

    char input[MAX_LENGTH];

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Type your text (type 'exit' to quit):\n");
    
    while (1) {
        printf("Input: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int score = analyze_sentiment(input, sentiments, sentiment_count);
        if (score > 0) {
            printf("Positive Sentiment Score: %d\n", score);
        } else if (score < 0) {
            printf("Negative Sentiment Score: %d\n", score);
        } else {
            printf("Neutral Sentiment Score: 0\n");
        }
    }

    printf("Thank you for using the Sentiment Analysis Tool!\n");
    return EXIT_SUCCESS;
}