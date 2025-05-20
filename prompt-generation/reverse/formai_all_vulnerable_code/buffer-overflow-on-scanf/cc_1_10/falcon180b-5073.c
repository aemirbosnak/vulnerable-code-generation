//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

// Function to count the number of words in a sentence
int countWords(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to extract keywords from a sentence
void extractKeywords(char *sentence, char *keywords[]) {
    int i = 0;
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (i >= MAX_WORDS) {
            break;
        }
        strcpy(keywords[i], word);
        i++;
        word = strtok(NULL, " ");
    }
}

// Function to compare two strings
int compareStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2? len1 : len2;
    int matchCount = 0;
    for (int i = 0; i < minLen; i++) {
        if (str1[i] == str2[i]) {
            matchCount++;
        }
    }
    return (float)matchCount / minLen;
}

// Function to print keywords and their relevance to the input string
void printKeywords(char *input, char *keywords[], int numKeywords) {
    printf("Keywords:\n");
    for (int i = 0; i < numKeywords; i++) {
        printf("%s (relevance: %.2f)\n", keywords[i], compareStrings(input, keywords[i]));
    }
}

int main() {
    char input[MAX_WORD_LEN];
    printf("Enter a sentence: ");
    scanf("%s", input);

    char keywords[MAX_WORDS][MAX_WORD_LEN];
    int numKeywords = 0;

    // Extract keywords from the input string
    extractKeywords(input, keywords);
    numKeywords = countWords(input);

    printKeywords(input, keywords, numKeywords);

    return 0;
}