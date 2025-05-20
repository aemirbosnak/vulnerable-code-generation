//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *word;
    int score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {{"happy", 4}, {"joy", 4}, {"love", 3}, {"sad", -2}, {"anger", -3}, {"hate", -4}};

int getSentimentScore(char *sentence) {
    int score = 0;
    int i;
    char *word;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        word = strtok(sentence, " ");
        while (word!= NULL) {
            if (strcmp(word, sentiments[i].word) == 0) {
                score += sentiments[i].score;
            }
            word = strtok(NULL, " ");
        }
    }

    return score;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char sentence[MAX_SENTENCE_LENGTH];
    int sentenceLength = 0;
    int totalSentimentScore = 0;
    double avgSentimentScore;
    time_t start, end;

    if (argc!= 2) {
        printf("Usage:./sentiment_analysis <text_file>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    start = time(NULL);

    while ((ch = fgetc(fp))!= EOF) {
        if (isalnum(ch)) {
            sentence[sentenceLength++] = tolower(ch);
        } else if (sentenceLength > 0) {
            sentence[sentenceLength] = '\0';
            totalSentimentScore += getSentimentScore(sentence);
            sentenceLength = 0;
        }
    }

    if (sentenceLength > 0) {
        sentence[sentenceLength] = '\0';
        totalSentimentScore += getSentimentScore(sentence);
    }

    end = time(NULL);
    avgSentimentScore = (double)totalSentimentScore / (end - start);

    printf("Total sentiment score: %d\n", totalSentimentScore);
    printf("Average sentiment score per second: %.2f\n", avgSentimentScore);

    fclose(fp);
    return 0;
}