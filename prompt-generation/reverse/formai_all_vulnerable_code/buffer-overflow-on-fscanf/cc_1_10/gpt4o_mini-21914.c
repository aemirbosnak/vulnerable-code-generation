//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int sentimentValue; // positive or negative
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int keywordCount = 0;

void loadKeywords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open keywords file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s %d", keywords[keywordCount].keyword, &keywords[keywordCount].sentimentValue) != EOF) {
        keywordCount++;
        if (keywordCount >= MAX_KEYWORDS) {
            printf("Warning: Reached maximum keyword limit\n");
            break;
        }
    }
    fclose(file);
}

int analyzeSentiment(const char *input) {
    int sentimentScore = 0;
    char *token = strtok(strdup(input), " ");
    
    while (token != NULL) {
        for (int i = 0; i < keywordCount; ++i) {
            if (strcmp(token, keywords[i].keyword) == 0) {
                sentimentScore += keywords[i].sentimentValue;
            }
        }
        token = strtok(NULL, " ");
    }
    
    return sentimentScore;
}

void displaySentimentResult(int score) {
    if (score > 0) {
        printf("Overall sentiment: Positive (score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall sentiment: Negative (score: %d)\n", score);
    } else {
        printf("Overall sentiment: Neutral (score: %d)\n", score);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    loadKeywords("keywords.txt");
    
    printf("Enter the text for sentiment analysis:\n");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        
        int sentimentScore = analyzeSentiment(input);
        displaySentimentResult(sentimentScore);
    } else {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}