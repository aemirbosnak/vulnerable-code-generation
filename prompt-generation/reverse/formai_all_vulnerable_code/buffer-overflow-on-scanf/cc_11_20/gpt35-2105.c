//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    int choice;
    int distance = 0;
    int fuel = 100;
    int energy = 100;
    int food = 100;
    char planet[10];

    printf("Welcome to the Procedural Space Adventure Game!\n");

    while (distance < 1000 && fuel > 0 && energy > 0 && food > 0) {
        printf("\n");
        printf("You are currently %d light years away from Earth and have:\n", distance);
        printf("- %d units of fuel\n", fuel);
        printf("- %d units of energy\n", energy);
        printf("- %d units of food\n", food);
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Travel to a new planet\n");
        printf("2. Refuel the spaceship\n");
        printf("3. Recharge the spaceship's energy\n");
        printf("4. Restock the spaceship's food supply\n");
        printf("5. Quit the game\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Travel to a new planet
                printf("\n");
                printf("Enter the name of the planet you would like to travel to: ");
                scanf("%s", planet);
                printf("Traveling to planet %s...\n", planet);
                sleep(2);
                printf("Arrived at planet %s!\n", planet);
                distance += 250;
                fuel -= 50;
                energy -= 20;
                food -= 30;
                break;
            case 2:
                // Refuel the spaceship
                printf("\n");
                printf("Refueling spaceship...\n");
                sleep(2);
                printf("Spaceship successfully refueled!\n");
                fuel = 100;
                energy -= 10;
                food -= 5;
                break;
            case 3:
                // Recharge the spaceship's energy
                printf("\n");
                printf("Recharging spaceship's energy...\n");
                sleep(2);
                printf("Spaceship's energy successfully recharged!\n");
                energy = 100;
                fuel -= 5;
                food -= 5;
                break;
            case 4:
                // Restock the spaceship's food supply
                printf("\n");
                printf("Restocking spaceship's food supply...\n");
                sleep(2);
                printf("Spaceship's food supply successfully restocked!\n");
                food = 100;
                fuel -= 5;
                energy -= 5;
                break;
            case 5:
                // Quit the game
                printf("\n");
                printf("Quitting game...\n");
                sleep(1);
                printf("Game over!\n");
                exit(0);
            default:
                printf("\n");
                printf("Invalid choice. Please try again.\n");
        }

        if (distance >= 1000) {
            printf("\n");
            printf("Congratulations! You have successfully completed the Procedural Space Adventure Game!\n");
            exit(0);
        }

        if (fuel <= 0) {
            printf("\n");
            printf("Game over! You ran out of fuel and were unable to continue your journey.\n");
            exit(0);
        }

        if (energy <= 0) {
            printf("\n");
            printf("Game over! You were unable to continue your journey due to lack of energy.\n");
            exit(0);
        }

        if (food <= 0) {
            printf("\n");
            printf("Game over! You were unable to continue your journey due to lack of food.\n");
            exit(0);
        }
    }

    return 0;
}