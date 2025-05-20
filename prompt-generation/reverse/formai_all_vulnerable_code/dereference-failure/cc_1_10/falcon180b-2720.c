//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENT_LABELS 3

typedef struct {
    char *word;
    int score;
} WordScore;

typedef struct {
    char *label;
    int threshold;
} SentimentLabel;

SentimentLabel labels[NUM_SENTIMENT_LABELS] = {
    {"positive", 2},
    {"neutral", 0},
    {"negative", -2}
};

int compareWords(const void *a, const void *b) {
    const WordScore *wordA = (const WordScore *)a;
    const WordScore *wordB = (const WordScore *)b;

    return wordB->score - wordA->score;
}

int getSentimentScore(char *sentence, SentimentLabel labels[NUM_SENTIMENT_LABELS]) {
    int score = 0;
    char *token;
    WordScore words[MAX_SENTENCE_LENGTH];

    token = strtok(sentence, " ");
    while (token!= NULL) {
        WordScore *word = NULL;
        for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
            if (words[i].word == NULL) {
                words[i].word = strdup(token);
                words[i].score = 0;
                word = &words[i];
                break;
            }
        }

        if (word == NULL) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        int len = strlen(token);
        for (int i = 0; i < len; i++) {
            if (isalpha(token[i])) {
                word->score += (int)token[i] - 64;
            }
        }

        token = strtok(NULL, " ");
    }

    qsort(words, MAX_SENTENCE_LENGTH, sizeof(WordScore), compareWords);

    for (int i = 0; i < NUM_SENTIMENT_LABELS; i++) {
        if (score >= labels[i].threshold) {
            return i;
        }
    }

    return -1;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    SentimentLabel result = labels[getSentimentScore(sentence, labels)];

    if (result.label == NULL) {
        printf("Error: Invalid input.\n");
    } else {
        printf("Sentiment: %s\n", result.label);
    }

    return 0;
}