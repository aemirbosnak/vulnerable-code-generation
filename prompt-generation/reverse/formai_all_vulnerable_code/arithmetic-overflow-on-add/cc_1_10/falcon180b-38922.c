//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;

    return strcmp(word1->word, word2->word);
}

int main() {
    char input[100];
    char word[MAX_WORD_LENGTH + 1];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter text to analyze: ");
    fgets(input, 100, stdin);

    // Remove punctuation and convert to lowercase
    for (i = 0; input[i]; ++i) {
        if (!isalnum(input[i])) {
            continue;
        }

        word[numWords] = tolower(input[i]);
        ++numWords;

        if (numWords >= MAX_WORDS) {
            break;
        }
    }

    word[numWords] = '\0';

    // Count word frequencies
    for (i = 0; i < numWords; ++i) {
        int j;
        for (j = 0; j < numWords - i; ++j) {
            if (strcmp(words[j].word, word + i) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == numWords - i) {
            strncpy(words[numWords - i].word, word + i, MAX_WORD_LENGTH);
            words[numWords - i].count = 1;
            --numWords;
        }
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequencies
    for (i = 0; i < numWords; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}