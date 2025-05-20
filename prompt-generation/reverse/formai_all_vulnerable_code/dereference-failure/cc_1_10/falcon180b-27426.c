//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORDS_LENGTH 50
#define NUM_SENTIMENTS 3

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentiment;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"positive", 0}, {"negative", 0}, {"neutral", 0}};

void initializeSentiments() {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        sentiments[i].score = 0;
    }
}

void addWordToSentiment(Sentiment *sentiment, char *word) {
    if (strcmp(word, "happy") == 0) {
        sentiment->score += 1;
    } else if (strcmp(word, "sad") == 0) {
        sentiment->score -= 1;
    }
}

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void analyzeSentiment(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        WordCount *wordCount = malloc(sizeof(WordCount));
        strcpy(wordCount->word, token);
        wordCount->count = 1;

        qsort(sentiments, NUM_SENTIMENTS, sizeof(Sentiment), compareStrings);

        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            addWordToSentiment(&sentiments[i], wordCount->word);
        }

        free(wordCount);
        token = strtok(NULL, " ");
    }
}

int main() {
    initializeSentiments();

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    analyzeSentiment(sentence);

    printf("Sentiment Analysis:\n");
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, sentiments[i].score);
    }

    return 0;
}