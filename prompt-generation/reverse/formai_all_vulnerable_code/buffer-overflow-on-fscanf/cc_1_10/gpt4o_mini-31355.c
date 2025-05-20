//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define POSITIVE_WORDS_COUNT 10
#define NEGATIVE_WORDS_COUNT 10

// Function prototypes
void loadWords(const char *fileName, char words[][MAX_WORD_LENGTH], int *wordCount);
int analyzeSentiment(const char *text, char positiveWords[][MAX_WORD_LENGTH], 
                     int positiveCount, char negativeWords[][MAX_WORD_LENGTH], int negativeCount);
void printSentimentScore(int score);

int main() {
    char positiveWords[POSITIVE_WORDS_COUNT][MAX_WORD_LENGTH];
    char negativeWords[NEGATIVE_WORDS_COUNT][MAX_WORD_LENGTH];
    int posCount = 0, negCount = 0;

    // Load positive and negative words from files
    loadWords("positive_words.txt", positiveWords, &posCount);
    loadWords("negative_words.txt", negativeWords, &negCount);

    // Read the input text from a file
    FILE *file = fopen("input_text.txt", "r");
    if (!file) {
        perror("Error opening input text file");
        return EXIT_FAILURE;
    }

    char text[1000];
    fread(text, sizeof(char), 1000, file);
    fclose(file);

    // Analyze sentiment
    int score = analyzeSentiment(text, positiveWords, posCount, negativeWords, negCount);
    
    // Print the sentiment score
    printSentimentScore(score);

    return EXIT_SUCCESS;
}

// Function to load words from a file into an array
void loadWords(const char *fileName, char words[][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening words file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", words[*wordCount]) != EOF && *wordCount < MAX_WORDS) {
        (*wordCount)++;
    }

    fclose(file);
}

// Function to analyze the sentiment of the given text
int analyzeSentiment(const char *text, char positiveWords[][MAX_WORD_LENGTH], 
                     int positiveCount, char negativeWords[][MAX_WORD_LENGTH], int negativeCount) {
    int score = 0;
    char *word;
    char *textCopy = strdup(text); // Duplicate text for tokenizing

    // Tokenize the text
    word = strtok(textCopy, " ,.!?;\n");
    while (word != NULL) {
        for (int i = 0; i < positiveCount; i++) {
            if (strcasecmp(word, positiveWords[i]) == 0) {
                score++;
                break; // Found a positive word
            }
        }
        for (int i = 0; i < negativeCount; i++) {
            if (strcasecmp(word, negativeWords[i]) == 0) {
                score--;
                break; // Found a negative word
            }
        }
        word = strtok(NULL, " ,.!?;\n"); // Get next word
    }
    free(textCopy); // Free the duplicated text
    return score;
}

// Function to print the sentiment score
void printSentimentScore(int score) {
    if (score > 0) {
        printf("Overall Sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall Sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Overall Sentiment: Neutral (Score: %d)\n", score);
    }
}