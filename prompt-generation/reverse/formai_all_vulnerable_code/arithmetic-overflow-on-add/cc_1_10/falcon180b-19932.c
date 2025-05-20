//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000
#define MAX_SPAM_THRESHOLD 3

// Function to count the frequency of each word in the input text
void countWords(char* input, int* wordCounts) {
    char word[MAX_WORD_LENGTH];
    char* token;
    int i = 0;

    token = strtok(input, " ");
    while (token!= NULL) {
        // Convert the word to lowercase
        for (int j = 0; j < strlen(token); j++) {
            token[j] = tolower(token[j]);
        }

        // Increment the word count
        wordCounts[i]++;
        i++;

        // Move to the next word
        token = strtok(NULL, " ");
    }
}

// Function to check if the input text is spam
int isSpam(int* wordCounts, int threshold) {
    int i;
    int spamCount = 0;

    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (wordCounts[i] >= threshold) {
            spamCount++;
        }
    }

    return spamCount;
}

int main(int argc, char** argv) {
    FILE* inputFile;
    char input[MAX_WORD_LENGTH * MAX_WORD_COUNT];
    int wordCounts[MAX_WORD_COUNT];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fgets(input, MAX_WORD_LENGTH * MAX_WORD_COUNT, inputFile);
    fclose(inputFile);

    countWords(input, wordCounts);

    int spamCount = isSpam(wordCounts, MAX_SPAM_THRESHOLD);

    if (spamCount >= MAX_SPAM_THRESHOLD) {
        printf("Input is spam.\n");
    } else {
        printf("Input is not spam.\n");
    }

    return 0;
}