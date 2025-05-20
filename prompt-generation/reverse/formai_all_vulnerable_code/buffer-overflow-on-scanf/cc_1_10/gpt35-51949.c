//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCES 100

char* removePunctuation(char* sentence) {
    char* output = malloc(sizeof(char) * strlen(sentence));
    int i = 0, j = 0;
    while (sentence[i]) {
        if (sentence[i] != '.' && sentence[i] != ',' && sentence[i] != ';' && sentence[i] != ':' && sentence[i] != '!' && sentence[i] != '?') {
            output[j] = sentence[i];
            j++;
        }
        i++;
    }
    return output;
}

int countWords(char* sentence) {
    int count = 1;
    int i;
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    return count;
}

int countSentences(char* passage) {
    int count = 1;
    int i;
    for (i = 0; i < strlen(passage); i++) {
        if (passage[i] == '.' || passage[i] == '!' || passage[i] == '?') {
            count++;
        }
    }
    return count;
}

char* summarize(char* passage, int numSentences) {
    int i, j, k;
    char* sentences[MAX_SENTENCES];
    for (i = 0; i < MAX_SENTENCES; i++) {
        sentences[i] = NULL;
    }
    i = 0;
    j = 0;
    while (passage[i]) {
        if (passage[i] == '.' || passage[i] == '!' || passage[i] == '?') {
            char* sentence = malloc(sizeof(char) * (i - j + 2));
            strncpy(sentence, &passage[j], i - j + 1);
            sentence[i - j + 1] = '\0';
            sentences[countSentences(passage)] = removePunctuation(sentence);
            j = i + 1;
        }
        i++;
    }
    int sentenceScores[MAX_SENTENCES] = {0};
    for (i = 0; i < MAX_SENTENCES; i++) {
        if (sentences[i] == NULL) {
            break;
        }
        int wordsInSentence = countWords(sentences[i]);
        for (j = 0; j < MAX_SENTENCES; j++) {
            if (sentences[j] == NULL) {
                break;
            }
            int wordsInCommon = 0;
            for (k = 0; k < wordsInSentence; k++) {
                char* currentWord = strtok(sentences[i], " ");
                char* compareWord = strtok(sentences[j], " ");
                while (currentWord && compareWord) {
                    if (strcmp(currentWord, compareWord) == 0) {
                        wordsInCommon++;
                        break;
                    }
                    compareWord = strtok(NULL, " ");
                }
            }
            sentenceScores[i] += wordsInCommon;
        }
    }
    char* summary = malloc(sizeof(char) * MAX_STRING_LENGTH);
    for (i = 0; i < numSentences; i++) {
        int maxScore = 0;
        int maxIndex = 0;
        for (j = 0; j < countSentences(passage); j++) {
            if (sentenceScores[j] > maxScore) {
                maxScore = sentenceScores[j];
                maxIndex = j;
            }
        }
        strcat(summary, sentences[maxIndex]);
        sentenceScores[maxIndex] = 0;
    }
    for (i = 0; i < MAX_SENTENCES; i++) {
        if (sentences[i] != NULL) {
            free(sentences[i]);
        }
        else {
            break;
        }
    }
    return summary;
}

int main() {
    printf("Welcome to the Romeo and Juliet text summarizer!\n");
    printf("Please enter the passage you would like to summarize:\n");
    char passage[MAX_STRING_LENGTH];
    fgets(passage, MAX_STRING_LENGTH, stdin);
    printf("\n");
    printf("How many sentences would you like in your summary?\n");
    int numSentences;
    scanf("%d", &numSentences);
    char* summary = summarize(passage, numSentences);
    printf("\nYour summary:\n%s\n", summary);
    free(summary);
    return 0;
}