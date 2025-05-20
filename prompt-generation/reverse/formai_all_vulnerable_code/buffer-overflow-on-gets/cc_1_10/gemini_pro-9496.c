//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(const char *str) {
    int wordCount = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    return wordCount;
}

// Function to print the top N words in a string
void printTopWords(const char *str, int n) {
    // Create an array of word counts
    int wordCounts[10000] = {0};

    // Tokenize the string and count the number of occurrences of each word
    char *token = strtok(str, " ");
    while (token != NULL) {
        int index = atoi(token);
        wordCounts[index]++;
        token = strtok(NULL, " ");
    }

    // Find the top N words with the highest counts
    int topWords[n];
    int topCounts[n];
    for (int i = 0; i < n; i++) {
        int maxCount = 0;
        int maxIndex = -1;

        for (int j = 0; j < 10000; j++) {
            if (wordCounts[j] > maxCount) {
                maxCount = wordCounts[j];
                maxIndex = j;
            }
        }

        topWords[i] = maxIndex;
        topCounts[i] = maxCount;

        wordCounts[maxIndex] = 0;
    }

    // Print the top N words and their counts
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", topWords[i], topCounts[i]);
    }
}

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Count the number of words in the string
    int wordCount = countWords(str);

    // Print the word count
    printf("The string contains %d words.\n", wordCount);

    // Print the top 10 words in the string
    printTopWords(str, 10);

    return 0;
}