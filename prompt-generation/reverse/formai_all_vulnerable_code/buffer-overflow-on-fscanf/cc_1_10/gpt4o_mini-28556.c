//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to load sentiment words from a file
int loadSentimentWords(const char *filename, char sentiments[][20], int *score) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening sentiment words file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiments[count], &score[count]) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to analyze sentiment of a given text
int analyzeSentiment(const char *text, char sentiments[][20], int *score, int sentimentCount) {
    char buffer[256];
    int totalScore = 0;
    
    // Split the text into words
    char *word = strtok(strdup(text), " ");
    while (word != NULL) {
        toLowerCase(word); // Normalize the word to lowercase

        // Check if the word is in the sentiment list
        for (int i = 0; i < sentimentCount; i++) {
            if (strcmp(word, sentiments[i]) == 0) {
                totalScore += score[i];
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    
    return totalScore;
}

// Function to print sentiment result
void printSentimentResult(int score) {
    if (score > 0) {
        printf("Overall Sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall Sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Overall Sentiment: Neutral (Score: %d)\n", score);
    }
}

int main() {
    const int MAX_SENTIMENTS = 100;
    char sentiments[MAX_SENTIMENTS][20];
    int score[MAX_SENTIMENTS];
    int sentimentCount;

    // Load sentiment words and scores
    sentimentCount = loadSentimentWords("sentiments.txt", sentiments, score);
    if (sentimentCount == 0) {
        return 1;
    }

    char text[256];
    printf("Enter a sentence for sentiment analysis: ");
    fgets(text, sizeof(text), stdin);

    // Analyze the sentiment of the text
    int sentimentScore = analyzeSentiment(text, sentiments, score, sentimentCount);
    
    // Print the result
    printSentimentResult(sentimentScore);

    return 0;
}