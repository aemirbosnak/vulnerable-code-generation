//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define some categories and their potential theories
const char* subjects[] = {
    "the moon landing",
    "Area 51",
    "Bigfoot",
    "the Illuminati",
    "the Bermuda Triangle",
    "aliens",
    "the lost city of Atlantis",
    "government surveillance",
    "COVID-19 vaccines",
    "the flat earth theory"
};

const char* actions[] = {
    "was staged",
    "is a cover-up for",
    "is a distraction from",
    "is being used to control",
    "is a secret project designed to",
    "is part of a larger plan to",
    "has hidden evidence of",
    "is connected to",
    "links back to",
    "is related to an ancient prophecy about"
};

const char* entities[] = {
    "the government",
    "the corporations",
    "secret societies",
    "reptilian overlords",
    "time travelers",
    "the scientific community",
    "the media",
    "hidden civilizations",
    "elite politicians",
    "supernatural beings"
};

const char* consequences[] = {
    "so we can never truly know the truth.",
    "to make us question our reality.",
    "as a way to distract from important issues.",
    "to manipulate public opinion for their gain.",
    "to prepare us for a future where we can't escape.",
    "to control our minds and bodies.",
    "to hide more sinister agendas.",
    "to ensure their power over us.",
    "to rewrite history as they see fit.",
    "to make us reliant on technology."
};

// Function to get a random element from an array
const char* getRandomElement(const char* array[], int size) {
    return array[rand() % size];
}

// Function to construct a conspiracy theory
void generateConspiracyTheory() {
    const char* subject = getRandomElement(subjects, sizeof(subjects) / sizeof(subjects[0]));
    const char* action = getRandomElement(actions, sizeof(actions) / sizeof(actions[0]));
    const char* entity = getRandomElement(entities, sizeof(entities) / sizeof(entities[0]));
    const char* consequence = getRandomElement(consequences, sizeof(consequences) / sizeof(consequences[0]));

    printf("Conspiracy Theory: %s %s %s %s\n", subject, action, entity, consequence);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    int numberOfTheories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &numberOfTheories);

    for (int i = 0; i < numberOfTheories; i++) {
        generateConspiracyTheory();
    }

    return 0;
}