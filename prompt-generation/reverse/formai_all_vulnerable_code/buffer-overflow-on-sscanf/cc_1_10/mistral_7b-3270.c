//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WORD_SIZE 50
#define NUM_WORDS 10000
#define SENTIMENT_SCORE_THRESHOLD 0.05

typedef struct {
    char word[WORD_SIZE];
    double sentiment_score;
} Word;

Word words[NUM_WORDS];

void load_sentiment_scores() {
    FILE *file = fopen("sentiment_scores.csv", "r");
    int i = 0;

    if (file != NULL) {
        char line[1000];
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%s %lf", words[i].word, &words[i].sentiment_score);
            i++;
        }
        fclose(file);
    }
}

int main() {
    load_sentiment_scores();

    char input[100];
    double total_sentiment_score = 0.0;
    int num_words = 0;

    printf("Enter text for sentiment analysis: ");
    scanf("%s", input);

    char *token = strtok(input, " ");
    while (token != NULL) {
        int i;
        double sentiment_score = 0.0;

        for (i = 0; i < NUM_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                sentiment_score = words[i].sentiment_score;
                break;
            }
        }

        if (i < NUM_WORDS) {
            total_sentiment_score += sentiment_score;
            num_words++;
        }

        token = strtok(NULL, " ");
    }

    double average_sentiment_score = total_sentiment_score / num_words;

    if (average_sentiment_score > SENTIMENT_SCORE_THRESHOLD) {
        printf("Positive sentiment\n");
    } else {
        printf("Negative sentiment\n");
    }

    return 0;
}