//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_conspiracy_theory(int length) {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
    theory->name = malloc(length + 1);
    theory->description = malloc(length * 10 + 1);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        theory->name[i] = rand() % 26 + 'a';
    }

    theory->name[length] = '\0';

    sprintf(theory->description, "The %s conspiracy theory states that ", theory->name);

    for (int i = 0; i < length * 10; i++) {
        theory->description[i] = rand() % 26 + 'a';
    }

    theory->description[length * 10] = '\0';

    return theory;
}

void print_conspiracy_theory(ConspiracyTheory *theory) {
    printf("Conspiracy Theory: %s\n", theory->name);
    printf("Description: %s\n", theory->description);
}

int main() {
    int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    ConspiracyTheory *theory = generate_conspiracy_theory(length);
    print_conspiracy_theory(theory);

    free(theory->name);
    free(theory->description);
    free(theory);

    return 0;
}