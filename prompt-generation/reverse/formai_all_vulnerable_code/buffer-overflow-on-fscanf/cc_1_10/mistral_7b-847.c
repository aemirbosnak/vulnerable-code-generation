//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 50
#define VOCAB_SIZE 100
#define MIN_SCORE -5

typedef struct {
    char word[WORD_LENGTH];
    int score;
} Word;

Word vocab[VOCAB_SIZE];

void load_vocab() {
    FILE *fp = fopen("vocab.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open vocabulary file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d", vocab[i].word, &vocab[i].score) != EOF) {
        i++;
    }
    fclose(fp);
}

int analyze_sentiment(char *text) {
    int sentiment_score = 0;
    char words[10][WORD_LENGTH];
    int words_count = 0;

    char *token = strtok(text, " .,!?:;\"'()-_");
    while (token != NULL) {
        int i;
        for (i = 0; i < words_count; i++) {
            if (strcmp(token, words[i]) == 0) {
                sentiment_score += vocab[i].score;
                break;
            }
        }

        if (i == words_count) {
            strcpy(words[words_count++], token);
            if (words_count >= 10) {
                break;
            }
        }

        token = strtok(NULL, " .,!?:;\"'()-_");
    }

    return sentiment_score;
}

int main() {
    load_vocab();

    char text[100] = "The sun sets peacefully over the tranquil lake.";
    int sentiment_score = analyze_sentiment(text);

    printf("Text: %s\n", text);
    printf("Sentiment Score: %d\n", sentiment_score);

    if (sentiment_score > MIN_SCORE) {
        printf("Positive sentiment.\n");
    } else {
        printf("Negative or neutral sentiment.\n");
    }

    return 0;
}