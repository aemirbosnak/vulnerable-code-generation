//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000 // Maximum length of a sentence
#define NUM_SENTIMENTS 6 // Number of sentiments to analyze for

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"joy", 1},
    {"sadness", -1},
    {"anger", -1},
    {"fear", -1},
    {"disgust", -1},
    {"surprise", 1}
};

int analyze_sentiment(char *sentence) {
    int sentiment_score = 0;
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            if (strcmp(token, sentiments[i].name) == 0) {
                sentiment_score += sentiments[i].value;
                break;
            }
            token = strtok(NULL, " ");
        }
    }

    return sentiment_score;
}

int main() {
    FILE *fp;
    char filename[100];
    char sentence[MAX_SENTENCE_LENGTH];
    int sentiment_score;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, fp)!= NULL) {
        int len = strlen(sentence);
        if (sentence[len - 1] == '\n') {
            sentence[len - 1] = '\0';
            len--;
        }

        sentiment_score = analyze_sentiment(sentence);

        if (sentiment_score > 0) {
            printf("Positive sentiment detected.\n");
        } else if (sentiment_score < 0) {
            printf("Negative sentiment detected.\n");
        } else {
            printf("Neutral sentiment detected.\n");
        }
    }

    fclose(fp);

    return 0;
}