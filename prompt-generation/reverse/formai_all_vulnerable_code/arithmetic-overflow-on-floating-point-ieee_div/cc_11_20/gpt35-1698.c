//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

int main() {
    // Introduction
    printf("Welcome to my awesome text summarizer!\n\n");

    // Get input text from user
    char inputText[MAX_INPUT_SIZE];
    printf("Enter the text you want to summarize:\n");
    fgets(inputText, MAX_INPUT_SIZE, stdin);

    // Calculate number of sentences in input text
    int numSentences = 0;
    for (int i = 0; i < strlen(inputText); i++) {
        if (inputText[i] == '.') {
            numSentences++;
        }
    }

    // Create array to hold individual sentences
    char sentences[numSentences][MAX_INPUT_SIZE];
    char *token = strtok(inputText, ".");
    int sentenceIndex = 0;
    while (token != NULL) {
        strcpy(sentences[sentenceIndex], token);
        sentenceIndex++;
        token = strtok(NULL, ".");
    }

    // Calculate weight of each sentence
    float weights[numSentences];
    for (int i = 0; i < numSentences; i++) {
        int sentenceLength = strlen(sentences[i]);
        int numWords = 1;
        for (int j = 0; j < sentenceLength; j++) {
            if (sentences[i][j] == ' ') {
                numWords++;
            }
        }
        weights[i] = (float) numWords / (float) sentenceLength;
    }

    // Sort sentences by weight in descending order
    for (int i = 0; i < numSentences - 1; i++) {
        for (int j = 0; j < numSentences - i - 1; j++) {
            if (weights[j] < weights[j+1]) {
                float tempWeight = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = tempWeight;

                char tempSentence[MAX_INPUT_SIZE];
                strcpy(tempSentence, sentences[j]);
                strcpy(sentences[j], sentences[j+1]);
                strcpy(sentences[j+1], tempSentence);
            }
        }
    }

    // Create the summary from the top weighted sentences
    char summary[MAX_SUMMARY_SIZE] = "";
    int summaryLength = 0;
    for (int i = 0; i < numSentences; i++) {
        if (summaryLength + strlen(sentences[i]) <= MAX_SUMMARY_SIZE) {
            strcat(summary, sentences[i]);
            summaryLength += strlen(sentences[i]);
            if (i < numSentences - 1) {
                strcat(summary, ".");
                summaryLength++;
            }
        }
    }

    // Display the summary to the user
    printf("\nHere is your summarized text:\n");
    printf("%s\n", summary);

    return 0;
}