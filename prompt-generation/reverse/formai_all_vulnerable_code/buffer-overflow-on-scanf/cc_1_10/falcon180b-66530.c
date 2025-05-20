//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void countWords(char* text, WordFrequency* wordFrequencies, int numWords) {
    int i = 0;
    while (i < strlen(text)) {
        char c = tolower(text[i]);
        if (isalpha(c)) {
            char word[MAX_WORD_LENGTH];
            int j = 0;
            while (i < strlen(text) && isalpha(text[i])) {
                word[j++] = tolower(text[i++]);
            }
            word[j] = '\0';
            for (int k = 0; k < numWords; k++) {
                if (strcmp(wordFrequencies[k].word, word) == 0) {
                    wordFrequencies[k].frequency++;
                    break;
                }
            }
        } else {
            i++;
        }
    }
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    int numWords = 0;
    char input[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    while (numWords < MAX_NUM_WORDS) {
        printf("Enter a word: ");
        scanf("%s", input[numWords]);
        numWords++;
    }
    countWords(" ", wordFrequencies, numWords);
    printWordFrequencies(wordFrequencies, numWords);
    return 0;
}