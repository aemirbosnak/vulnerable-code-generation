//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORDS 100
#define MAX_ENTRIES 100

typedef struct {
    char word[MAX_LINE_LENGTH];
    int sentimentScore;
} SentimentEntry;

SentimentEntry sentimentLexicon[MAX_ENTRIES];
int entryCount = 0;

// Function declarations
int loadSentimentLexicon(const char* filename);
int getSentimentScore(const char* line);
void analyzeSentimentOfFile(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sentiment_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* sentimentFile = argv[1];
    const char* textFile = argv[2];

    if (loadSentimentLexicon(sentimentFile) == -1) {
        fprintf(stderr, "Failed to load sentiment lexicon.\n");
        return EXIT_FAILURE;
    }

    analyzeSentimentOfFile(textFile);
    return EXIT_SUCCESS;
}

int loadSentimentLexicon(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open sentiment file");
        return -1;
    }

    while (fscanf(file, "%s %d", sentimentLexicon[entryCount].word, &sentimentLexicon[entryCount].sentimentScore) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            fprintf(stderr, "Maximum number of sentiment entries reached.\n");
            break;
        }
    }

    fclose(file);
    return 0;
}

int getSentimentScore(const char* line) {
    char* token;
    int totalScore = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        for (int i = 0; i < entryCount; i++) {
            if (strcmp(token, sentimentLexicon[i].word) == 0) {
                totalScore += sentimentLexicon[i].sentimentScore;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return totalScore;
}

void analyzeSentimentOfFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    if (!file) {
        perror("Unable to open text file");
        return;
    }

    printf("Sentiment Analysis Results:\n");
    printf("----------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        int score = getSentimentScore(line);
        printf("Line: %sSentiment Score: %d\n", line, score);
    }

    fclose(file);
}