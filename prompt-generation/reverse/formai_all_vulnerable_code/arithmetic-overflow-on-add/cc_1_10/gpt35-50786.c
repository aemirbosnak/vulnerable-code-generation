//FormAI DATASET v1.0 Category: Text Summarizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50000
#define MAX_SENTENCE_NUM 1000
#define MAX_SENTENCE_LEN 1000
#define SUMMARY_LEN 1000

void removePunctuation(char *s) {
    int i = 0, j = 0;
    while (s[i]) {
        if (ispunct((unsigned char)s[i])) {
            i++;
            continue;
        }
        s[j] = s[i];
        j++;
        i++;
    }
    s[j] = '\0';
}

int countWords(char *sentence) {
    int i = 0, count = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            count++;
        }
        i++;
    }
    return count + 1;
}

void getSentences(char *input, char sentences[MAX_SENTENCE_NUM][MAX_SENTENCE_LEN], int *numSentences) {
    int i = 0, j = 0, k = 0;
    while (input[i] != '\0') {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentences[j][k] = '\0';
            removePunctuation(sentences[j]);
            j++;
            k = 0;
        } else {
            sentences[j][k] = input[i];
            k++;
        }
        i++;
    }
    *numSentences = j;
}

void getWordCounts(char sentences[MAX_SENTENCE_NUM][MAX_SENTENCE_LEN], int counts[MAX_SENTENCE_NUM], int numSentences) {
    int i = 0;
    for (i = 0; i < numSentences; i++) {
        counts[i] = countWords(sentences[i]);
    }
}

void initializeSummary(char summary[SUMMARY_LEN]) {
    memset(&summary[0], 0, sizeof(summary));
}

void appendSummary(char summary[SUMMARY_LEN], char *sentence) {
    strcat(summary, sentence);
    strcat(summary, " ");
}

void summarize(char *input, char summary[SUMMARY_LEN]) {
    char sentences[MAX_SENTENCE_NUM][MAX_SENTENCE_LEN];
    int numSentences = 0;

    getSentences(input, sentences, &numSentences);

    int counts[MAX_SENTENCE_NUM];
    getWordCounts(sentences, counts, numSentences);

    int targetWordCount = 0.4 * countWords(input);
    int currentWordCount = 0;
    int i = 0;

    initializeSummary(summary);

    while (currentWordCount < targetWordCount) {
        appendSummary(summary, sentences[i]);
        currentWordCount += counts[i];
        i++;
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the text to summarize: \n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char summary[SUMMARY_LEN];
    summarize(input, summary);

    printf("\nSummary:\n%s\n", summary);

    return 0;
}