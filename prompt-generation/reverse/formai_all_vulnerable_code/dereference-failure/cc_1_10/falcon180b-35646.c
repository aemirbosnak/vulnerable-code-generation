//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_THEORY_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char *name;
    char *description;
    int probability;
} Theory;

Theory theories[MAX_THEORIES];

void generate_theory(Theory *theory, int length) {
    int i;
    for (i = 0; i < length; i++) {
        theory->name[i] = 'a' + rand() % 26;
    }
    theory->name[length] = '\0';

    theory->description = malloc(length * sizeof(char));
    for (i = 0; i < length; i++) {
        theory->description[i] = 'a' + rand() % 26;
    }
    theory->description[length] = '\0';

    theory->probability = rand() % 101;
}

void generate_theories() {
    int i;
    for (i = 0; i < MAX_THEORIES; i++) {
        generate_theory(&theories[i], rand() % MAX_THEORY_LENGTH + 1);
    }
}

void generate_words(char *words[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        words[i] = malloc(MAX_THEORY_LENGTH * sizeof(char));
        generate_theory(words[i], rand() % MAX_THEORY_LENGTH + 1);
    }
}

int main() {
    srand(time(NULL));

    generate_theories();

    char *words[MAX_WORDS];
    int num_words = rand() % MAX_WORDS + 1;
    generate_words(words, num_words);

    printf("Conspiracy Theories:\n");
    for (int i = 0; i < MAX_THEORIES; i++) {
        printf("%s: %s (%.2f%%)\n", theories[i].name, theories[i].description, theories[i].probability);
    }

    printf("\nRandom Conspiracy Theory:\n");
    int theory_index = rand() % MAX_THEORIES;
    printf("%s: %s (%.2f%%)\n", theories[theory_index].name, theories[theory_index].description, theories[theory_index].probability);

    return 0;
}