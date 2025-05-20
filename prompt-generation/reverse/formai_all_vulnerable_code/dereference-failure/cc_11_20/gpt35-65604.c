//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    // Initialize variables
    char input[500];
    char *word;
    int i, j, k, count, wordCount = 0, sentimentValue = 0;
    WordCount wordCounts[500];

    // Read input
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // Count number of words and store in wordCounts array
    word = strtok(input, " ");
    while (word != NULL) {
        // Check if word already exists in array
        for (i = 0; i < wordCount; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }

        // If word doesn't exist in array, add it
        if (i == wordCount) {
            wordCounts[i].word = (char*)malloc(strlen(word) + 1);
            strcpy(wordCounts[i].word, word);
            wordCounts[i].count = 1;
            wordCount++;
        }

        // Get next word
        word = strtok(NULL, " ");
    }

    // Calculate sentiment value based on word counts
    for (i = 0; i < wordCount; i++) {
        // Check if word is positive
        char positiveWords[10][20] = {"good", "great", "wonderful", "excellent", "fantastic", "amazing", "love", "like", "happy", "pleased"};
        for (j = 0; j < 10; j++) {
            if (strcmp(wordCounts[i].word, positiveWords[j]) == 0) {
                sentimentValue += wordCounts[i].count;
                break;
            }
        }

        // Check if word is negative
        char negativeWords[10][20] = {"bad", "poor", "terrible", "awful", "horrible", "hate", "dislike", "angry", "unhappy", "upset"};
        for (k = 0; k < 10; k++) {
            if (strcmp(wordCounts[i].word, negativeWords[k]) == 0) {
                sentimentValue -= wordCounts[i].count;
                break;
            }
        }
    }

    // Print sentiment value
    printf("Sentiment value: %d\n", sentimentValue);

    // Free memory
    for (i = 0; i < wordCount; i++) {
        free(wordCounts[i].word);
    }

    return 0;
}