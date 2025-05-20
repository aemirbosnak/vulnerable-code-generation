//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 256
#define NUM_THEORIES 10
#define MAX_SUBJECTS 5
#define MAX_CLAIMS 7

const char *subjects[MAX_SUBJECTS] = {
    "aliens",
    "government",
    "big tech companies",
    "the elite",
    "scientists"
};

const char *claims[MAX_CLAIMS] = {
    "control our minds through social media.",
    "are hiding the truth about extraterrestrial life.",
    "are altering the weather to manipulate populations.",
    "use advanced technology to surveil us.",
    "have built underground cities.",
    "are manufacturing a new virus to implement population control.",
    "are planning to implement mandatory chip implants."
};

const char *locations[NUM_THEORIES] = {
    "Area 51",
    "the moon",
    "the Bermuda Triangle",
    "the Denver Airport",
    "a secret base in Antarctica",
    "the International Space Station",
    "the Vatican",
    "Silicon Valley",
    "a bunker in the Swiss Alps",
    "the Amazon rainforest"
};

const char *actors[NUM_THEORIES] = {
    "a secret society of world leaders",
    "a race of advanced beings",
    "powerful corporations",
    "the royal family",
    "government agencies",
    "the media establishment",
    "tech moguls",
    "ancient civilizations",
    "AI corporations",
    "the scientific community"
};

// Function to generate a random conspiracy theory
void generateConspiracyTheory(char *output) {
    int subjectIndex = rand() % MAX_SUBJECTS;
    int claimIndex = rand() % MAX_CLAIMS;
    int locationIndex = rand() % NUM_THEORIES;
    int actorIndex = rand() % NUM_THEORIES;

    // Build the conspiracy theory string
    snprintf(output, MAX_LEN, "The theory suggests that %s %s At %s, %s.",
             subjects[subjectIndex],
             claims[claimIndex],
             locations[locationIndex],
             actors[actorIndex]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char theory[MAX_LEN];
    int numberOfTheories;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? ");
    scanf("%d", &numberOfTheories);

    if(numberOfTheories < 1 || numberOfTheories > 10) {
        printf("Please enter a number between 1 and 10.\n");
        return 1;
    }

    printf("\nGenerating %d Conspiracy Theories...\n", numberOfTheories);
    for(int i = 0; i < numberOfTheories; i++) {
        generateConspiracyTheory(theory);
        printf("Theory %d: %s\n", i + 1, theory);
    }

    printf("\nThank you for using the Conspiracy Theory Generator!\n");
    return 0;
}