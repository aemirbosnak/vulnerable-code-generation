//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_POSITIVE_WORDS 10
#define MAX_NEGATIVE_WORDS 10

void loadWords(char words[][MAX_WORD_LENGTH], const char *filename, int *count);
int analyzeSentiment(char *text, char positiveWords[][MAX_WORD_LENGTH], int posCount, char negativeWords[][MAX_WORD_LENGTH], int negCount);
void getInput(char *text, int size);
void displayResult(int sentiment);

int main() {
    char positiveWords[MAX_POSITIVE_WORDS][MAX_WORD_LENGTH];
    char negativeWords[MAX_NEGATIVE_WORDS][MAX_WORD_LENGTH];
    int posCount = 0, negCount = 0;

    loadWords(positiveWords, "positive_words.txt", &posCount);
    loadWords(negativeWords, "negative_words.txt", &negCount);

    char inputText[500];
    printf("Enter a sentence for sentiment analysis:\n");
    getInput(inputText, sizeof(inputText));

    int sentimentScore = analyzeSentiment(inputText, positiveWords, posCount, negativeWords, negCount);
    displayResult(sentimentScore);

    return 0;
}

void loadWords(char words[][MAX_WORD_LENGTH], const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    while (fscanf(file, "%s", words[*count]) != EOF && *count < MAX_WORDS) {
        (*count)++;
    }
    fclose(file);
}

int analyzeSentiment(char *text, char positiveWords[][MAX_WORD_LENGTH], int posCount, char negativeWords[][MAX_WORD_LENGTH], int negCount) {
    int score = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < posCount; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                score++;
                break;
            }
        }
        for (int j = 0; j < negCount; j++) {
            if (strcmp(token, negativeWords[j]) == 0) {
                score--;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

void getInput(char *text, int size) {
    if (fgets(text, size, stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    text[strcspn(text, "\n")] = 0; // Remove the newline character
}

void displayResult(int sentiment) {
    if (sentiment > 0) {
        printf("Overall Sentiment: Positive (Score: %d)\n", sentiment);
    } else if (sentiment < 0) {
        printf("Overall Sentiment: Negative (Score: %d)\n", sentiment);
    } else {
        printf("Overall Sentiment: Neutral (Score: %d)\n", sentiment);
    }
}