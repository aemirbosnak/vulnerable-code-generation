//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a constant for the maximum length of the text to summarize */
#define MAX_TEXT_LENGTH 1000

/* Define a constant for the maximum length of the summary to generate */
#define MAX_SUMMARY_LENGTH 500

/* Define a constant for the maximum number of sentences to include in the summary */
#define MAX_SENTENCES 5

/* Define a function to split the input text into individual sentences */
void splitSentences(char* text, char** sentences, int* numSentences) {
    char* token = strtok(text, ".?!"); // Split the text at each sentence-ending punctuation mark
    *numSentences = 0;
    while (token != NULL && *numSentences < MAX_SENTENCES) {
        sentences[*numSentences] = token;
        (*numSentences)++;
        token = strtok(NULL, ".?!");
    }
}

/* Define a function to count the number of words in a sentence */
int countWords(char* sentence) {
    int numWords = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        numWords++;
        token = strtok(NULL, " ");
    }
    return numWords;
}

/* Define a function to generate the summary */
void generateSummary(char* text, char* summary) {
    // Allocate memory for arrays of sentences and sentence lengths
    char** sentences = (char**)malloc(MAX_SENTENCES * sizeof(char*));
    int* sentenceLengths = (int*)malloc(MAX_SENTENCES * sizeof(int));
    int numSentences;

    // Split the input text into sentences
    splitSentences(text, sentences, &numSentences);

    // Calculate the lengths of each sentence and store them in an array
    for (int i = 0; i < numSentences; i++) {
        sentenceLengths[i] = strlen(sentences[i]);
    }

    // Sort the sentences by length (in descending order)
    for (int i = 0; i < numSentences - 1; i++) {
        for (int j = i + 1; j < numSentences; j++) {
            if (sentenceLengths[i] < sentenceLengths[j]) {
                // Swap the sentences
                char* tempSentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = tempSentence;

                // Swap the corresponding sentence lengths
                int tempLength = sentenceLengths[i];
                sentenceLengths[i] = sentenceLengths[j];
                sentenceLengths[j] = tempLength;
            }
        }
    }

    // Combine the longest sentences into the summary
    int summaryLength = 0;
    int sentenceIndex = 0;
    while (summaryLength < MAX_SUMMARY_LENGTH && sentenceIndex < numSentences) {
        int numWords = countWords(sentences[sentenceIndex]);
        if (summaryLength + sentenceLengths[sentenceIndex] <= MAX_SUMMARY_LENGTH) {
            // The entire sentence can be included in the summary
            strcat(summary, sentences[sentenceIndex]);
            strcat(summary, ". ");
            summaryLength += sentenceLengths[sentenceIndex];
        } else if (numWords > 1) {
            // The sentence is too long, but can be truncated to fit in the summary
            int wordsToAdd = 0;
            char tempSentence[MAX_TEXT_LENGTH];
            strcpy(tempSentence, sentences[sentenceIndex]);
            char* token = strtok(tempSentence, " ");
            while (token != NULL && wordsToAdd < numWords / 2) {
                wordsToAdd++;
                token = strtok(NULL, " ");
            }
            strncpy(summary + strlen(summary), sentences[sentenceIndex], token - sentences[sentenceIndex]);
            strcat(summary, "... ");
            summaryLength += token - sentences[sentenceIndex];
        }
        sentenceIndex++;
    }

    // Free memory allocated for arrays
    free(sentences);
    free(sentenceLengths);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = "";

    printf("Enter the text to summarize (up to %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin);

    // Remove newline character from end of input string
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }

    generateSummary(text, summary);

    printf("Summary:\n%s\n", summary);

    return 0;
}