//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a given range
int generateRandomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("*** Welcome to the Procedural Space Adventure! ***\n\n");

    // Generate random values for the distance to travel, fuel, and supplies
    int distance = generateRandomNumber(100, 1000);
    float fuel = generateRandomNumber(50, 500);
    int supplies = generateRandomNumber(10, 100);

    // Print the generated values
    printf("You are about to embark on a journey through space!\n");
    printf("You need to travel a distance of %d light years.\n", distance);
    printf("You have %.0f units of fuel and %d units of supplies.\n\n", fuel, supplies);

    // Begin the adventure
    while (distance > 0) {
        printf("You are currently %.0f light years away from your destination.\n", (float)distance);

        // Generate random events
        int event = generateRandomNumber(1, 3);
        switch (event) {
            case 1: // Asteroid belt
                printf("Oh no! You have encountered an asteroid belt!\n");
                printf("You need to navigate through it carefully.\n");
                printf("Rolling the dice...\n");
                int dice = generateRandomNumber(1, 6);
                if (dice >= 4) {
                    printf("Phew! You have successfully navigated through the asteroid belt.\n");
                } else {
                    printf("Oh no! You have been hit by an asteroid and lost some supplies.\n");
                    supplies -= generateRandomNumber(1, 10);
                    if (supplies <= 0) {
                        printf("You have run out of supplies! Game over.\n");
                        return 0;
                    }
                }
                break;
            case 2: // Alien encounter
                printf("Oh no! You have encountered an alien spaceship!\n");
                printf("You need to choose whether to fight or negotiate.\n");
                printf("Rolling the dice...\n");
                int dice2 = generateRandomNumber(1, 6);
                if (dice2 >= 4) {
                    printf("Congratulations! You have successfully negotiated with the aliens.\n");
                    supplies += generateRandomNumber(5, 15);
                } else {
                    printf("Uh oh! The aliens have attacked you!\n");
                    int damage = generateRandomNumber(10, 50);
                    fuel -= (float)damage;
                    if (fuel <= 0) {
                        printf("You have run out of fuel! Game over.\n");
                        return 0;
                    }
                }
                break;
            case 3: // Space anomaly
                printf("Interesting! You have encountered a rare space anomaly.\n");
                printf("You are curious and want to investigate it. Do you?\n");
                printf("Press y for yes and n for no: ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("You investigate the space anomaly and discover a new technology!\n");
                    printf("Your spaceship is now equipped with a warp drive, allowing you to travel faster!\n");
                    distance /= 2;
                } else {
                    printf("You decide to continue your journey without investigating the space anomaly.\n");
                }
                break;
        }

        // Update distance, fuel, and supplies
        int distanceTraveled = generateRandomNumber(50, 200);
        distance -= distanceTraveled;
        printf("You have traveled %d light years.\n", distanceTraveled);
        fuel -= (float)distanceTraveled / generateRandomNumber(5, 20);
        if (fuel <= 0) {
            printf("You have run out of fuel! Game over.\n");
            return 0;
        }
        supplies -= generateRandomNumber(1, 5);
        if (supplies <= 0) {
            printf("You have run out of supplies! Game over.\n");
            return 0;
        }
    }

    printf("\nCongratulations! You have successfully completed your Procedural Space Adventure!\n");
    printf("You have arrived at your destination and have %.0f units of fuel and %d units of supplies remaining.\n", fuel, supplies);

    return 0;
}