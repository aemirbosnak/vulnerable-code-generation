//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES 50

typedef struct {
    char *name;
    int length;
} ConspiracyTheory;

ConspiracyTheory generate_theory() {
    ConspiracyTheory theory = {0};
    theory.name = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    if (theory.name == NULL) {
        printf("Error: Failed to allocate memory for conspiracy theory name.\n");
        exit(1);
    }

    srand(time(NULL));
    int theory_length = rand() % MAX_CONSPIRACY_LENGTH + 1;

    for (int i = 0; i < theory_length; i++) {
        theory.name[i] = 'a' + rand() % 26;
    }
    theory.name[theory_length] = '\0';
    theory.length = theory_length;

    return theory;
}

int main() {
    int num_theories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_theories);

    ConspiracyTheory *theories = malloc(num_theories * sizeof(ConspiracyTheory));
    if (theories == NULL) {
        printf("Error: Failed to allocate memory for conspiracy theories.\n");
        exit(1);
    }

    for (int i = 0; i < num_theories; i++) {
        theories[i] = generate_theory();
        printf("Conspiracy theory %d: %s\n", i + 1, theories[i].name);
    }

    free(theories);
    return 0;
}