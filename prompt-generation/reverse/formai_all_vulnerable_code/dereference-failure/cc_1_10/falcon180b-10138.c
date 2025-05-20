//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 6

typedef struct Sentiment {
    char *name;
    int count;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Positive", 0}, {"Negative", 0}, {"Neutral", 0}, {"Happy", 0}, {"Sad", 0}, {"Angry", 0}};

void updateSentiments(char *sentence) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (strstr(sentence, sentiments[i].name)) {
            sentiments[i].count++;
        }
    }
}

void printSentiments() {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].name, sentiments[i].count);
    }
}

int main() {
    srand(time(NULL));

    char *sentences[MAX_SENTENCE_LENGTH];
    int numSentences = 0;

    while (numSentences < MAX_SENTENCE_LENGTH) {
        char *sentence = malloc(sizeof(char) * (rand() % 50 + 1));
        strcpy(sentence, "");

        int length = 0;
        while (length < strlen(sentence)) {
            char c = rand() % 26 + 'a';
            if (isalpha(c)) {
                sentence[length] = toupper(c);
                length++;
            }
        }

        sentences[numSentences] = sentence;
        numSentences++;
    }

    for (int i = 0; i < numSentences; i++) {
        updateSentiments(sentences[i]);
    }

    printSentiments();

    for (int i = 0; i < numSentences; i++) {
        free(sentences[i]);
    }

    return 0;
}