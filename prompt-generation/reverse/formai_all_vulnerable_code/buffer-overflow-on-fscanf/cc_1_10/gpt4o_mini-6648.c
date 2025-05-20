//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100
#define MAX_LENGTH 256

// Structure to hold a word and its corresponding sentiment score
typedef struct {
    char word[MAX_LENGTH];
    int score;
} Sentiment;

// Function to read sentiment words from file
int loadSentimentData(const char *filename, Sentiment sentiments[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open sentiment file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiments[count].word, &sentiments[count].score) != EOF && count < MAX_SENTENCES) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to calculate sentiment score of a sentence
int calculateSentimentScore(const char *sentence, Sentiment sentiments[], int sentimentCount) {
    int totalScore = 0;
    char *token;
    char *tempSentence = strdup(sentence);

    token = strtok(tempSentence, " ");
    while (token != NULL) {
        for (int i = 0; i < sentimentCount; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                totalScore += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    
    free(tempSentence);
    return totalScore;
}

// Function to read sentences from user input
void readSentences(char sentences[MAX_SENTENCES][MAX_LENGTH], int *count) {
    printf("Enter sentences (type 'exit' to stop):\n");
    while (*count < MAX_SENTENCES) {
        fgets(sentences[*count], MAX_LENGTH, stdin);
        if (strncmp(sentences[*count], "exit", 4) == 0) {
            break;
        }
        // Remove newline character from fgets
        sentences[*count][strcspn(sentences[*count], "\n")] = 0;
        (*count)++;
    }
}

// Function to display results
void displayResults(char sentences[MAX_SENTENCES][MAX_LENGTH], int sentimentScores[], int count) {
    printf("\nSentiment Analysis Results:\n");
    for (int i = 0; i < count; i++) {
        printf("Sentence: \"%s\" - Sentiment Score: %d\n", sentences[i], sentimentScores[i]);
    }
}

int main() {
    Sentiment sentiments[MAX_SENTENCES];
    int sentimentCount = loadSentimentData("sentiment.txt", sentiments);
    
    if (sentimentCount == 0) {
        printf("No sentiment data loaded. Exiting...\n");
        return 1;
    }

    char sentences[MAX_SENTENCES][MAX_LENGTH];
    int sentimentScores[MAX_SENTENCES];
    int sentenceCount = 0;

    readSentences(sentences, &sentenceCount);

    for (int i = 0; i < sentenceCount; i++) {
        sentimentScores[i] = calculateSentimentScore(sentences[i], sentiments, sentimentCount);
    }

    displayResults(sentences, sentimentScores, sentenceCount);

    return 0;
}