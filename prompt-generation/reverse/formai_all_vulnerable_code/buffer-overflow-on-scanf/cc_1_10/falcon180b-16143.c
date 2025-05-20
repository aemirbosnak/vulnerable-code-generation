//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// Function to remove punctuation from a string
void removePunctuation(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isspace(str[i]) &&!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Function to split a string into words
void splitString(char *str, char *words[]) {
    int i = 0, j = 0;
    char *word = strtok(str, " ");
    while (word!= NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
}

// Function to generate a summary of a text
void generateSummary(char *text, int numSentences) {
    char *words[MAX_WORDS];
    int numWords = 0;

    // Remove punctuation and split the text into words
    removePunctuation(text);
    splitString(text, words);

    // Count the frequency of each word
    int freq[MAX_WORD_LENGTH];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < numWords; i++) {
        freq[strlen(words[i])]++;
    }

    // Generate the summary
    int maxFreq = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int numSummaryWords = (numSentences * maxFreq) / numWords;
    int summaryWords[numSummaryWords];
    int summaryIndex = 0;

    for (int i = 0; i < numWords; i++) {
        int wordLength = strlen(words[i]);
        if (freq[wordLength] >= maxFreq) {
            summaryWords[summaryIndex++] = words[i];
        }
    }

    // Print the summary
    for (int i = 0; i < summaryIndex; i++) {
        printf("%s ", summaryWords[i]);
    }
    printf("\n");
}

int main() {
    char text[1000000];
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    int numSentences;
    printf("Enter the number of sentences in the summary: ");
    scanf("%d", &numSentences);

    generateSummary(text, numSentences);

    return 0;
}