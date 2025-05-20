//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256
#define NUM_THEORIES 10
#define MAX_CLAUSES 5

const char *subjects[] = {
    "aliens", "reptilian overlords", "Bigfoot", "the moon landing",
    "the government", "the Illuminati", "chemtrails", "5G technology",
    "the flat Earth society", "mind control"
};

const char *actions[] = {
    "are stealing our thoughts", "are hiding the truth from us",
    "control the weather", "are responsible for the pandemic",
    "are manipulating our DNA", "have infiltrated our schools",
    "control the world's economies", "are monitoring our every move"
};

const char *objects[] = {
    "to create a new world order", "to turn us into zombies",
    "so they can harvest our energy", "to keep us distracted",
    "to control the population", "to prevent us from ascending",
    "in order to ruin our environment", "to erase our history"
};

// Function to get random number within a range
int getRandomNumber(int min, int max) {
    return rand() % (max - min) + min;
}

// Function to generate a random conspiracy theory
void generateConspiracyTheory() {
    int subjectIdx = getRandomNumber(0, sizeof(subjects) / sizeof(subjects[0]));
    int actionIdx = getRandomNumber(0, sizeof(actions) / sizeof(actions[0]));
    int objectIdx = getRandomNumber(0, sizeof(objects) / sizeof(objects[0]));

    printf("Conspiracy Theory: %s %s %s.\n", 
        subjects[subjectIdx], actions[actionIdx], objects[objectIdx]);
}

// Function to generate a series of conspiracy theories
void generateTheories(int count) {
    printf("\n--- Random Conspiracy Theories ---\n");
    for (int i = 0; i < count; i++) {
        generateConspiracyTheory();
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // User input for number of theories
    int count;
    printf("How many conspiracy theories would you like to generate? ");
    
    // Validation for count input
    while (scanf("%d", &count) != 1 || count <= 0 || count > NUM_THEORIES) {
        printf("Please enter a number between 1 and %d: ", NUM_THEORIES);
        while(getchar() != '\n'); // Clear invalid input
    }

    // Generate random conspiracy theories
    generateTheories(count);

    return 0;
}