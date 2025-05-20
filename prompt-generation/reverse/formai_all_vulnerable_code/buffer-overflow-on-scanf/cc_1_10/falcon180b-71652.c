//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONSPIRACIES 100
#define MAX_CONSPIRACY_LENGTH 50
#define MAX_CONSPIRACY_WORDS 10

typedef struct {
    char words[MAX_CONSPIRACY_WORDS][MAX_CONSPIRACY_LENGTH];
    int num_words;
} ConspiracyTheory;

void generate_conspiracy_theory(ConspiracyTheory* theory) {
    srand(time(NULL));

    int i;
    for (i = 0; i < MAX_CONSPIRACY_WORDS; i++) {
        int word_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
        theory->words[i][0] = toupper(rand() % 26 + 'A');
        for (int j = 1; j < word_length; j++) {
            theory->words[i][j] = rand() % 26 + 'A';
        }
        theory->words[i][word_length] = '\0';
    }

    theory->num_words = rand() % MAX_CONSPIRACY_WORDS + 1;
}

void print_conspiracy_theory(ConspiracyTheory* theory) {
    printf("The %s is controlling the world through ", theory->words[0]);

    int i;
    for (i = 1; i < theory->num_words; i++) {
        printf("%s ", theory->words[i]);
    }

    printf(".\n");
}

int main() {
    ConspiracyTheory theory;

    int num_theories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_theories);

    srand(time(NULL));

    int i;
    for (i = 0; i < num_theories; i++) {
        generate_conspiracy_theory(&theory);
        print_conspiracy_theory(&theory);
    }

    return 0;
}