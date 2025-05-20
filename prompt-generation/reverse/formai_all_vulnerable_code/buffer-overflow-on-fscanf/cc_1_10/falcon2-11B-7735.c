//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the number of occurrences of a word in a string
int countOccurrences(const char* str, const char* word) {
    int count = 0;
    int len = strlen(word);
    while (*str) {
        if (strncmp(str, word, len) == 0) {
            count++;
            str += len;
        }
        str++;
    }
    return count;
}

// Function to remove stopwords from a string
void removeStopwords(char* str, int stopwords[]) {
    int i, j, k;
    for (i = 0; str[i]; i++) {
        if (stopwords[i] == 0) {
            for (j = i + 1; j <= i + 100; j++) {
                str[j] = str[j + 1];
            }
            str[i] = '\0';
            for (k = i; k < strlen(str); k++) {
                stopwords[k] = 1;
            }
        }
    }
}

// Function to calculate the summary score of a string
int calculateSummaryScore(char* str, int stopwords[]) {
    int i, j, k, sum = 0;
    for (i = 0; str[i]; i++) {
        for (j = i + 1; str[j]; j++) {
            if (stopwords[i] == 0 && stopwords[j] == 0) {
                sum += countOccurrences(str + i, str + j);
            }
        }
    }
    return sum;
}

int main() {
    char str[10000];
    int stopwords[10000];
    int i, j;

    printf("Enter a text: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a stopword list: ");
    for (i = 0; i < 10000; i++) {
        fscanf(stdin, "%d", &stopwords[i]);
    }

    removeStopwords(str, stopwords);

    int summaryScore = calculateSummaryScore(str, stopwords);

    printf("Summary score: %d\n", summaryScore);

    return 0;
}