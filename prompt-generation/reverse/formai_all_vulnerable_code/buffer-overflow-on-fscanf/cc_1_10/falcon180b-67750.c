//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define SENTIMENT_FILE "sentiment.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
    int sentiment;
} Word;

void loadSentimentFile(Word words[]) {
    FILE *file = fopen(SENTIMENT_FILE, "r");
    if (file == NULL) {
        printf("Error loading sentiment file.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s %d %d\n", words[wordCount].word, &words[wordCount].count, &words[wordCount].sentiment)!= EOF) {
        wordCount++;
    }

    fclose(file);
}

void analyzeSentiment(char text[], Word words[], int wordCount) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int i = 0;
        while (i < wordCount && strcmp(token, words[i].word)!= 0) {
            i++;
        }

        if (i < wordCount) {
            words[i].count++;
        }

        token = strtok(NULL, " ");
    }
}

void printSentiment(Word words[], int wordCount) {
    printf("Word\tCount\tSentiment\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\t%d\n", words[i].word, words[i].count, words[i].sentiment);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char text[10000];
    strcpy(text, argv[1]);

    Word words[MAX_WORDS];
    loadSentimentFile(words);

    analyzeSentiment(text, words, 0);

    printSentiment(words, 0);

    return 0;
}