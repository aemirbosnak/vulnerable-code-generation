//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWordChar(char c) {
    return isalpha(c) || c == '\''; // Include apostrophe for words like 'it's
}

int main() {
    WordFrequency wordFreq[MAX_WORDS];
    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH];
    
    printf("Welcome to the C Word Frequency Counter!\n");
    printf("Please enter your text below (end with EOF):\n");

    // Read input until EOF
    while (scanf("%s", buffer) != EOF) {
        // Convert to lowercase for uniformity
        toLowerCase(buffer);
        
        // Skip non-word characters
        if (!isWordChar(buffer[0])) {
            continue;
        }

        // Check if the word is already counted
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFreq[i].word, buffer) == 0) {
                wordFreq[i].count++;
                found = 1;
                break;
            }
        }
        
        // If the word is new, add it to the array
        if (!found) {
            if (wordCount < MAX_WORDS) {
                strcpy(wordFreq[wordCount].word, buffer);
                wordFreq[wordCount].count = 1;
                wordCount++;
            } else {
                printf("Maximum word limit reached, unable to count more words.\n");
                break;
            }
        }
    }

    // Sort the word frequency array in descending order of counts
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (wordFreq[j].count < wordFreq[j + 1].count) {
                WordFrequency temp = wordFreq[j];
                wordFreq[j] = wordFreq[j + 1];
                wordFreq[j + 1] = temp;
            }
        }
    }

    // Display the results
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].count);
    }

    return 0;
}