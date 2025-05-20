//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_AGENTS 10
#define MAX_LOCATIONS 10
#define MAX_EVIDENCES 10

const char* conspiracies[MAX_CONSPIRACIES] = {
    "the moon landing was faked",
    "aliens are controlling our thoughts",
    "the government is hiding the cure for aging",
    "vaccines contain mind-control agents",
    "Bigfoot is a secret government experiment",
    "the earth is flat and ruled by lizard people",
    "COVID-19 was created in a lab to control the population",
    "time travelers are altering history",
    "the media is run by a cabal of globalists",
    "the pyramids were built by extraterrestrials"
};

const char* agents[MAX_AGENTS] = {
    "the CIA",
    "NASA",
    "the Illuminati",
    "Big Pharma",
    "the Freemasons",
    "the United Nations",
    "Tech Giants",
    "Hollywood elites",
    "the New World Order",
    "local squirrels"
};

const char* locations[MAX_LOCATIONS] = {
    "Area 51",
    "the Bermuda Triangle",
    "a secret underground base",
    "the Vatican",
    "a remote island in the Pacific",
    "the heart of Silicon Valley",
    "the moon",
    "a mysterious forest",
    "the White House",
    "a hidden bunker"
};

const char* evidences[MAX_EVIDENCES] = {
    "a leaked document",
    "witness testimonies",
    "unexplained phenomena",
    "ancient texts",
    "computer glitches",
    "videos posted on the internet",
    "strange symbols",
    "missing person cases",
    "government contracts",
    "unrevealed technology"
};

void generate_conspiracy_theory() {
    // Seed the random number generator
    srand(time(NULL));

    // Randomly select components for the conspiracy theory
    const char* conspiracy = conspiracies[rand() % MAX_CONSPIRACIES];
    const char* agent = agents[rand() % MAX_AGENTS];
    const char* location = locations[rand() % MAX_LOCATIONS];
    const char* evidence = evidences[rand() % MAX_EVIDENCES];

    // Generate and print the conspiracy theory
    printf("Conspiracy Theory:\n");
    printf("-----------------------------------------------------\n");
    printf("It is widely believed that %s, orchestrated by %s. Evidence points to %s located at %s.\n",
           conspiracy, agent, evidence, location);
    printf("-----------------------------------------------------\n\n");
}

int main() {
    int number_of_theories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &number_of_theories);

    // Ensure number of theories is within a reasonable range
    if (number_of_theories < 1 || number_of_theories > 100) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("\nGenerating %d conspiracy theories...\n\n", number_of_theories);

    for (int i = 0; i < number_of_theories; i++) {
        generate_conspiracy_theory();
    }

    printf("Thank you for using the Conspiracy Theory Generator!\n");
    return 0;
}