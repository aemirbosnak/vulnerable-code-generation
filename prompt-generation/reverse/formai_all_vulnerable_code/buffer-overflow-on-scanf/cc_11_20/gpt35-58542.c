//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int fuel = 100;
    int distance = 0;
    int oxygen = 100;
    int alien = 0;
    int found = 0;
    int randnum;
    srand(time(NULL));
    
    printf("Welcome to your Procedural Space Adventure!\n");
    printf("--------------------------------------------\n");
    printf("You are the captain of the spaceship U.S.S. Explorer.\n");
    printf("You are on a mission to explore uncharted parts of the galaxy.\n");
    printf("You have only 100 units of fuel and oxygen.\n");
    printf("Your mission is to find a habitable planet and return to Earth.\n");
    printf("--------------------------------------------\n");

    while (distance < 20) {
        printf("\nWhat do you want to do?\n");
        printf("1. Fly forward (costs 10 fuel, 5 oxygen)\n");
        printf("2. Scan for a planet (costs 20 fuel)\n");
        printf("3. Check your resources\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (fuel < 10 || oxygen < 5) {
                    printf("You don't have enough resources to fly forward!\n");
                } else {
                    fuel -= 10;
                    oxygen -= 5;
                    distance++;
                    if (alien == 1) {
                        randnum = rand() % 10;
                        if (randnum > 5) {
                            printf("You encountered an alien and it attacked your ship!\n");
                            fuel -= 30;
                            oxygen -= 20;
                            alien = 0;
                        } else {
                            printf("You encountered an alien but it seems to be friendly.\n");
                        }
                    } else {
                        randnum = rand() % 10;
                        if (randnum > 7) {
                            printf("You encountered an alien!\n");
                            alien = 1;
                        }
                    }
                    printf("You have flown forward one unit.\n");
                }
                break;
            case 2:
                if (fuel < 20) {
                    printf("You don't have enough fuel to scan for a planet!\n");
                } else {
                    fuel -= 20;
                    randnum = rand() % 10;
                    if (randnum > 5) {
                        printf("You found a habitable planet!\n");
                        found = 1;
                    } else {
                        printf("You didn't find any habitable planets.\n");
                    }
                }
                break;
            case 3:
                printf("Fuel: %d\n", fuel);
                printf("Oxygen: %d\n", oxygen);
                printf("Distance from Earth: %d units\n", distance);
                if (alien == 1) {
                    printf("There is an alien aboard your ship.\n");
                }
                break;
            case 4:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        if (found == 1) {
            break;
        }

        if (fuel <= 0 || oxygen <= 0) {
            printf("You ran out of fuel or oxygen and can't continue your mission anymore!\n");
            return 0;
        }
    }

    printf("\nCongratulations! You have successfully found a habitable planet and returned to Earth!\n");
    return 0;
}