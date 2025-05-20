//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CHARACTERS 5
#define NUM_EVENTS 5
#define NUM_LOCATIONS 5
#define NUM_MOTIVES 5

const char *characters[NUM_CHARACTERS] = {
    "aliens",
    "the government",
    "lizard people",
    "time travelers",
    "secret societies"
};

const char *events[NUM_EVENTS] = {
    "the moon landing",
    "the assassination of JFK",
    "the disappearance of Amelia Earhart",
    "the rise of the internet",
    "the COVID-19 pandemic"
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51",
    "the Bermuda Triangle",
    "the Vatican",
    "a hidden base in Antarctica",
    "the pyramids of Giza"
};

const char *motives[NUM_MOTIVES] = {
    "to control humanity",
    "for immortality",
    "to harvest our organs",
    "to gain intergalactic power",
    "to prevent the discovery of ancient technologies"
};

void generateTheory() {
    // Randomly select one element from each category
    const char *character = characters[rand() % NUM_CHARACTERS];
    const char *event = events[rand() % NUM_EVENTS];
    const char *location = locations[rand() % NUM_LOCATIONS];
    const char *motive = motives[rand() % NUM_MOTIVES];

    // Print the conspiracy theory
    printf("Conspiracy Theory:\n");
    printf("It's believed that %s were responsible for %s to gain control of the secrets hidden in %s %s.\n\n", 
            character, event, location, motive);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Number of theories to generate
    int numOfTheories;
    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &numOfTheories);

    // Check for valid input
    if (numOfTheories <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Generate the specified number of theories
    for (int i = 0; i < numOfTheories; i++) {
        generateTheory();
    }

    return 0;
}