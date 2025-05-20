//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 3

typedef struct {
    char *sentiment;
    int count;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Positive", 0}, {"Negative", 0}, {"Neutral", 0}};

void analyze_sentiment(char *sentence) {
    int i, j;
    char word[MAX_SENTENCE_LENGTH];
    int sentiment_index;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[j] = '\0';
            j = 0;
        } else {
            word[j++] = tolower(sentence[i]);
        }
    }

    word[j] = '\0';

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strstr(word, sentiments[i].sentiment)) {
            sentiment_index = i;
            break;
        }
    }

    sentiments[sentiment_index].count++;
}

void print_sentiments() {
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, sentiments[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        analyze_sentiment(sentence);
    }

    print_sentiments();

    return 0;
}