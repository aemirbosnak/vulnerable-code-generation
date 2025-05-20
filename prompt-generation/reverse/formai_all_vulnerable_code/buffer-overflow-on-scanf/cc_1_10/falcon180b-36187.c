//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} ConspiracyWord;

ConspiracyWord conspiracyWords[MAX_CONSPIRACY_WORDS];

void generateRandomConspiracyTheory(int theoryLength) {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACY_WORDS; i++) {
        conspiracyWords[i].word[0] = '\0';
        conspiracyWords[i].length = 0;
    }

    int numWords = rand() % (MAX_CONSPIRACY_WORDS - 1) + 1;

    for (int i = 0; i < numWords; i++) {
        int wordLength = rand() % MAX_WORD_LENGTH + 1;
        char word[MAX_WORD_LENGTH];

        for (int j = 0; j < wordLength; j++) {
            word[j] = rand() % 26 + 'a';
        }

        word[wordLength] = '\0';
        strcpy(conspiracyWords[i].word, word);
        conspiracyWords[i].length = wordLength;
    }

    char theory[MAX_CONSPIRACY_LENGTH];
    int theoryLengthRemaining = theoryLength;

    for (int i = 0; i < numWords; i++) {
        int wordLength = conspiracyWords[i].length;

        if (theoryLengthRemaining < wordLength) {
            wordLength = theoryLengthRemaining;
        }

        strncat(theory, conspiracyWords[i].word, wordLength);
        theoryLengthRemaining -= wordLength;

        if (i < numWords - 1) {
            strcat(theory, " ");
            theoryLengthRemaining--;
        }
    }

    theory[theoryLength] = '\0';
    printf("Random Conspiracy Theory: %s\n", theory);
}

int main() {
    int theoryLength;

    printf("Enter the length of the conspiracy theory: ");
    scanf("%d", &theoryLength);

    generateRandomConspiracyTheory(theoryLength);

    return 0;
}