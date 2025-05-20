//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {{"happy", 1}, {"sad", -1}, {"angry", -1}, {"excited", 1}, {"bored", -1}, {"confused", 0}};

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int getSentimentScore(char *sentence) {
    int score = 0;
    char *token;
    token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                score += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

void loadSentiments() {
    FILE *fp;
    char line[MAX_SENTENCE_LENGTH];
    fp = fopen(SENTIMENT_FILE, "r");
    if (fp!= NULL) {
        while (fgets(line, MAX_SENTENCE_LENGTH, fp)!= NULL) {
            char *token;
            token = strtok(line, ",");
            int i;
            for (i = 0; i < NUM_SENTIMENTS; i++) {
                if (strcmp(token, sentiments[i].word) == 0) {
                    sentiments[i].score = atoi(strtok(NULL, ","));
                    break;
                }
            }
        }
        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_SENTENCE_LENGTH];
    loadSentiments();
    printf("Enter a sentence: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    int score = getSentimentScore(input);
    if (score > 0) {
        printf("The sentence expresses a positive sentiment.\n");
    } else if (score < 0) {
        printf("The sentence expresses a negative sentiment.\n");
    } else {
        printf("The sentence expresses a neutral sentiment.\n");
    }
    return 0;
}