//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Function to simulate an alien invasion
void simulateInvasion() {
    int success = 0;
    int attempts = 0;

    while (attempts < 10) {
        int defense = generateRandomNumber();
        int invasion = generateRandomNumber();

        if (invasion <= defense) {
            success = 1;
            break;
        }

        attempts++;
    }

    if (success) {
        printf("The aliens have been repelled!\n");
    } else {
        printf("The aliens have invaded Earth!\n");
    }
}

int main() {
    srand(time(NULL));

    int numSimulations;
    printf("How many simulations do you want to run? ");
    scanf("%d", &numSimulations);

    int invasions = 0;

    for (int i = 0; i < numSimulations; i++) {
        simulateInvasion();
        if (invasions == 0) {
            printf("Invasion probability: 0%\n");
        } else {
            printf("Invasion probability: %d%\n", invasions * 10);
        }
        invasions = 0;
    }

    return 0;
}