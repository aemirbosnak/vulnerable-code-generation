//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 50
#define MAX_WORDS_PER_CONSPIRACY 10

typedef struct {
    char *words[MAX_WORDS_PER_CONSPIRACY];
    int num_words;
} ConspiracyTheory;

ConspiracyTheory generate_conspiracy_theory(int num_words) {
    ConspiracyTheory theory;
    theory.num_words = num_words;

    for (int i = 0; i < num_words; i++) {
        theory.words[i] = malloc(sizeof(char) * 20); // Allocate memory for each word
        sprintf(theory.words[i], "%s%d", "theory", rand() % 100); // Generate a random word
    }

    return theory;
}

void print_conspiracy_theory(ConspiracyTheory theory) {
    for (int i = 0; i < theory.num_words; i++) {
        printf("%s ", theory.words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int num_theories;
    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &num_theories);

    ConspiracyTheory theories[num_theories];

    for (int i = 0; i < num_theories; i++) {
        int num_words = rand() % MAX_WORDS_PER_CONSPIRACY + 1; // Generate a random number of words
        theories[i] = generate_conspiracy_theory(num_words);
    }

    for (int i = 0; i < num_theories; i++) {
        print_conspiracy_theory(theories[i]);
    }

    return 0;
}