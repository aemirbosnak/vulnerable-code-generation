//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int countWords(char* str);
int countSentences(char* str);
int countParagraphs(char* str);

// Main function
int main(int argc, char** argv) {
    char* inputStr = NULL;
    int inputLen = 0;
    char* token = NULL;
    int wordCount = 0;
    int sentenceCount = 0;
    int paragraphCount = 0;

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", inputStr);

    // Get input string length
    inputLen = strlen(inputStr);

    // Count words in input string
    token = strtok(inputStr, " ");
    while (token!= NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Count sentences in input string
    token = strtok(inputStr, ".");
    while (token!= NULL) {
        sentenceCount++;
        token = strtok(NULL, ".");
    }

    // Count paragraphs in input string
    token = strtok(inputStr, "\n");
    while (token!= NULL) {
        paragraphCount++;
        token = strtok(NULL, "\n");
    }

    // Print results
    printf("Number of words: %d\n", wordCount);
    printf("Number of sentences: %d\n", sentenceCount);
    printf("Number of paragraphs: %d\n", paragraphCount);

    return 0;
}

// Function to count words in a string
int countWords(char* str) {
    char* token = strtok(str, " ");
    int wordCount = 0;

    while (token!= NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    return wordCount;
}

// Function to count sentences in a string
int countSentences(char* str) {
    char* token = strtok(str, ".");
    int sentenceCount = 0;

    while (token!= NULL) {
        sentenceCount++;
        token = strtok(NULL, ".");
    }

    return sentenceCount;
}

// Function to count paragraphs in a string
int countParagraphs(char* str) {
    char* token = strtok(str, "\n");
    int paragraphCount = 0;

    while (token!= NULL) {
        paragraphCount++;
        token = strtok(NULL, "\n");
    }

    return paragraphCount;
}