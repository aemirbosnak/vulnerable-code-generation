//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 100
#define DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} SentimentWord;

SentimentWord sentimentDict[DICTIONARY_SIZE];
int dictSize = 0;

void loadSentimentDictionary(const char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open sentiment dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(file, "%s %d\n", sentimentDict[dictSize].word, &sentimentDict[dictSize].score) != EOF) {
        dictSize++;
    }

    fclose(file);
}

int getSentimentScore(const char *word) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(sentimentDict[i].word, word) == 0) {
            return sentimentDict[i].score;
        }
    }
    return 0; // neutral if word is not found
}

void analyzeSentiment(const char *sentence) {
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int wordCount = 0;
    char *token = strtok(strdup(sentence), " ");
    
    while(token != NULL) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " ");
    }

    int totalScore = 0;
    
    for (int i = 0; i < wordCount; i++) {
        totalScore += getSentimentScore(words[i]);
    }

    printf("Sentiment analysis result for sentence: \"%s\"\n", sentence);
    if (totalScore > 0) {
        printf("Positive Sentiment Score: %d\n", totalScore);
    } else if (totalScore < 0) {
        printf("Negative Sentiment Score: %d\n", totalScore);
    } else {
        printf("Neutral Sentiment Score: %d\n", totalScore);
    }
}

int main() {
    loadSentimentDictionary("sentiment_dict.txt");

    char sentences[MAX_SENTENCES][MAX_WORD_LENGTH];
    int sentenceCount = 0;

    printf("Enter sentences to analyze sentiment (type 'exit' to quit):\n");

    while (1) {
        printf("Sentence %d: ", sentenceCount + 1);
        fgets(sentences[sentenceCount], MAX_WORD_LENGTH, stdin);
        
        // Remove newline character
        sentences[sentenceCount][strcspn(sentences[sentenceCount], "\n")] = 0;
        
        if (strcmp(sentences[sentenceCount], "exit") == 0) {
            break;
        }
        
        analyzeSentiment(sentences[sentenceCount]);
        sentenceCount++;
        
        if (sentenceCount >= MAX_SENTENCES) {
            printf("Maximum number of sentences reached.\n");
            break;
        }
    }

    return 0;
}