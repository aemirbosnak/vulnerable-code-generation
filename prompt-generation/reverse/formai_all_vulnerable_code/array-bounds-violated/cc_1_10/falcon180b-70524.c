//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 3

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentiment;
    int positive_words;
    int negative_words;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Positive", 0, 0},
    {"Negative", 0, 0},
    {"Neutral", 0, 0}
};

void add_word(char *word) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, sentiments[i].sentiment) == 0) {
            sentiments[i].positive_words++;
            break;
        }
    }
}

int main() {
    FILE *fp;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORDS][20];
    int num_words = 0;
    int i, j;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, fp)!= NULL) {
        num_words = 0;
        for (i = 0; i < strlen(sentence); i++) {
            if (isspace(sentence[i])) {
                word[num_words][strlen(word[num_words]) - 1] = '\0';
                num_words++;
            } else {
                strncat(word[num_words], &sentence[i], 1);
            }
        }

        for (i = 0; i < num_words; i++) {
            for (j = 0; j < NUM_SENTIMENTS; j++) {
                if (strcmp(word[i], sentiments[j].sentiment) == 0) {
                    sentiments[j].positive_words++;
                    break;
                }
            }
        }
    }

    fclose(fp);

    printf("Sentiment Analysis:\n");
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, sentiments[i].positive_words);
    }

    return 0;
}