//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 3

typedef struct Sentiment {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Positive", 1}, {"Negative", -1}, {"Neutral", 0}};

int getSentimentValue(char *sentimentName) {
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentimentName, sentiments[i].name) == 0) {
            return sentiments[i].value;
        }
    }
    return -1;
}

char *processWord(char *word) {
    char *processedWord = malloc(MAX_WORD_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            processedWord[j++] = tolower(word[i]);
        }
    }
    processedWord[j] = '\0';
    return processedWord;
}

int analyzeSentence(char *sentence) {
    char *token = strtok(sentence, " ");
    int sentimentValue = 0;
    while (token!= NULL) {
        char *processedToken = processWord(token);
        int wordValue = getSentimentValue(processedToken);
        if (wordValue!= -1) {
            sentimentValue += wordValue;
        }
        free(processedToken);
        token = strtok(NULL, " ");
    }
    return sentimentValue;
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to analyze: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);
    int length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[--length] = '\0';
    }
    int sentimentValue = analyzeSentence(input);
    printf("The sentiment of the sentence is: ");
    if (sentimentValue > 0) {
        printf("Positive\n");
    } else if (sentimentValue < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
    return 0;
}