//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 20
#define MAX_FACTORS 10

const char *subjects[] = {
    "aliens", "government", "big pharma", "CEOs", "the moon landing",
    "cryptocurrency", "climate change", "flat earth", "the internet", "vaccines"
};

const char *actions[] = {
    "are brainwashing us", "control the weather", "hoard gold",
    "manipulate raw data", "created the internet", "fake historical events",
    "monitor our thoughts", "sell our secrets", "use mind control",
    "hide ancient artifacts"
};

const char *connections[] = {
    "to keep us distracted", "to sell us products", "for global domination",
    "to profit from fear", "to maintain control", "to alter reality",
    "to rewrite history", "to exploit natural resources", "to suppress knowledge",
    "to prevent unity"
};

const char *witnesses[] = {
    "a whistleblower", "a time traveler", "an uncontacted tribe",
    "ancient manuscripts", "the world's top scientists", "the internet's deep web",
    "a retired astronaut", "a rogue AI", "numerous pets", "my neighbor’s cat"
};

const char *conclusions[] = {
    "this is why the sky is blue.", "that's how the pyramids were built.",
    "it explains why my neighbor never smiles.", "they're hiding something big.",
    "this could change everything.", "that's how they take control.",
    "it all makes sense now.", "they use secret tunnels.",
    "our future is now at risk!", "the truth is out there!"
};

void generateTheory() {
    srand(time(NULL)); // Seed for randomness
    
    // Randomly select components
    const char *subject = subjects[rand() % MAX_THEORIES];
    const char *action = actions[rand() % MAX_THEORIES];
    const char *connection = connections[rand() % MAX_THEORIES];
    const char *witness = witnesses[rand() % MAX_THEORIES];
    const char *conclusion = conclusions[rand() % MAX_THEORIES];

    // Construct and display the conspiracy theory
    printf("Conspiracy Theory:\n");
    printf("Did you know that %s %s %s? According to %s, %s\n\n",
           subject, action, connection, witness, conclusion);
}

int main() {
    int numberOfTheories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &numberOfTheories);

    if (numberOfTheories < 1 || numberOfTheories > MAX_FACTORS) {
        printf("Please enter a number between 1 and %d.\n", MAX_FACTORS);
        return 1;
    }

    for (int i = 0; i < numberOfTheories; i++) {
        generateTheory();
    }

    printf("Remember, the truth is out there!\n");
    return 0;
}