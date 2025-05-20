//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SENTIMENT_WORDS 100

typedef struct SentimentWord {
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord sentiment_words[MAX_SENTIMENT_WORDS];

void load_sentiment_words() {
    FILE *fp = fopen("sentiment_words.txt", "r");
    if (fp == NULL) {
        perror("Error opening sentiment_words.txt");
        exit(1);
    }

    int i = 0;
    char word[20];
    int sentiment;

    while (fscanf(fp, "%s %d", word, &sentiment) != EOF) {
        sentiment_words[i].word = strdup(word);
        sentiment_words[i].sentiment = sentiment;
        i++;
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    load_sentiment_words();

    int i = 0;
    int sentiment_score = 0;

    for (i = 0; sentiment_words[i].word != NULL; i++) {
        if (strstr(text, sentiment_words[i].word) != NULL) {
            sentiment_score += sentiment_words[i].sentiment;
        }
    }

    return sentiment_score;
}

int main() {
    char text[] = "I am very happy today.";

    int sentiment_score = analyze_sentiment(text);

    if (sentiment_score > 0) {
        printf("The text is positive.\n");
    } else {
        printf("The text is negative.\n");
    }

    return 0;
}