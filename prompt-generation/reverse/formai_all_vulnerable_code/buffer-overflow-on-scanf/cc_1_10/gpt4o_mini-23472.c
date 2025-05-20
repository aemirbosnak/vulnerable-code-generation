//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUBJECTS 10
#define NUM_ACTIONS 10
#define NUM_LOCATIONS 10
#define NUM_CONCLUSIONS 10

const char *subjects[NUM_SUBJECTS] = {
    "aliens", "the government", "the lizard people", 
    "Bigfoot", "scientists", "AI overlords", 
    "the moon landing hoax", "the Illuminati", 
    "vaccine manufacturers", "time travelers"
};

const char *actions[NUM_ACTIONS] = {
    "control", "manipulate", "monitor", 
    "experiment on", "suppress", "observe", 
    "communicate with", "create simulations of", 
    "hide evidence from", "brainwash"
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51", "Antarctica", "the Bermuda Triangle", 
    "deep within the ocean", "the hollow Earth", 
    "on Mars", "the dark side of the moon", 
    "in your own neighborhood", "inside a computer", 
    "forests of the Pacific Northwest"
};

const char *conclusions[NUM_CONCLUSIONS] = {
    "to control humanity.", "for ultimate power.", 
    "to alter the timeline.", "to enslave the human race.", 
    "in preparation for an alien invasion.", 
    "to harvest dreams.", "to create a new world order.", 
    "for unknown purposes.", "as part of a grand experiment.", 
    "to keep us distracted from the real truth."
};

void generateConspiracyTheory() {
    int subjectIndex = rand() % NUM_SUBJECTS;
    int actionIndex = rand() % NUM_ACTIONS;
    int locationIndex = rand() % NUM_LOCATIONS;
    int conclusionIndex = rand() % NUM_CONCLUSIONS;

    printf("Conspiracy Theory:\n");
    printf("The %s %s the population of %s %s\n",
           subjects[subjectIndex],
           actions[actionIndex],
           locations[locationIndex],
           conclusions[conclusionIndex]);
    printf("\n");
}

int main() {
    char userResponse = 'y';
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Enter 'y' to generate a conspiracy theory, or 'n' to exit.\n");

    while (userResponse == 'y') {
        generateConspiracyTheory();
        printf("Would you like to generate another theory? (y/n): ");
        scanf(" %c", &userResponse);
    }

    printf("Thanks for using the Conspiracy Theory Generator! Stay curious!\n");
    
    return 0;
}