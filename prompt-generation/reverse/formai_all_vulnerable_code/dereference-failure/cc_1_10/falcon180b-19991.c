//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_theory(int complexity) {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
    theory->name = malloc(50 * sizeof(char));
    theory->description = malloc(200 * sizeof(char));

    switch (complexity) {
        case 1:
            sprintf(theory->name, "Flat Earth");
            sprintf(theory->description, "The Earth is actually flat, and the government is hiding the truth from us.");
            break;
        case 2:
            sprintf(theory->name, "Moon Landing Hoax");
            sprintf(theory->description, "The moon landing was faked by the government to win the space race against the Soviets.");
            break;
        case 3:
            sprintf(theory->name, "9/11 Conspiracy");
            sprintf(theory->description, "The 9/11 attacks were orchestrated by the government as an excuse to invade the Middle East.");
            break;
        case 4:
            sprintf(theory->name, "Illuminati");
            sprintf(theory->description, "A secret society of powerful individuals who control the world's governments and financial systems.");
            break;
        case 5:
            sprintf(theory->name, "Chemtrails");
            sprintf(theory->description, "The trails left by airplanes in the sky are actually chemicals being sprayed by the government for unknown purposes.");
            break;
        default:
            sprintf(theory->name, "Unknown Conspiracy");
            sprintf(theory->description, "A mysterious theory that has not yet been revealed to the public.");
            break;
    }

    return theory;
}

int main() {
    srand(time(NULL));
    int complexity = rand() % 6;
    ConspiracyTheory *theory = generate_theory(complexity);

    printf("Conspiracy Theory: %s\n", theory->name);
    printf("Description: %s\n", theory->description);

    free(theory->name);
    free(theory->description);
    free(theory);

    return 0;
}