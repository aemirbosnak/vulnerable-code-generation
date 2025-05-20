//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *description;
    char *motivation;
} ConspiracyTheory;

ConspiracyTheory *generate_theory() {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
    theory->name = "The ";
    theory->description = "Involves ";
    theory->motivation = "To ";

    char *adjectives[] = {"Illuminati", "Lizard People", "New World Order", "Aliens", "Government", "Big Pharma", "Elites", "Deep State"};
    char *nouns[] = {"control", "manipulate", "enslave", "dominate", "oppress", "brainwash", "exploit", "enslave"};
    char *verbs[] = {"the masses", "the population", "the people", "the world", "society", "humanity", "the planet", "the universe"};

    srand(time(NULL));
    int adjective_index = rand() % sizeof(adjectives);
    int noun_index = rand() % sizeof(nouns);
    int verb_index = rand() % sizeof(verbs);

    strcat(theory->name, adjectives[adjective_index]);
    strcat(theory->description, "a secretive group known as the ");
    strcat(theory->description, adjectives[adjective_index]);
    strcat(theory->description, " who seek to ");
    strcat(theory->description, verbs[verb_index]);
    strcat(theory->description, " through their control over ");
    strcat(theory->description, nouns[noun_index]);
    strcat(theory->motivation, "to maintain their power and influence over the world.");

    return theory;
}

void print_theory(ConspiracyTheory *theory) {
    printf("The %s Theory:\n", theory->name);
    printf("Description: %s\n", theory->description);
    printf("Motivation: %s\n", theory->motivation);
}

int main() {
    srand(time(NULL));
    int num_theories = rand() % 10 + 1;

    for (int i = 0; i < num_theories; i++) {
        ConspiracyTheory *theory = generate_theory();
        print_theory(theory);
        free(theory);
    }

    return 0;
}