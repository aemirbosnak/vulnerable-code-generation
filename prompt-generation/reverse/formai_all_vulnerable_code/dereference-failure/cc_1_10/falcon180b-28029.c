//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

struct Word {
    char *word;
    int sentiment;
};

struct Sentiment {
    int positive;
    int negative;
    int neutral;
};

void loadWords(struct Word *words) {
    FILE *file = fopen("words.txt", "r");
    char line[100];
    int count = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, " ");
        if (count >= MAX_WORDS) {
            break;
        }
        words[count].word = strdup(word);
        words[count].sentiment = NEUTRAL;
        count++;
    }

    fclose(file);
}

void analyzeSentiment(struct Sentiment *sentiment, struct Word *words, int numWords) {
    sentiment->positive = 0;
    sentiment->negative = 0;
    sentiment->neutral = 0;

    char *text = "I love this product. It works great and I would recommend it to anyone.";
    int textLength = strlen(text);
    char *token = strtok(text, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                if (words[i].sentiment == POSITIVE) {
                    sentiment->positive++;
                } else if (words[i].sentiment == NEGATIVE) {
                    sentiment->negative++;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < numWords; i++) {
        if (words[i].sentiment == NEUTRAL) {
            sentiment->neutral++;
        }
    }
}

int main() {
    struct Word words[MAX_WORDS];
    loadWords(words);

    struct Sentiment sentiment;
    analyzeSentiment(&sentiment, words, MAX_WORDS);

    printf("Positive: %d\n", sentiment.positive);
    printf("Negative: %d\n", sentiment.negative);
    printf("Neutral: %d\n", sentiment.neutral);

    return 0;
}