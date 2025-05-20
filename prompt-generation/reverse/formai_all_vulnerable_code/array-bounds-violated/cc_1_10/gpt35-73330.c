//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

// function to count number of occurrences of a substring
int countSubstring(char* str, char* substr) {
    int count = 0;
    char* ptr = strstr(str, substr);
    while (ptr) {
        count++;
        ptr = strstr(ptr + 1, substr);
    }
    return count;
}

// function to remove trailing whitespace in a string
void removeTrailingWhitespace(char* str) {
    int i = strlen(str) - 1;
    while (i >= 0 && str[i] == ' ') {
        str[i] = '\0';
        i--;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Enter text to summarize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int numSentences = countSubstring(input, ".");
    if (numSentences == 0) {
        printf("Error: input contains no sentences.\n");
        return 1;
    }

    int sentenceLengths[numSentences];
    int sentenceStart[numSentences];
    int currentLength = 0;
    int sentenceCount = 0;
    sentenceStart[0] = 0;

    // split input into sentences and calculate lengths
    for (int i = 0; i < strlen(input); i++) {
        currentLength++;
        if (input[i] == '.') {
            sentenceLengths[sentenceCount] = currentLength;
            sentenceStart[++sentenceCount] = i + 1;
            currentLength = 0;
        }
    }

    // calculate average sentence length
    int totalLength = 0;
    for (int i = 0; i < numSentences; i++) {
        totalLength += sentenceLengths[i];
    }
    int avgLength = totalLength / numSentences;

    // choose sentences to include in summary
    int summaryCount = 0;
    for (int i = 0; i < numSentences; i++) {
        if (strchr(input + sentenceStart[i], '.') == NULL) {
            removeTrailingWhitespace(input + sentenceStart[i]);
            if (strlen(input + sentenceStart[i]) < avgLength * 0.9) {
                strcat(summary, input + sentenceStart[i]);
                strcat(summary, ". ");
                summaryCount++;
            }
        }
    }

    // print summary
    printf("\nSummary:\n");
    if (summaryCount == 0) {
        printf("No summary generated.\n");
    } else {
        printf("%s\n", summary);
    }

    return 0;
}