//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10

struct Word {
    char *word;
    int score;
};

int main() {
    int numPlayers = 2;
    struct Word words[MAX_WORDS];

    // Initialize words
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].word = NULL;
        words[i].score = 0;
    }

    // Get words from players
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter a word: ");
        words[i].word = malloc(20);
        scanf("%s", words[i].word);
    }

    // Check words
    for (int i = 0; i < numPlayers; i++) {
        int isWordValid = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                isWordValid = 1;
            }
        }

        // Award points if the word is valid
        if (isWordValid) {
            words[i].score++;
        }
    }

    // Print results
    for (int i = 0; i < numPlayers; i++) {
        printf("Word: %s, Score: %d\n", words[i].word, words[i].score);
    }

    return 0;
}