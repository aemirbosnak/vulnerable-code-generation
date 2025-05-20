//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int score = 0;
    int planetCount = 0;
    int alienCount = 0;
    int time = 0;
    int fuel = 1000;
    int shipFuel = 1000;

    // Display initial message
    printf("Welcome to the Space Adventure!\n");

    // Loop until game over
    while (time < 100) {
        // Check if player is on a planet
        if (planetCount!= 0) {
            // Display planet name and options
            printf("You are on planet %d:\n", planetCount);
            printf("1. Explore\n");
            printf("2. Leave\n");
            printf("3. Fight Alien\n");
            printf("4. Check Fuel\n");
            printf("5. Check Time\n");
            printf("6. Return to Space Ship\n");
            printf("7. Quit\n");
            printf("Enter your choice: ");
            int choice = scanf("%d", &choice);

            // Handle choice
            switch (choice) {
                case 1:
                    printf("Exploring...\n");
                    time++;
                    break;
                case 2:
                    printf("Leaving planet...\n");
                    planetCount--;
                    break;
                case 3:
                    printf("Fighting alien...\n");
                    if (alienCount == 0) {
                        printf("You win!\n");
                        time++;
                        score++;
                        planetCount--;
                    } else {
                        printf("You lose!\n");
                        time++;
                        alienCount--;
                    }
                    break;
                case 4:
                    printf("Fuel level: %d\n", fuel);
                    break;
                case 5:
                    printf("Time remaining: %d\n", time);
                    break;
                case 6:
                    printf("Returning to space ship...\n");
                    shipFuel--;
                    if (shipFuel < 0) {
                        printf("Game Over!\n");
                        break;
                    }
                    break;
                case 7:
                    printf("Quitting game...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        }

        // Check if player is in space
        else {
            // Display options
            printf("You are in space:\n");
            printf("1. Explore\n");
            printf("2. Visit planet\n");
            printf("3. Check Fuel\n");
            printf("4. Check Time\n");
            printf("5. Return to Space Ship\n");
            printf("6. Quit\n");
            printf("Enter your choice: ");
            int choice = scanf("%d", &choice);

            // Handle choice
            switch (choice) {
                case 1:
                    printf("Exploring...\n");
                    time++;
                    break;
                case 2:
                    printf("Visiting planet...\n");
                    planetCount++;
                    break;
                case 3:
                    printf("Fuel level: %d\n", fuel);
                    break;
                case 4:
                    printf("Time remaining: %d\n", time);
                    break;
                case 5:
                    printf("Returning to space ship...\n");
                    shipFuel--;
                    if (shipFuel < 0) {
                        printf("Game Over!\n");
                        break;
                    }
                    break;
                case 6:
                    printf("Quitting game...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        }

        // Check if time is up
        if (time == 100) {
            printf("Time's up!\n");
            printf("Score: %d\n", score);
            printf("Alien count: %d\n", alienCount);
            printf("Fuel remaining: %d\n", fuel);
            printf("Ship fuel remaining: %d\n", shipFuel);
            break;
        }

        // Check if fuel is low
        if (fuel <= 0) {
            printf("Out of fuel!\n");
            printf("Game Over!\n");
            break;
        }

        // Check if ship fuel is low
        if (shipFuel <= 0) {
            printf("Out of ship fuel!\n");
            printf("Game Over!\n");
            break;
        }

        // Display prompt
        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}