//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define WORDS_IN_THEORY 10

typedef struct {
    char *words[WORDS_IN_THEORY];
} Theory;

Theory theories[MAX_THEORIES];

char *conspiracy_words[] = {
    "lizard",
    "alien",
    "Illuminati",
    "Masonic",
    "reptilian",
    "globalist",
    "satanic",
    "deep state",
    "new world order",
    "chemtrails",
    "fluoride",
    "vaccines",
    "5G",
    "AI",
    "robot",
    "simulation",
    "matrix",
    "mind control"
};

void generate_theory(Theory *theory) {
    for (int i = 0; i < WORDS_IN_THEORY; ++i) {
        theory->words[i] = malloc(strlen(conspiracy_words[rand() % sizeof(conspiracy_words)]) + 1);
        strcpy(theory->words[i], conspiracy_words[rand() % sizeof(conspiracy_words)]);
    }
}

void print_theory(Theory theory) {
    for (int i = 0; i < WORDS_IN_THEORY; ++i) {
        printf("%s ", theory.words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_THEORIES; ++i) {
        generate_theory(&theories[i]);
    }

    for (int i = 0; i < MAX_THEORIES; ++i) {
        printf("Conspiracy Theory #%d:\n", i + 1);
        print_theory(theories[i]);
        for (int j = 0; j < WORDS_IN_THEORY; ++j) {
            free(theories[i].words[j]);
        }
    }

    return 0;
}