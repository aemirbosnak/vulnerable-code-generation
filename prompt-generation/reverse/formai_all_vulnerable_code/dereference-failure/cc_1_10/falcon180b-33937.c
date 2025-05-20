//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_theory() {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
    theory->name = malloc(MAX_LENGTH * sizeof(char));
    theory->description = malloc(MAX_LENGTH * sizeof(char));

    srand(time(NULL));
    int name_length = rand() % MAX_LENGTH + 1;
    int description_length = rand() % MAX_LENGTH + 1;

    for (int i = 0; i < name_length; i++) {
        theory->name[i] = 'A' + rand() % 26;
    }
    theory->name[name_length] = '\0';

    for (int i = 0; i < description_length; i++) {
        theory->description[i] = 'A' + rand() % 26;
    }
    theory->description[description_length] = '\0';

    return theory;
}

void print_theory(ConspiracyTheory *theory) {
    printf("Name: %s\n", theory->name);
    printf("Description: %s\n", theory->description);
}

int main() {
    int num_theories;

    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        ConspiracyTheory *theory = generate_theory();
        print_theory(theory);
        free(theory->name);
        free(theory->description);
        free(theory);
    }

    return 0;
}