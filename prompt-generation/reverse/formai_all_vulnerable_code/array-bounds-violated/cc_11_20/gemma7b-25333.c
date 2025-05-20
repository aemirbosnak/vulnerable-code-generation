//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORDS][MAX_SENTENCE_LENGTH];
    int numWords = 0;
    int i, j, k;

    printf("Enter a sentence: ");
    scanf("%[^\n]%*c", sentence);

    // Tokenize the sentence into words
    i = 0;
    words[numWords][0] = sentence[i];
    numWords++;
    while (sentence[i] != '\0') {
        i++;
        if (sentence[i] != ' ' && sentence[i] != '\t') {
            words[numWords][0] = sentence[i];
            numWords++;
        } else {
            words[numWords][0] = '\0';
        }
    }

    // Remove punctuation from words
    for (i = 0; i < numWords; i++) {
        for (j = 0; words[i][j] != '\0'; j++) {
            if (ispunct(words[i][j])) {
                words[i][j] = '\0';
            }
        }
    }

    // Create a frequency table of words
    int wordFreq[numWords];
    for (i = 0; i < numWords; i++) {
        wordFreq[i] = 0;
    }
    for (i = 0; i < numWords; i++) {
        wordFreq[words[i][0]]++;
    }

    // Identify words that occur more than once
    for (i = 0; i < numWords; i++) {
        if (wordFreq[words[i][0]] > 1) {
            printf("%s occurs more than once.\n", words[i]);
        }
    }

    return 0;
}