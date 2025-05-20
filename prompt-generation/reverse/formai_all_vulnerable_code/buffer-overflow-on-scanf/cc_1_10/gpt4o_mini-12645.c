//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

// Structure to hold a conspiracy theory
typedef struct {
    char title[MAX_LENGTH];
    char body[MAX_LENGTH];
} ConspiracyTheory;

// List of conspiracy theory titles
const char *titles[] = {
    "The Moon Landing was Staged",
    "Aliens Control the Weather",
    "The Lizard People Run the Government",
    "Bigfoot is an Experiment Gone Wrong",
    "The Bermuda Triangle is a Portal",
    "Aliens Built the Pyramids",
    "The Earth is Flat - It's All a Hoax",
    "The Government is Hiding Cures for Diseases",
    "Time Travel is Real and Used by the Elite",
    "Dinosaurs are Still Alive in a Secret Island"
};

// List of conspiracy theory bodies
const char *bodies[] = {
    "The moon landing was not possible with the technology of the 1960s. NASA staged it to win the space race.",
    "Weather patterns are manipulated by alien lifeforms that are living among us, ensuring humanity remains distracted.",
    "Hidden within the corridors of power are reptilian shapeshifters who perpetuate wars, control economies and extract human suffering.",
    "What we know as Bigfoot is actually a failed genetic experiment, broader than history itself.",
    "The Bermuda Triangle is actually a gateway to another dimension, used by advanced civilizations.",
    "Aliens helped our ancestors construct the pyramids using advanced technology beyond our current scientific understanding.",
    "The world is flat; our beliefs about the globe are all orchestrated by a group who aims to keep the truth hidden.",
    "There's a secret cabal that prevents life-saving cures from reaching the general population to maintain control over the pharmaceutical industry.",
    "Time travel technology exists, but only those in power utilize it to manipulate history to their advantage.",
    "Dinosaurs are secretly kept on a hidden island, and the governments use them as a deterrent for nuclear conflict."
};

// Function to generate a random conspiracy theory
void generateConspiracyTheory(ConspiracyTheory *theory) {
    // Get a random index for titles and bodies
    int titleIndex = rand() % (sizeof(titles) / sizeof(titles[0]));
    int bodyIndex = rand() % (sizeof(bodies) / sizeof(bodies[0]));

    // Populate the theory structure with the random title and body
    strcpy(theory->title, titles[titleIndex]);
    strcpy(theory->body, bodies[bodyIndex]);
}

// Function to print the conspiracy theory
void printConspiracyTheory(const ConspiracyTheory *theory) {
    printf("Conspiracy Theory:\n");
    printf("Title: %s\n", theory->title);
    printf("Details: %s\n\n", theory->body);
}

int main() {
    // Seed the random number generator using current time
    srand(time(NULL));
    
    // Create an array of conspiracy theories
    ConspiracyTheory theories[MAX_THEORIES];
    
    int n;  // Number of theories to generate
    printf("Enter the number of conspiracy theories to generate (max %d): ", MAX_THEORIES);
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    // Generate and print the conspiracy theories
    for (int i = 0; i < n; ++i) {
        generateConspiracyTheory(&theories[i]);
        printConspiracyTheory(&theories[i]);
    }

    return 0;
}