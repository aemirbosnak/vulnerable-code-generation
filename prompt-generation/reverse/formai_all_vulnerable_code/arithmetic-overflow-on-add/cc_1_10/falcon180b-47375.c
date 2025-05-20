//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define SENTIMENT_THRESHOLD 0.5
#define NUM_SENTIMENTS 3

typedef struct {
    char *word;
    int score;
} WordScore;

typedef struct {
    int positive;
    int negative;
    int neutral;
} Sentiment;

void init_word_scores(WordScore *scores) {
    scores[0].word = "happy";
    scores[0].score = 1;

    scores[1].word = "sad";
    scores[1].score = -1;

    scores[2].word = "angry";
    scores[2].score = -1;
}

int get_word_score(char *word, WordScore *scores) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, scores[i].word) == 0) {
            return scores[i].score;
        }
    }
    return 0;
}

void process_sentence(char *sentence, Sentiment *sentiment) {
    char *word;
    int length;
    WordScore *scores = (WordScore *)malloc(sizeof(WordScore) * NUM_SENTIMENTS);
    init_word_scores(scores);

    length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        length = MAX_SENTENCE_LENGTH;
    }

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        word = tolower(token);
        int score = get_word_score(word, scores);
        if (score > 0) {
            sentiment->positive++;
        } else if (score < 0) {
            sentiment->negative++;
        } else {
            sentiment->neutral++;
        }
        token = strtok(NULL, " ");
    }

    free(scores);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    Sentiment sentiment;
    process_sentence(sentence, &sentiment);

    double positive_percent = (double)sentiment.positive / (sentiment.positive + sentiment.negative + sentiment.neutral) * 100;
    double negative_percent = (double)sentiment.negative / (sentiment.positive + sentiment.negative + sentiment.neutral) * 100;
    double neutral_percent = (double)sentiment.neutral / (sentiment.positive + sentiment.negative + sentiment.neutral) * 100;

    printf("Sentiment analysis:\n");
    printf("Positive: %d (%d%%)\n", sentiment.positive, (int)positive_percent);
    printf("Negative: %d (%d%%)\n", sentiment.negative, (int)negative_percent);
    printf("Neutral: %d (%d%%)\n", sentiment.neutral, (int)neutral_percent);

    return 0;
}