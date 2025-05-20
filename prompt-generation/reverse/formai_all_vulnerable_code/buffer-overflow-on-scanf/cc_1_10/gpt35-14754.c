//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between two values */
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

/* Function to print a message and wait for input */
void printAndWait(char *message) {
    printf("%s\n", message);
    printf("(Press enter to continue)\n");
    getchar();
}

int main() {
    srand(time(NULL)); /* Initiate random seed */

    /* Welcome message */
    printf("Welcome to Procedural Space Adventure!\n");

    /* Initialize variables */
    int isShipDestroyed = 0;
    int travelDistance = 0;
    int totalFuel = 100;
    int currentFuel = totalFuel;
    int currentHullIntegrity = 100;
    char currentHullStatus[50] = "Intact";

    /* Game loop */
    while (!isShipDestroyed) {

        /* Generate random event */
        int eventNum = generateRandomNumber(1, 3);

        if (eventNum == 1) { /* Asteroid field */
            printAndWait("You have encountered an asteroid field.");
            int damage = generateRandomNumber(20, 40);
            currentHullIntegrity -= damage;

            /* Update hull status */
            if (currentHullIntegrity <= 0) {
                isShipDestroyed = 1;
                sprintf(currentHullStatus, "Destroyed");
            } else if (currentHullIntegrity <= 50) {
                sprintf(currentHullStatus, "Damaged");
            } else if (currentHullIntegrity <= 80) {
                sprintf(currentHullStatus, "Slightly damaged");
            } else {
                sprintf(currentHullStatus, "Intact");
            }

            printf("Your ship has taken %d damage.\n", damage);

        } else if (eventNum == 2) { /* Space station */
            printAndWait("You have found a space station.");
            int fuelGain = generateRandomNumber(20, 50);
            currentFuel += fuelGain;

            /* Update total and current fuel */
            if (currentFuel > totalFuel) {
                currentFuel = totalFuel;
            }

            printf("You have gained %d fuel.\n", fuelGain);

        } else { /* Alien encounter */
            printAndWait("You have encountered an alien species.");
            int fleeChance = generateRandomNumber(1, 3);

            if (fleeChance == 1) {
                printf("You have successfully fled from the alien species.\n");
            } else {
                int damage = generateRandomNumber(30, 50);
                currentHullIntegrity -= damage;

                /* Update hull status */
                if (currentHullIntegrity <= 0) {
                    isShipDestroyed = 1;
                    sprintf(currentHullStatus, "Destroyed");
                } else if (currentHullIntegrity <= 50) {
                    sprintf(currentHullStatus, "Damaged");
                } else if (currentHullIntegrity <= 80) {
                    sprintf(currentHullStatus, "Slightly damaged");
                } else {
                    sprintf(currentHullStatus, "Intact");
                }

                printf("Your ship has taken %d damage.\n", damage);
            }
        }

        /* Print current status */
        printf("\n\nCurrent Status:\n");
        printf("Hull Integrity: %d%% (%s)\n", currentHullIntegrity, currentHullStatus);
        printf("Fuel: %d/%d\n", currentFuel, totalFuel);
        printf("Travel Distance: %d Light Years\n", travelDistance);

        /* Ask user if they want to continue or quit */
        char choice;
        printf("\nDo you want to continue traveling? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            printf("Thank you for playing Procedural Space Adventure. Goodbye!\n");
            break;
        }

        /* Update variables for next loop */
        travelDistance += generateRandomNumber(1, 20);
        currentFuel -= generateRandomNumber(5, 20);

        /* Check if player ran out of fuel */
        if (currentFuel <= 0) {
            isShipDestroyed = 1;
            printf("Your ship has run out of fuel and is stranded in space. Game Over.\n");
        }
    }

    return 0;
}