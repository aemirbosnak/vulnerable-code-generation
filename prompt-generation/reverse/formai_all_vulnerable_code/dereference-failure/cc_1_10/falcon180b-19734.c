//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_theory(int complexity) {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
    theory->name = malloc(20 * sizeof(char));
    theory->description = malloc(100 * sizeof(char));

    srand(time(NULL));
    int theory_type = rand() % 5; // 0: government, 1: aliens, 2: technology, 3: secret society, 4: supernatural

    switch (theory_type) {
        case 0:
            strcpy(theory->name, "Operation");
            strcpy(theory->description, "The government is secretly controlling our thoughts through radio waves.");
            break;
        case 1:
            strcpy(theory->name, "The");
            strcpy(theory->description, "Aliens have been living among us for centuries, manipulating world events.");
            break;
        case 2:
            strcpy(theory->name, "Project");
            strcpy(theory->description, "Advanced technology from Area 51 is being used to control global politics.");
            break;
        case 3:
            strcpy(theory->name, "The Order of");
            strcpy(theory->description, "A secret society of powerful elites controls world governments behind the scenes.");
            break;
        case 4:
            strcpy(theory->name, "The");
            strcpy(theory->description, "Supernatural forces are manipulating human history for their own mysterious purposes.");
            break;
    }

    int complexity_level = rand() % 3; // 0: simple, 1: moderate, 2: complex

    switch (complexity_level) {
        case 0:
            strcat(theory->description, " They do this by broadcasting subliminal messages through television and radio broadcasts.");
            break;
        case 1:
            strcat(theory->description, " Their ultimate goal is to establish a new world order where they hold all the power.");
            break;
        case 2:
            strcat(theory->description, " These beings possess advanced psychic abilities and use them to influence our thoughts and actions.");
            break;
    }

    return theory;
}

void print_theory(ConspiracyTheory *theory) {
    printf("The %s Theory:\n%s\n", theory->name, theory->description);
}

int main() {
    int num_theories;
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        ConspiracyTheory *theory = generate_theory(2); // Generate complex theories
        print_theory(theory);
        free(theory->name);
        free(theory->description);
        free(theory);
    }

    return 0;
}