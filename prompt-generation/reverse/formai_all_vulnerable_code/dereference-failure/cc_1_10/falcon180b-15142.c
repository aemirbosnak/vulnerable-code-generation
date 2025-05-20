//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"joy", 1},
    {"sadness", -1},
    {"anger", -1},
    {"fear", -1},
    {"surprise", 1},
    {"disgust", -1}
};

int getSentimentValue(char *sentimentName) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiments[i].name, sentimentName) == 0) {
            return sentiments[i].value;
        }
    }
    return 0;
}

int getMaxIndex(int *arr, int size) {
    int maxIndex = 0;
    int maxValue = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxIndex = i;
            maxValue = arr[i];
        }
    }
    return maxIndex;
}

void analyzeSentence(char *sentence) {
    int i, j;
    int wordCount = 0;
    int *wordScores = malloc(MAX_SENTENCE_LENGTH * sizeof(int));
    memset(wordScores, 0, MAX_SENTENCE_LENGTH * sizeof(int));

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            if (wordCount < MAX_SENTENCE_LENGTH) {
                wordScores[wordCount] = getSentimentValue(sentence + i);
                wordCount++;
            }
        }
    }

    int totalScore = 0;
    for (i = 0; i < wordCount; i++) {
        totalScore += wordScores[i];
    }

    int maxIndex = getMaxIndex(wordScores, wordCount);
    int maxScore = wordScores[maxIndex];

    if (maxScore > 0) {
        printf("The sentence expresses joy.\n");
    } else if (maxScore < 0) {
        printf("The sentence expresses sadness.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    free(wordScores);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    analyzeSentence(sentence);

    return 0;
}