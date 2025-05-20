//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000
#define SPAM_THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char input[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    int i, j;

    // Read in input
    printf("Enter text to analyze: ");
    fgets(input[numWords], MAX_WORD_LENGTH, stdin);
    while (input[numWords][0]!= '\n') {
        numWords++;
        printf("Enter next line: ");
        fgets(input[numWords], MAX_WORD_LENGTH, stdin);
    }

    // Count word frequencies
    WordFrequency *wordFrequencies = (WordFrequency*) malloc(numWords * sizeof(WordFrequency));
    for (i = 0; i < numWords; i++) {
        char *word = strtok(input[i], " ");
        while (word!= NULL) {
            int found = 0;
            for (j = 0; j < numWords; j++) {
                if (strcmp(word, input[j]) == 0) {
                    wordFrequencies[j].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordFrequencies[numWords - 1].word, word);
                wordFrequencies[numWords - 1].frequency = 1;
                numWords++;
                break;
            }
            word = strtok(NULL, " ");
        }
    }

    // Calculate spam probability
    int totalWords = 0;
    for (i = 0; i < numWords; i++) {
        totalWords += wordFrequencies[i].frequency;
    }
    float spamProbability = 0.0;
    for (i = 0; i < numWords; i++) {
        if (wordFrequencies[i].frequency > 1) {
            spamProbability += (float) wordFrequencies[i].frequency / totalWords;
        }
    }

    // Print results
    printf("Spam probability: %.2f\n", spamProbability);
    printf("Threshold: %.2f\n", SPAM_THRESHOLD);
    if (spamProbability > SPAM_THRESHOLD) {
        printf("Input is likely spam.\n");
    } else {
        printf("Input is likely not spam.\n");
    }

    return 0;
}