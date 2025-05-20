//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define NUM_SENTIMENTS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1}
};

int getSentimentScore(char* sentence) {
    int score = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        bool found = false;
        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(word, sentiments[i].word) == 0) {
                score += sentiments[i].sentiment;
                found = true;
                break;
            }
        }
        if (!found) {
            score += 0;
        }
        word = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH - 1) {
        printf("Sentence is too long.\n");
        return 1;
    }
    sentence[length - 1] = '\0'; // remove newline character
    int score = getSentimentScore(sentence);
    if (score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }
    return 0;
}