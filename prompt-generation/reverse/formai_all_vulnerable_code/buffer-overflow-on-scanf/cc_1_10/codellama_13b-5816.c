//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Sentiment Analysis

#define MAX_LEN 100
#define MAX_WORD_LEN 20
#define MAX_SENTIMENT 10

typedef struct {
    char word[MAX_WORD_LEN];
    int sentiment;
} Word;

Word words[MAX_LEN];

int get_sentiment(char *word) {
    if (strcmp(word, "good") == 0) {
        return 1;
    } else if (strcmp(word, "bad") == 0) {
        return -1;
    } else {
        return 0;
    }
}

int get_sentiment_from_words(char *words) {
    int sentiment = 0;
    char *token = strtok(words, " ");

    while (token != NULL) {
        sentiment += get_sentiment(token);
        token = strtok(NULL, " ");
    }

    return sentiment;
}

int main() {
    char sentence[MAX_LEN];
    scanf("%s", sentence);

    int sentiment = get_sentiment_from_words(sentence);

    if (sentiment > 0) {
        printf("The sentiment is positive.\n");
    } else if (sentiment < 0) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }

    return 0;
}