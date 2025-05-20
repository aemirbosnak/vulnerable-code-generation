//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUBJECTS 10
#define NUM_VERBS 10
#define NUM_OBJECTS 10

const char *subjects[NUM_SUBJECTS] = {
    "The government",
    "Aliens",
    "The moon",
    "Bigfoot",
    "The Illuminati",
    "Time travelers",
    "A secret society of cats",
    "Reptilian overlords",
    "Artificial intelligence",
    "Flat Earth enthusiasts"
};

const char *verbs[NUM_VERBS] = {
    "is controlling",
    "wants to hide",
    "has been secretly watching",
    "created",
    "is conspiring with",
    "is secretly funding",
    "such that everyone believes",
    "aims to eradicate",
    "has a plan to implant microchips in",
    "is influencing the thoughts of"
};

const char *objects[NUM_OBJECTS] = {
    "all television shows",
    "the weather patterns",
    "human consciousness",
    "our dreams",
    "the food we eat",
    "the stock market",
    "the next generation of technology",
    "history books",
    "pet rocks",
    "unicorn sightings"
};

void generateTheory() {
    int subjectIndex = rand() % NUM_SUBJECTS;
    int verbIndex = rand() % NUM_VERBS;
    int objectIndex = rand() % NUM_OBJECTS;

    printf("%s %s %s.\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numTheories;
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &numTheories);

    printf("\nHere are %d thrilling conspiracy theories:\n", numTheories);
    for (int i = 0; i < numTheories; i++) {
        generateTheory();
    }

    printf("\nKeep questioning reality!\n");
    return 0;
}