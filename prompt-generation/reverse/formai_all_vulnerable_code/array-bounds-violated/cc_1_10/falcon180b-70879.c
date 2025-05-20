//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 6

typedef struct Sentiment {
    char *name;
    double weight;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1.0},
    {"sad", -1.0},
    {"angry", -1.0},
    {"excited", 1.0},
    {"bored", -1.0},
    {"confused", 0.0}
};

double get_sentiment_score(char *sentence) {
    double score = 0.0;
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    Sentiment *sentiment;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[k] = '\0';
            k = 0;
        } else {
            word[k++] = tolower(sentence[i]);
        }
    }

    for (j = 0; j < NUM_SENTIMENTS; j++) {
        sentiment = &sentiments[j];
        if (strstr(sentence, sentiment->name)) {
            score += sentiment->weight;
        }
    }

    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    double score = get_sentiment_score(sentence);

    if (score > 0.0) {
        printf("The sentence expresses a positive sentiment.\n");
    } else if (score < 0.0) {
        printf("The sentence expresses a negative sentiment.\n");
    } else {
        printf("The sentence expresses a neutral sentiment.\n");
    }

    return 0;
}