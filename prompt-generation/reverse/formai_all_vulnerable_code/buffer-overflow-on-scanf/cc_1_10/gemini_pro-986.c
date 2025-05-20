//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Structure to represent a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to compare two words based on their frequency
int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return wordB->frequency - wordA->frequency;
}

// Function to summarize the text
void summarizeText(char *text, int numWords) {
    // Tokenize the text into words
    char *words[MAX_WORDS];
    int numTokens = 0;
    char *token = strtok(text, " ,.-");
    while (token != NULL) {
        words[numTokens++] = token;
        token = strtok(NULL, " ,.-");
    }

    // Count the frequency of each word
    Word wordFreq[MAX_WORDS];
    int numUniqueWords = 0;
    for (int i = 0; i < numTokens; i++) {
        int found = 0;
        for (int j = 0; j < numUniqueWords; j++) {
            if (strcmp(words[i], wordFreq[j].word) == 0) {
                wordFreq[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordFreq[numUniqueWords].word, words[i]);
            wordFreq[numUniqueWords].frequency = 1;
            numUniqueWords++;
        }
    }

    // Sort the words based on their frequency
    qsort(wordFreq, numUniqueWords, sizeof(Word), compareWords);

    // Print the top 'numWords' words
    printf("Summary:\n");
    for (int i = 0; i < numWords && i < numUniqueWords; i++) {
        printf("%s (%d)\n", wordFreq[i].word, wordFreq[i].frequency);
    }
}

// Main function
int main() {
    // Get the text from the user
    char text[10000];
    printf("Enter the text to summarize:\n");
    fgets(text, 10000, stdin);

    // Get the number of words in the summary
    int numWords;
    printf("Enter the number of words in the summary:\n");
    scanf("%d", &numWords);

    // Summarize the text
    summarizeText(text, numWords);

    return 0;
}