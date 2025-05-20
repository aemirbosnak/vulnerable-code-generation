//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define MAX_INPUT_LENGTH 500
#define MAX_WORDS 100

void loadSentimentWords(char words[][MAX_WORD_LENGTH], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open sentiment words file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", words[*count]) != EOF) {
        (*count)++;
    }

    fclose(file);
}

int analyzeSentiment(char *input, char positiveWords[][MAX_WORD_LENGTH], int posCount, 
                     char negativeWords[][MAX_WORD_LENGTH], int negCount) {
    int sentimentScore = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        for (int i = 0; i < posCount; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                sentimentScore++;
                break;
            }
        }
        for (int j = 0; j < negCount; j++) {
            if (strcmp(token, negativeWords[j]) == 0) {
                sentimentScore--;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main() {
    char positiveWords[MAX_WORDS][MAX_WORD_LENGTH];
    char negativeWords[MAX_WORDS][MAX_WORD_LENGTH];
    int posCount = 0, negCount = 0;
    
    loadSentimentWords(positiveWords, &posCount, "positive.txt");
    loadSentimentWords(negativeWords, &negCount, "negative.txt");

    char input[MAX_INPUT_LENGTH];
    printf("Enter a sentence for sentiment analysis (max 500 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character at the end
    input[strcspn(input, "\n")] = 0;

    int sentimentScore = analyzeSentiment(input, positiveWords, posCount, negativeWords, negCount);

    printf("Sentiment Score: %d\n", sentimentScore);
    if (sentimentScore > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (sentimentScore < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}