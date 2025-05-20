//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1000

// Define the path to the sentiment lexicon
#define SENTIMENT_LEXICON_PATH "sentiment_lexicon.txt"

// Define the number of words in the sentiment lexicon
#define SENTIMENT_LEXICON_SIZE 8000

// Define the structure for a word in the sentiment lexicon
typedef struct {
    char word[100];
    int score;
} SentimentWord;

// Function to load the sentiment lexicon from a file
void loadSentimentLexicon(SentimentWord lexicon[]) {
    FILE *file = fopen(SENTIMENT_LEXICON_PATH, "r");
    if (file == NULL) {
        printf("Error: Could not open sentiment lexicon file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d\n", lexicon[count].word, &lexicon[count].score)!= EOF) {
        count++;
    }

    fclose(file);
}

// Function to calculate the sentiment score of a sentence
int calculateSentimentScore(char sentence[], SentimentWord lexicon[]) {
    int score = 0;
    int numWords = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        numWords++;

        int i;
        for (i = 0; i < SENTIMENT_LEXICON_SIZE; i++) {
            if (strcmp(token, lexicon[i].word) == 0) {
                score += lexicon[i].score;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return score / numWords;
}

// Function to print the sentiment analysis results
void printSentimentAnalysis(char sentence[], int score) {
    if (score > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }
}

int main() {
    SentimentWord lexicon[SENTIMENT_LEXICON_SIZE];
    loadSentimentLexicon(lexicon);

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int score = calculateSentimentScore(sentence, lexicon);
    printSentimentAnalysis(sentence, score);

    return 0;
}