//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int fuel = 100, distance = 0;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to Procedural Space Adventure!\n");

    while (fuel > 0 && distance < 500) { // game loop
        int event = rand() % 3; // generate random event (0-2)

        if (event == 0) { // asteroid field
            fuel -= 20;
            printf("You have encountered an asteroid field!\n");
            printf("Your fuel has decreased by 20.\n");
        }
        else if (event == 1) { // alien attack
            fuel -= 30;
            printf("You have been attacked by aliens!\n");
            printf("Your fuel has decreased by 30.\n");
        }
        else { // nothing happens
            printf("You continue on your journey.\n");
        }

        distance += 50;
        printf("You have travelled %d kilometers.\n", distance);

        if (fuel <= 0) { // out of fuel
            printf("You have run out of fuel. Game over.\n");
            break;
        }
        else if (distance >= 500) { // reached destination
            printf("You have arrived at your destination!\n");
            printf("Congratulations, you have completed the game.\n");
            break;
        }

        printf("You have %d units of fuel left.\n", fuel);
        printf("Enter 'r' to refuel or any other key to continue.\n");

        char choice;
        scanf(" %c", &choice);

        if (choice == 'r') { // refuel
            fuel = 100;
            printf("You have refuelled and have %d units of fuel.\n", fuel);
        }
        else { // continue
            printf("You have chosen to continue.\n");
        }

        printf("--------------------------------------------------\n");
    }

    return 0;
}