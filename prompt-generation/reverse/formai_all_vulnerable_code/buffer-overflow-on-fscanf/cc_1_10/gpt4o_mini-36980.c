//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#define MAX_LINE_LENGTH 1024 
#define MAX_WORD_LENGTH 100 
#define MAX_WORDS 1000 

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} SentimentWord;

SentimentWord sentimentWords[MAX_WORDS]; 
int sentimentWordCount = 0; 

void loadSentimentWords(const char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (!file) { 
        perror("Unable to open sentiment file"); 
        exit(EXIT_FAILURE); 
    } 
    while (fscanf(file, "%s %d\n", sentimentWords[sentimentWordCount].word, &sentimentWords[sentimentWordCount].score) != EOF) {
        sentimentWordCount++; 
    }
    fclose(file); 
}

int getSentimentScore(const char *text) {
    int totalScore = 0; 
    char *token;
    char *textCopy = strdup(text); 
    token = strtok(textCopy, " "); 
    while (token) { 
        for (int i = 0; i < sentimentWordCount; i++) { 
            if (strcasecmp(token, sentimentWords[i].word) == 0) { 
                totalScore += sentimentWords[i].score; 
                break; 
            }
        }
        token = strtok(NULL, " "); 
    }
    free(textCopy); 
    return totalScore; 
}

void printSentimentAnalysis(const char *text) {
    int score = getSentimentScore(text); 
    if (score > 0) { 
        printf("Sentiment: Positive (Score: %d)\n", score); 
    } else if (score < 0) { 
        printf("Sentiment: Negative (Score: %d)\n", score); 
    } else { 
        printf("Sentiment: Neutral (Score: %d)\n", score); 
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]); 
    }
}

void analyzeTextFromFile(const char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (!file) {
        perror("Unable to open text file"); 
        return; 
    }
    char line[MAX_LINE_LENGTH]; 
    while (fgets(line, sizeof(line), file)) { 
        printf("Analyzing: %s", line); 
        toLowerCase(line); 
        printSentimentAnalysis(line); 
    }
    fclose(file); 
}

int main(int argc, char *argv[]) {
    if (argc != 3) { 
        fprintf(stderr, "Usage: %s <sentiment_file> <text_file>\n", argv[0]); 
        return EXIT_FAILURE; 
    }
    
    loadSentimentWords(argv[1]); 
    analyzeTextFromFile(argv[2]);
    
    return EXIT_SUCCESS; 
}