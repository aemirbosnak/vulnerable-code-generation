//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 100

typedef struct SentimentWord {
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord sentimentWords[MAX_SENTIMENT_WORDS];

void loadSentimentWords() {
    FILE *fp = fopen("sentiment_words.txt", "r");
    if (fp == NULL) {
        return;
    }

    int i = 0;
    char word[20];
    while (fscanf(fp, "%s", word) != EOF) {
        sentimentWords[i].word = strdup(word);
        sentimentWords[i].sentiment = rand() % 2 - 1;
        i++;
    }

    fclose(fp);
}

int analyzeSentiment(char *sentence) {
    loadSentimentWords();

    int sentiment = 0;
    for (int i = 0; sentimentWords[i].word != NULL; i++) {
        if (strstr(sentence, sentimentWords[i].word) != NULL) {
            sentiment += sentimentWords[i].sentiment;
        }
    }

    return sentiment;
}

int main() {
    char sentence[] = "I am very happy today.";
    int sentiment = analyzeSentiment(sentence);

    if (sentiment > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else {
        printf("The sentiment of the sentence is negative.\n");
    }

    return 0;
}