//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

struct sentiment {
    char *name;
    int value;
};

struct sentiment sentiments[NUM_SENTIMENTS] = {
    {"joy", 1},
    {"sadness", -1},
    {"anger", -1},
    {"fear", -1},
    {"surprise", 1},
    {"neutral", 0}
};

int get_sentiment_index(char *sentiment_name) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void analyze_sentence(char *sentence) {
    int sentiment_index = -1;
    int total_sentiment_value = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        sentiment_index = get_sentiment_index(token);
        if (sentiment_index!= -1) {
            total_sentiment_value += sentiments[sentiment_index].value;
        }
        token = strtok(NULL, " ");
    }

    printf("Sentiment analysis result: %s (%d)\n", sentiments[sentiment_index].name, total_sentiment_value);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to analyze:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    analyze_sentence(sentence);

    return 0;
}