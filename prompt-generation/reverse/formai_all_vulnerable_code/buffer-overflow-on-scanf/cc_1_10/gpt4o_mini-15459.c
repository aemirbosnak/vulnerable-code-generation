//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUBJECTS 10
#define NUM_ACTIONS 10
#define NUM_LOCATIONS 10
#define NUM_MOTIVATIONS 10

const char *subjects[NUM_SUBJECTS] = {
    "aliens",
    "government agents",
    "lizard people",
    "time travelers",
    "bigfoot",
    "robots",
    "illuminati",
    "secret societies",
    "extraterrestrial beings",
    "reptilian overlords"
};

const char *actions[NUM_ACTIONS] = {
    "control our minds",
    "manipulate weather patterns",
    "create fake news",
    "steal our resources",
    "spy on us through our devices",
    "alter history",
    "sabotage natural disasters",
    "infiltrate schools",
    "transmit secret messages",
    "shape public opinion"
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51",
    "the Bermuda Triangle",
    "the moon",
    "the Hollow Earth",
    "Trilateral Commission headquarters",
    "Montana's forests",
    "the Vatican",
    "Neuschwabenland",
    "the Internet's deep web",
    "behind a waterfall"
};

const char *motivations[NUM_MOTIVATIONS] = {
    "to establish a New World Order",
    "for financial gain",
    "to colonize Earth",
    "to hide the truth from humanity",
    "to manipulate history",
    "for control over the global population",
    "to eliminate dissenters",
    "for personal power",
    "to exploit natural resources",
    "to prevent the awakening of humankind"
};

void generate_theory() {
    int subject_index = rand() % NUM_SUBJECTS;
    int action_index = rand() % NUM_ACTIONS;
    int location_index = rand() % NUM_LOCATIONS;
    int motivation_index = rand() % NUM_MOTIVATIONS;

    printf("Conspiracy Theory:\n");
    printf("%s are known to %s at %s %s.\n", 
            subjects[subject_index], 
            actions[action_index], 
            locations[location_index], 
            motivations[motivation_index]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int num_theories;
    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        generate_theory();
        printf("\n");
    }

    return 0;
}