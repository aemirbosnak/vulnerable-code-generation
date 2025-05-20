//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>

// Define the periodic table with post-apocalyptic elements
const char* elements[] = {
    "Acid Rain",
    "Ash",
    "Blast",
    "Cinder",
    "Decay",
    "Ember",
    "Famine",
    "Gamma",
    "Haze",
    "Iridium",
    "Junk",
    "Krypton",
    "Lava",
    "Meltdown",
    "Nova",
    "Ozone",
    "Plague",
    "Quake",
    "Radon",
    "Scorch",
    "Toxic",
    "Uranium",
    "Virus",
    "Wasteland",
    "Xenon",
    "Yttrium",
    "Zombie"
};

int main() {
    int numElements = sizeof(elements)/sizeof(elements[0]);
    int score = 0;

    // Quiz loop
    for (int i = 0; i < numElements; i++) {
        printf("Question %d: What element is represented by the symbol %s?\n", i+1, elements[i]);
        char answer[20];
        scanf("%s", answer);

        // Check answer
        if (strcmp(answer, elements[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    // Print final score
    printf("You scored %d out of %d questions correct.\n", score, numElements);

    return 0;
}