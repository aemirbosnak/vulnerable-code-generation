//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int fuel = 100;
    int distance = 0;
    int max_distance = 500;

    srand(time(NULL)); // Seed for generating random events

    printf("Welcome to the Procedural Space Adventure!\n\n");
    printf("Your mission, should you choose to accept it, is to explore as far as possible into space.\n");
    printf("But be warned, there are dangerous events that may occur on your journey.\n\n");

    while (distance < max_distance && fuel > 0) {
        printf("Current Distance: %d km\n", distance);
        printf("Fuel Remaining: %d%%\n\n", fuel);

        printf("Choose what to do next:\n");
        printf("1. Travel at Light Speed (50%% fuel, high chance of event)\n");
        printf("2. Travel at Medium Speed (25%% fuel, moderate chance of event)\n");
        printf("3. Travel at Low Speed (10%% fuel, low chance of event)\n");
        printf("4. Refuel (100%% fuel, no event)\n");
        printf("5. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: {
                int event = rand() % 3; // 33% chance of event

                fuel -= 50;
                distance += 100;

                if (event == 0) {
                    printf("WARNING: Your ship has encountered a meteor shower!\n");
                    printf("Your ship has sustained heavy damage and has lost 50%% fuel.\n\n");
                    fuel /= 2;
                }
                else if (event == 1) {
                    printf("WARNING: Your ship is being sucked into a black hole!\n");
                    printf("Your ship has lost 25%% fuel and your distance has been reset.\n\n");
                    fuel /= 4;
                    distance = 0;
                }
                else {
                    printf("You have traveled 100 km at light speed without any events!\n\n");
                }

                break;
            }

            case 2: {
                int event = rand() % 2; // 50% chance of event

                fuel -= 25;
                distance += 50;

                if (event == 0) {
                    printf("WARNING: Your ship has encountered space debris!\n");
                    printf("Your ship has sustained minor damage and has lost 25%% fuel.\n\n");
                    fuel /= 2;
                }
                else {
                    printf("You have traveled 50 km at medium speed without any events!\n\n");
                }

                break;
            }

            case 3: {
                int event = rand() % 4; // 25% chance of event

                fuel -= 10;
                distance += 20;

                if (event == 0) {
                    printf("WARNING: Your ship has encountered an alien attack!\n");
                    printf("Your ship has lost 50%% fuel and has sustained heavy damage.\n\n");
                    fuel /= 2;
                }
                else {
                    printf("You have traveled 20 km at low speed without any events!\n\n");
                }

                break;
            }

            case 4: {
                fuel = 100;
                printf("Your ship has been refueled to 100%%!\n\n");
                break;
            }

            case 5: {
                printf("You have chosen to quit the game. Goodbye!\n");
                return 0;
            }

            default: {
                printf("Invalid choice. Please choose again.\n\n");
            }
        }
    }

    if (distance >= max_distance) {
        printf("Congratulations! You have successfully traveled %d km into space!\n", max_distance);
    }
    else {
        printf("GAME OVER: Your ship has run out of fuel and cannot continue.\n");
    }

    return 0;
}