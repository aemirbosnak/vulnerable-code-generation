//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50
#define ALIEN_ALPHABET "XqwÉ£$%&/@#_=+!*^"

typedef struct AlienWord {
    char word[MAX_LENGTH];
    int translation[MAX_LENGTH];
} AlienWord;

void translateWord(AlienWord *alienWord) {
    int i, j;
    char currentLetter, alienLetter;

    for (i = 0; i < strlen(alienWord->word) && i < MAX_LENGTH; i++) {
        currentLetter = alienWord->word[i];
        alienLetter = strchr(ALIEN_ALPHABET, currentLetter)[0];

        alienWord->translation[i] = alienLetter;
    }

    alienWord->translation[i] = '\0';
}

void printTranslation(AlienWord *alienWord) {
    printf("%s -> ", alienWord->word);
    for (int i = 0; i < strlen(alienWord->word); i++) {
        printf("%c%c", alienWord->translation[i], i < strlen(alienWord->translation) - 1 ? ' ' : '\n');
    }
}

int main() {
    AlienWord alienWords[MAX_WORDS];
    char alienInput[MAX_LENGTH];
    int numWords = 0;

    while (fgets(alienInput, sizeof(alienInput), stdin) && numWords < MAX_WORDS) {
        sscanf(alienInput, "%s", alienWords[numWords].word);
        translateWord(&alienWords[numWords]);
        numWords++;
    }

    for (int i = 0; i < numWords; i++) {
        printTranslation(&alienWords[i]);
    }

    return 0;
}