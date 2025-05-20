//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 3

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Positive", 1}, {"Negative", -1}, {"Neutral", 0}};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(char *sentence) {
    int sentiment_index = get_sentiment_index("Positive");
    int length = strlen(sentence);
    int i;

    for (i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            if (tolower(sentence[i]) == 'a' || tolower(sentence[i]) == 'e' || tolower(sentence[i]) == 'i' || tolower(sentence[i]) == 'o' || tolower(sentence[i]) == 'u') {
                sentiment_index++;
            }
        }
    }

    return sentiments[sentiment_index].value;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int sentiment_value = analyze_sentiment(sentence);

    printf("The sentiment of the sentence is: %s (%d)\n", sentiments[sentiment_value].name, sentiment_value);

    return 0;
}