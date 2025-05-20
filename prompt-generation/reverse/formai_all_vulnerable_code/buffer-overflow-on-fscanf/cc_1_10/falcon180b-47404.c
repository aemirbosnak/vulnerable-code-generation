//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 3

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *word;
    int sentiment;
} SentimentWord;

void readWords(FILE *fp, char words[][MAX_WORD_LENGTH]) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }
}

void countWords(char words[][MAX_WORD_LENGTH], int numWords, WordCount counts[]) {
    int i, j;

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }
        if (j == MAX_WORDS) {
            strcpy(counts[j].word, words[i]);
            counts[j].count = 1;
        }
    }
}

void analyzeSentiment(char words[][MAX_WORD_LENGTH], int numWords, SentimentWord sentiments[]) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i], "happy") == 0) {
            sentiments[0].word = "happy";
            sentiments[0].sentiment = 1;
        } else if (strcmp(words[i], "sad") == 0) {
            sentiments[1].word = "sad";
            sentiments[1].sentiment = -1;
        } else if (strcmp(words[i], "angry") == 0) {
            sentiments[2].word = "angry";
            sentiments[2].sentiment = -1;
        }
    }
}

void printResults(WordCount counts[], SentimentWord sentiments[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (counts[i].word!= NULL) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (sentiments[i].word!= NULL) {
            printf("%s: %d\n", sentiments[i].word, sentiments[i].sentiment);
        }
    }
}

int main() {
    FILE *fp;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordCount counts[MAX_WORDS];
    SentimentWord sentiments[NUM_SENTIMENTS];

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    readWords(fp, words);
    countWords(words, strlen(words), counts);
    analyzeSentiment(words, strlen(words), sentiments);

    printResults(counts, sentiments);

    fclose(fp);

    return 0;
}