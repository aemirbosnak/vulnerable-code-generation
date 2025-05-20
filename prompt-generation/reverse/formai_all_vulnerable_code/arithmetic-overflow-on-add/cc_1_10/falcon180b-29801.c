//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to remove punctuation from a string
void removePunctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            continue;
        }
        str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

// Function to split a string into words
void splitWords(char* str, char** words) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            continue;
        }
        words[j++] = str[i];
    }
    words[j] = '\0';
}

// Function to calculate the frequency of a word
void calculateFrequency(char** words, int numWords, char* word, int* freq) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i], word) == 0) {
            (*freq)++;
        }
    }
}

// Function to print the summary
void printSummary(int numWords, char** words, int* freq) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (freq[i] > 0) {
            printf("%s: %d\n", words[i], freq[i]);
        }
    }
}

int main() {
    char input[10000];
    char* words[1000];
    int numWords, i, j, freq[1000];

    // Read input from user
    printf("Enter a text to summarize: ");
    fgets(input, 10000, stdin);

    // Remove punctuation and split into words
    removePunctuation(input);
    splitWords(input, words);
    numWords = 0;
    for (i = 0; words[i]!= NULL; i++) {
        numWords++;
    }

    // Calculate frequency of each word
    for (i = 0; i < numWords; i++) {
        for (j = 0; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
            }
        }
    }

    // Print summary
    printf("Summary:\n");
    printSummary(numWords, words, freq);

    return 0;
}