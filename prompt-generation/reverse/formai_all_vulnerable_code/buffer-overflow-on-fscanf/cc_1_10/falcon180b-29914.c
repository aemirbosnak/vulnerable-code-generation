//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 10
#define NUM_SENTIMENTS 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment;
} WordSentiment;

WordSentiment words[100];
int numWords;

void loadWords() {
    FILE *fp = fopen("words.txt", "r");

    if (fp == NULL) {
        printf("Error loading words.txt\n");
        exit(1);
    }

    numWords = 0;

    while (fscanf(fp, "%s %d", words[numWords].word, &words[numWords].sentiment)!= EOF) {
        numWords++;
    }

    fclose(fp);
}

void analyzeSentence(char *sentence) {
    int i, j;
    char word[MAX_WORD_LENGTH];
    int sentiment = 0;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[j] = '\0';
            j = 0;
        } else {
            word[j++] = tolower(sentence[i]);
        }
    }

    word[j] = '\0';

    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            sentiment += words[i].sentiment;
            break;
        }
    }

    if (sentiment > 0) {
        printf("Positive\n");
    } else if (sentiment < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
}

int main() {
    loadWords();

    char sentence[MAX_SENTENCE_LENGTH];

    while (true) {
        printf("Enter a sentence: ");
        fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

        analyzeSentence(sentence);
    }

    return 0;
}