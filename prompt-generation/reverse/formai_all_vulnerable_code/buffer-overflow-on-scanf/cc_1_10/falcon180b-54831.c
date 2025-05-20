//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define NUM_CONSPIRACIES 10

typedef struct {
    char name[MAX_CONSPIRACY_LENGTH];
    char description[MAX_CONSPIRACY_LENGTH];
} Conspiracy;

Conspiracy conspiracies[NUM_CONSPIRACIES] = {
    {"Flat Earth", "The belief that the Earth is flat and not a globe."},
    {"Moon Landing Hoax", "The belief that the Apollo moon landings were faked."},
    {"9/11 Inside Job", "The belief that the September 11 attacks were orchestrated by the U.S. government."},
    {"Chemtrails", "The belief that the trails left by aircraft are chemical or biological agents deliberately sprayed into the atmosphere."},
    {"Illuminati", "The belief in a secret society controlling world events."},
    {"Area 51", "The belief that a secret government facility in Nevada is involved in extraterrestrial research."},
    {"Roswell Incident", "The belief that an alien spacecraft crashed in Roswell, New Mexico in 1947."},
    {"Bigfoot", "The belief in a large, hairy, humanoid creature that inhabits the forests of North America."},
    {"Loch Ness Monster", "The belief in a creature inhabiting Loch Ness in the Scottish Highlands."},
    {"Atlantis", "The belief in a lost city or civilization that sank into the sea."}
};

void generate_random_conspiracy(Conspiracy* conspiracy) {
    int index;
    srand(time(NULL));
    index = rand() % NUM_CONSPIRACIES;
    *conspiracy = conspiracies[index];
}

int main() {
    Conspiracy conspiracy;
    int i;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate a new conspiracy theory:\n");

    while (1) {
        generate_random_conspiracy(&conspiracy);
        printf("\nConspiracy Theory: %s\n", conspiracy.name);
        printf("Description: %s\n\n", conspiracy.description);

        printf("Press enter to generate a new conspiracy theory or type 'quit' to exit:\n");
        scanf("%s", conspiracy.name);

        if (strcmp(conspiracy.name, "quit") == 0) {
            break;
        }
    }

    return 0;
}