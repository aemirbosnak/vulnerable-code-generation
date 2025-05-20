//Falcon-180B DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS_PER_SENTENCE 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void processText(char* text) {
    int numWords = 0;
    char* word = strtok(text, " ");
    while (word!= NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }

    WordFrequency* wordFrequencies = malloc(numWords * sizeof(WordFrequency));
    memset(wordFrequencies, 0, numWords * sizeof(WordFrequency));

    char* sentence = strtok(text, ".");
    int numSentences = 0;
    while (sentence!= NULL) {
        char* word = strtok(sentence, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordFrequencies[i].word) == 0) {
                    wordFrequencies[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strncpy(wordFrequencies[numWords].word, word, MAX_WORD_LENGTH);
                wordFrequencies[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
        numSentences++;
        sentence = strtok(NULL, ".");
    }

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    char text[MAX_SENTENCES * MAX_WORDS_PER_SENTENCE];
    printf("Enter text: ");
    fgets(text, MAX_SENTENCES * MAX_WORDS_PER_SENTENCE, stdin);
    processText(text);

    return 0;
}