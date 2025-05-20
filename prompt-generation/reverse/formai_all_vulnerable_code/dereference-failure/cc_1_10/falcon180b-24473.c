//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 200

// Function to remove punctuation from a given string
void removePunctuation(char* str) {
    int i = 0, j = 0;
    while (str[i]!= '\0') {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Function to split the input text into sentences
void splitSentences(char* text, char** sentences) {
    char* sentence = strtok(text, ".");
    int sentenceCount = 0;
    while (sentence!= NULL) {
        if (sentenceCount >= MAX_SENTENCE_LENGTH) {
            break;
        }
        sentences[sentenceCount] = sentence;
        sentenceCount++;
        sentence = strtok(NULL, ".");
    }
}

// Function to generate the summary
void generateSummary(char** sentences, int sentenceCount, char* summary) {
    int i = 0;
    for (i = 0; i < sentenceCount; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, " ");
    }
    if (strlen(summary) > SUMMARY_LENGTH) {
        summary[SUMMARY_LENGTH - 1] = '\0';
    }
}

int main() {
    FILE* inputFile;
    char text[100000];
    char* sentences[MAX_SENTENCE_LENGTH];
    char summary[SUMMARY_LENGTH];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    fread(text, 1, fileSize, inputFile);
    fclose(inputFile);

    removePunctuation(text);

    splitSentences(text, sentences);

    generateSummary(sentences, strlen(text), summary);

    printf("Summary:\n%s\n", summary);

    return 0;
}