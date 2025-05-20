//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} SentimentWord;

SentimentWord sentimentList[MAX_WORDS];
int sentimentCount = 0;

void loadSentimentWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open the file %s \n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentimentList[sentimentCount].word, &sentimentList[sentimentCount].score) != EOF) {
        sentimentCount++;
    }

    fclose(file);
}

int getSentimentScore(const char *text) {
    int totalScore = 0;
    char *token = strtok(text, " ");

    while (token != NULL) {
        for (int i = 0; i < sentimentCount; i++) {
            if (strcmp(token, sentimentList[i].word) == 0) {
                totalScore += sentimentList[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return totalScore;
}

void analyzeSentiment(const char *text) {
    char buffer[MAX_LINE_LENGTH];
    strcpy(buffer, text);
    int score = getSentimentScore(buffer);

    if (score > 0) {
        printf("Overall sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Overall sentiment: Neutral (Score: %d)\n", score);
    }
}

void readTextInput() {
    char line[MAX_LINE_LENGTH];
    printf("Enter text for sentiment analysis (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        line[strcspn(line, "\n")] = 0; // Remove newline character

        if (strcmp(line, "exit") == 0) break;

        analyzeSentiment(line);
    }
}

int main() {
    loadSentimentWords("sentiment_words.txt");
    readTextInput();
    return 0;
}