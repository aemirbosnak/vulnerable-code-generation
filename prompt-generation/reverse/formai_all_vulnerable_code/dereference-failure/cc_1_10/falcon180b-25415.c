//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LEN 1000
#define MAX_WORDS 10000
#define MAX_WORD_LEN 50
#define POSITIVE_SCORE 1
#define NEGATIVE_SCORE -1
#define NEUTRAL_SCORE 0

typedef struct {
    char *word;
    int score;
} WordScore;

typedef struct {
    int numWords;
    WordScore *wordScores;
} SentimentResult;

SentimentResult analyzeSentiment(char *sentence) {
    SentimentResult result = {0, NULL};
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        WordScore *wordScore = malloc(sizeof(WordScore));
        wordScore->word = strdup(token);
        wordScore->score = 0;
        result.numWords++;
        result.wordScores = realloc(result.wordScores, result.numWords * sizeof(WordScore));
        result.wordScores[result.numWords - 1] = *wordScore;
        free(wordScore);
        token = strtok(NULL, " ");
    }
    return result;
}

void printSentimentResult(SentimentResult result) {
    printf("Sentiment analysis result:\n");
    printf("Number of words: %d\n", result.numWords);
    for (int i = 0; i < result.numWords; i++) {
        printf("%s: %d\n", result.wordScores[i].word, result.wordScores[i].score);
    }
}

int main() {
    srand(time(NULL));
    char sentence[MAX_SENTENCE_LEN];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LEN, stdin);
    char *cleanedSentence = malloc(MAX_SENTENCE_LEN);
    int cleanedSentenceLen = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            cleanedSentence[cleanedSentenceLen++] = tolower(sentence[i]);
        }
    }
    cleanedSentence[cleanedSentenceLen] = '\0';
    SentimentResult result = analyzeSentiment(cleanedSentence);
    printSentimentResult(result);
    free(cleanedSentence);
    return 0;
}