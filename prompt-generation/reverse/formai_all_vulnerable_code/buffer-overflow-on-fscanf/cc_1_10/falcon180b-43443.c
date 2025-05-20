//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <regex.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_SENTIMENT_LABELS 10
#define MAX_SENTIMENT_VALUE 1000
#define MAX_SENTIMENT_SCORE 1000

typedef struct {
    char *label;
    int value;
} SentimentLabel;

typedef struct {
    int numLabels;
    SentimentLabel labels[MAX_SENTIMENT_LABELS];
} SentimentModel;

int loadSentimentModel(SentimentModel *model, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    int numLabels = 0;
    SentimentLabel label;

    while (fscanf(fp, "%s %d\n", label.label, &label.value) == 2) {
        if (numLabels >= MAX_SENTIMENT_LABELS) {
            break;
        }

        model->labels[numLabels++] = label;
    }

    fclose(fp);

    model->numLabels = numLabels;
    return 0;
}

int sentimentAnalysis(const char *sentence, SentimentModel *model) {
    int score = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < model->numLabels; i++) {
            if (strcasecmp(token, model->labels[i].label) == 0) {
                score += model->labels[i].value;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return score;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <sentence> <model_file>\n", argv[0]);
        return 1;
    }

    SentimentModel model;
    if (loadSentimentModel(&model, argv[2])!= 0) {
        fprintf(stderr, "Error loading sentiment model.\n");
        return 1;
    }

    int score = sentimentAnalysis(argv[1], &model);
    printf("Sentiment score: %d\n", score);

    return 0;
}