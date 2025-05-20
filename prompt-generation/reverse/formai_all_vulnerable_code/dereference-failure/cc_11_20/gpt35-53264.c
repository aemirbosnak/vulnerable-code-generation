//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100

void summarizeText(char *inputString, char *outputString, int summarySize) {
    // Split the input string into sentences using periods and newlines as delimiters
    char *sentence = strtok(inputString, ".\n");
    // Create an array to hold all the sentences
    char *sentences[MAX_OUTPUT_SIZE];
    int numSentences = 0;
    while (sentence != NULL && numSentences < MAX_OUTPUT_SIZE) {
        // Add the current sentence to the array of sentences
        sentences[numSentences++] = sentence;
        // Get the next sentence
        sentence = strtok(NULL, ".\n");
    }
    // Compute a score for each sentence based on the number of non-stop words it contains
    int scores[numSentences];
    for (int i = 0; i < numSentences; i++) {
        // Count the number of non-stop words in the current sentence
        char *word = strtok(sentences[i], " ");
        int count = 0;
        while (word != NULL) {
            // Check if the current word is a stop word
            if (strcmp(word, "a") != 0 && strcmp(word, "an") != 0 && strcmp(word, "the") != 0
                && strcmp(word, "and") != 0 && strcmp(word, "but") != 0 && strcmp(word, "or") != 0
                && strcmp(word, "as") != 0 && strcmp(word, "of") != 0 && strcmp(word, "to") != 0
                && strcmp(word, "in") != 0 && strcmp(word, "for") != 0 && strcmp(word, "on") != 0
                && strcmp(word, "with") != 0 && strcmp(word, "at") != 0 && strcmp(word, "by") != 0) {
                count++;
            }
            // Get the next word in the sentence
            word = strtok(NULL, " ");
        }
        // Compute the score for the current sentence as the number of non-stop words divided by the length of the sentence
        scores[i] = count / (strlen(sentences[i]) + 1);
    }
    // Select the top summarySize sentences based on their scores
    for (int i = 0; i < summarySize; i++) {
        // Find the sentence with the highest score
        int maxIndex = 0;
        int maxScore = -1;
        for (int j = 0; j < numSentences; j++) {
            if (scores[j] > maxScore) {
                maxIndex = j;
                maxScore = scores[j];
            }
        }
        // Add the selected sentence to the output string
        strcat(outputString, sentences[maxIndex]);
        strcat(outputString, ". ");
        // Remove the selected sentence from the array of sentences and scores
        for (int j = maxIndex; j < numSentences - 1; j++) {
            sentences[j] = sentences[j+1];
            scores[j] = scores[j+1];
        }
        numSentences--;
    }
}

int main() {
    char inputString[MAX_INPUT_SIZE];
    char outputString[MAX_OUTPUT_SIZE] = "";
    int summarySize;
    printf("Enter the input text:\n");
    fgets(inputString, MAX_INPUT_SIZE, stdin);
    printf("Enter the summary size:\n");
    scanf("%d", &summarySize);
    summarizeText(inputString, outputString, summarySize);
    printf("Summary:\n%s", outputString);
    return 0;
}