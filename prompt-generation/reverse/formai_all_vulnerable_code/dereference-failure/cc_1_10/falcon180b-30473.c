//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char *generate_conspiracy_theory(void);

int main(void) {
    srand(time(NULL));

    int num_theories = 5; // user input for number of theories

    for (int i = 0; i < num_theories; i++) {
        char *theory = generate_conspiracy_theory();
        printf("Conspiracy Theory #%d: %s\n", i + 1, theory);
    }

    return 0;
}

char *generate_conspiracy_theory(void) {
    char *theory = malloc(MAX_CONSPIRACY_LENGTH);
    memset(theory, 0, MAX_CONSPIRACY_LENGTH);

    int num_words = rand() % MAX_WORDS + 1;

    for (int i = 0; i < num_words; i++) {
        char *word = malloc(MAX_WORD_LENGTH);
        memset(word, 0, MAX_WORD_LENGTH);

        int word_length = rand() % MAX_WORD_LENGTH + 1;

        for (int j = 0; j < word_length; j++) {
            word[j] = rand() % 26 + 'a';
        }

        strcat(theory, word);

        if (i < num_words - 1) {
            strcat(theory, " ");
        }
    }

    return theory;
}