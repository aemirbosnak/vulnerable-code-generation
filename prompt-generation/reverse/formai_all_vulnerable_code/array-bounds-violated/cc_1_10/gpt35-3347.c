//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_DOC_LENGTH 1000 // Define the maximum document length

bool isSentenceEnd(char c)
{
    if (c == '.' || c == '?' || c == '!') {
        return true;
    }
    return false;
}

void summarizeDocument(char doc[])
{
    // Declare and initialize variables
    int numSentences = 0, numWords = 0, numChars = 0;
    char sentenceArr[MAX_DOC_LENGTH][MAX_DOC_LENGTH]; 
    char wordArr[MAX_DOC_LENGTH][MAX_DOC_LENGTH];
    char c;
    bool inWord = false, inSentence = false;

    // Iterate through document, counting number of sentences, words, and characters
    for (int i = 0; i < strlen(doc); i++) {
        c = doc[i];
        numChars++;

        if (inSentence && isSentenceEnd(c)) {
            sentenceArr[numSentences][i] = c;
            numSentences++;
            inSentence = false;
        } else if (isalpha(c)) {
            if (!inWord) {
                inWord = true;
                numWords++;
            }
            wordArr[numWords-1][strnlen(wordArr[numWords-1],MAX_DOC_LENGTH-1)] = tolower(c);
        } else if (isspace(c)) {
            inWord = false;
            sentenceArr[numSentences][i] = c;
            wordArr[numWords-1][strnlen(wordArr[numWords-1],MAX_DOC_LENGTH-1)] = c;
        } else {
            sentenceArr[numSentences][i] = c;
        }

        if (!inSentence && !isspace(c) && !isSentenceEnd(c)) {
            inSentence = true;
        }
    }

    // Print out summary information
    printf("Number of sentences: %d\n", numSentences);
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    printf("\n");

    // Print out summary of document by sentence
    for (int i = 0; i < numSentences; i++) {
        printf("Sentence %d: %s\n", i+1, sentenceArr[i]);
    }

    printf("\n");

    // Print out summary of document by word
    for (int i = 0; i < numWords; i++) {
        printf("Word %d: %s\n", i+1, wordArr[i]);
    }
}

int main() 
{
    // Sample document
    char doc[MAX_DOC_LENGTH] = "This is a sample document. It contains multiple sentences? And even some exclamation points! Let's see how our summarizer handles it.";

    // Summarize document
    summarizeDocument(doc);

    return 0;
}