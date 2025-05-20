//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    // Read the input text file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Create an array to store the words
    char words[1000][MAX_WORD_LENGTH];

    // Read the words from the input file
    int numWords = 0;
    while (fscanf(inputFile, "%s", words[numWords]) != EOF) {
        numWords++;
    }

    // Close the input file
    fclose(inputFile);

    // Calculate the word frequencies
    int wordFrequencies[1000];
    for (int i = 0; i < numWords; i++) {
        wordFrequencies[i] = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordFrequencies[i]++;
            }
        }
    }

    // Print the word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], wordFrequencies[i]);
    }

    // Calculate the mean word frequency
    int meanWordFrequency = 0;
    for (int i = 0; i < numWords; i++) {
        meanWordFrequency += wordFrequencies[i];
    }
    meanWordFrequency /= numWords;

    // Print the mean word frequency
    printf("Mean word frequency: %d\n", meanWordFrequency);

    // Calculate the median word frequency
    int medianWordFrequency = 0;
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (wordFrequencies[i] > wordFrequencies[j]) {
                int temp = wordFrequencies[i];
                wordFrequencies[i] = wordFrequencies[j];
                wordFrequencies[j] = temp;
            }
        }
    }
    if (numWords % 2 == 0) {
        medianWordFrequency = (wordFrequencies[numWords / 2] + wordFrequencies[numWords / 2 - 1]) / 2;
    } else {
        medianWordFrequency = wordFrequencies[numWords / 2];
    }

    // Print the median word frequency
    printf("Median word frequency: %d\n", medianWordFrequency);

    // Calculate the standard deviation of the word frequency
    int standardDeviation = 0;
    for (int i = 0; i < numWords; i++) {
        standardDeviation += (wordFrequencies[i] - meanWordFrequency) * (wordFrequencies[i] - meanWordFrequency);
    }
    standardDeviation /= numWords;
    standardDeviation = sqrt(standardDeviation);

    // Print the standard deviation of the word frequency
    printf("Standard deviation of the word frequency: %d\n", standardDeviation);

    return 0;
}