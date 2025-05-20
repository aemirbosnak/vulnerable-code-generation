//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_COMPONENTS 10

typedef struct {
    char *name;
    char *description;
} ConspiracyComponent;

ConspiracyComponent components[MAX_CONSPIRACY_COMPONENTS] = {
    {"Illuminati", "A secret society that controls world events"},
    {"Area 51", "A top-secret government facility where aliens are studied"},
    {"Flat Earth", "The belief that the Earth is flat, not round"},
    {"Lizard People", "The idea that shape-shifting reptilian aliens control the world"},
    {"Chemtrails", "The theory that contrails from planes are actually chemicals being sprayed on the population"},
    {"9/11", "The belief that the 9/11 attacks were a government conspiracy"},
    {"Moon Landing", "The idea that the moon landing was faked"},
    {"Big Pharma", "The belief that pharmaceutical companies are suppressing natural cures for profit"},
    {"New World Order", "The idea that a secretive group is working to establish a global government"},
    {"HAARP", "The theory that a government research facility is controlling the weather and causing natural disasters"}
};

void generate_conspiracy(char *conspiracy, int length) {
    char component[MAX_CONSPIRACY_LENGTH];
    int num_components = rand() % MAX_CONSPIRACY_COMPONENTS + 1;

    strcpy(conspiracy, "The ");
    for (int i = 0; i < num_components; i++) {
        int component_index = rand() % MAX_CONSPIRACY_COMPONENTS;
        strcat(conspiracy, components[component_index].name);
        if (i < num_components - 1) {
            strcat(conspiracy, ", ");
        }
    }

    strcat(conspiracy, " is a ");
    int adjective_index = rand() % 3;
    switch (adjective_index) {
        case 0:
            strcat(conspiracy, "sinister");
            break;
        case 1:
            strcat(conspiracy, "nefarious");
            break;
        case 2:
            strcat(conspiracy, "malevolent");
            break;
    }
    strcat(conspiracy, " plot by ");

    for (int i = 0; i < num_components; i++) {
        int component_index = rand() % MAX_CONSPIRACY_COMPONENTS;
        strcat(conspiracy, components[component_index].description);
        if (i < num_components - 1) {
            strcat(conspiracy, ", ");
        }
    }

    strcat(conspiracy, " to ");
    int verb_index = rand() % 4;
    switch (verb_index) {
        case 0:
            strcat(conspiracy, "control");
            break;
        case 1:
            strcat(conspiracy, "manipulate");
            break;
        case 2:
            strcat(conspiracy, "dominate");
            break;
        case 3:
            strcat(conspiracy, "enslave");
            break;
    }
    strcat(conspiracy, " the world. ");

    printf("%s\n", conspiracy);
}

int main() {
    srand(time(NULL));

    int num_conspiracies = rand() % 10 + 1;

    for (int i = 0; i < num_conspiracies; i++) {
        int conspiracy_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
        char conspiracy[conspiracy_length];
        generate_conspiracy(conspiracy, conspiracy_length);
    }

    return 0;
}