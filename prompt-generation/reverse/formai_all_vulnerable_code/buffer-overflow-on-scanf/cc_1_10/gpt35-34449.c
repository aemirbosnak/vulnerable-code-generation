//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generation

    int fuel = 100;
    int oxygen = 100;

    printf("You wake up from suspended animation to find yourself on a spaceship. Your mission is to explore the unknown reaches of space and make contact with any extraterrestrial life.\n");

    while (fuel > 0 && oxygen > 0) { // main game loop
        printf("You have %d units of fuel and %d units of oxygen left.\n", fuel, oxygen);
        printf("What would you like to do? (1) Explore planet (2) Fly to next planet (3) Check status\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) { // exploration
            int chance = rand() % 100 + 1; // randomly determine chance of encountering aliens

            if (chance <= 30) { // encounter aliens!
                printf("You have made contact with an alien race! They offer you a gift of extra oxygen and fuel.\n");
                fuel += 20;
                oxygen += 20;
            }
            else { // nothing found
                printf("You explore the planet but find nothing of interest.\n");
                fuel -= 10;
                oxygen -= 10;
            }
        }
        else if (choice == 2) { // flying to next planet
            fuel -= 30;
            oxygen -= 10;
            printf("You fly to the next planet.\n");
        }
        else if (choice == 3) { // check status
            printf("Fuel: %d\n", fuel);
            printf("Oxygen: %d\n", oxygen);
        }
        else { // invalid choice
            printf("Invalid choice.\n");
        }

        if (fuel <= 0 || oxygen <= 0) { // game over if out of fuel or oxygen
            printf("You have run out of fuel or oxygen.\n");
            break;
        }
    }

    printf("Game over. Thanks for playing!\n");

    return 0;
}