//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 255
#define NUM_THEORIES 10
#define NUM_PEOPLE 5
#define NUM_EVENTS 5
#define NUM_LOCATIONS 5

const char *theories[NUM_THEORIES] = {
    "The moon landing was staged by the government to distract us from the true state of the economy.",
    "Aliens are actually among us, controlling world leaders through mind control.",
    "The COVID-19 pandemic was planned by pharmaceutical companies to profit from vaccines.",
    "Climate change is a hoax created by scientists funded by secret organizations.",
    "The Earth is flat and any evidence to the contrary is fabricated by the government.",
    "History is rewritten by the victors to manipulate public perception and control the populace.",
    "Secret societies run the world and influence every major government policy.",
    "The internet is a tool for the elite to surveil and control the masses.",
    "Global warming was invented to impose regulations that hurt the average person while benefiting the rich.",
    "Food is being genetically engineered to control the population's DNA."
};

const char *people[NUM_PEOPLE] = {
    "scientists",
    "politicians",
    "celebrities",
    "business tycoons",
    "secret agents"
};

const char *events[NUM_EVENTS] = {
    "a major political election",
    "the last World Cup",
    "the launch of a new tech product",
    "a global pandemic",
    "an environmental disaster"
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51",
    "the Bermuda Triangle",
    "the Vatican",
    "the White House",
    "Silicon Valley"
};

void generateConspiracyTheory() {
    // Randomly select elements to build the conspiracy theory
    int theoryIndex = rand() % NUM_THEORIES;
    int personIndex = rand() % NUM_PEOPLE;
    int eventIndex = rand() % NUM_EVENTS;
    int locationIndex = rand() % NUM_LOCATIONS;

    // Construct and print the conspiracy theory
    printf("Conspiracy Theory:\n");
    printf("%s involves %s during %s, linked to %s.\n", 
        theories[theoryIndex], people[personIndex], 
        events[eventIndex], locations[locationIndex]);
    printf("\n");
}

int main() {
    int numberOfTheories;

    // Seed the random number generator
    srand(time(NULL));

    // User input for how many conspiracy theories to generate
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &numberOfTheories);

    // Validate user input
    if (numberOfTheories <= 0 || numberOfTheories > 100) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Generate the requested number of conspiracy theories
    for (int i = 0; i < numberOfTheories; i++) {
        generateConspiracyTheory();
    }

    return 0;
}