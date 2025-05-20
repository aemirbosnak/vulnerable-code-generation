//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;

    return strcmp(wordA->word, wordB->word);
}

int isSpam(char *text) {
    int totalWords = 0;
    int spamWords = 0;
    Word words[MAX_WORDS];

    char *token = strtok(text, " ");
    while (token!= NULL) {
        totalWords++;

        Word *word = NULL;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i].word, token) == 0) {
                word = &words[i];
                break;
            }
        }

        if (word == NULL) {
            if (totalWords >= MAX_WORDS) {
                return 1; // Too many words
            }

            strncpy(word->word, token, MAX_WORD_LENGTH);
            word->count = 1;
            words[totalWords] = *word;
        } else {
            word->count++;
        }

        token = strtok(NULL, " ");
    }

    for (int i = 0; i < totalWords; i++) {
        if (words[i].count >= 5) {
            spamWords++;
        }
    }

    return spamWords >= 3;
}

int main() {
    char text[10000];

    printf("Enter text to check for spam: ");
    fgets(text, sizeof(text), stdin);

    if (isSpam(text)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}