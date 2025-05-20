//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define struct for planets
struct planet {
    char name[20];
    int distance;
    int resources;
};

int main() {
    // Declare and initialize planets
    struct planet mercury = {"Mercury", 36, 120};
    struct planet venus = {"Venus", 67, 340};
    struct planet earth = {"Earth", 93, 500};
    struct planet mars = {"Mars", 142, 230};
    struct planet jupiter = {"Jupiter", 484, 1100};

    // Declare and initialize spaceship stats
    int fuel = 1000;
    int cargo = 0;
    int distance_traveled = 0;
    
    // Display welcome message
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship, and your mission is to explore the galaxy and collect resources.\n");
    printf("You start your journey on Earth, and your goal is to visit all the planets in the solar system.\n\n");
    
    // Main game loop
    while (1) {
        // Display current stats
        printf("Distance traveled: %d\n", distance_traveled);
        printf("Remaining fuel: %d\n", fuel);
        printf("Cargo: %d\n\n", cargo);

        // Display options for traveling to planets
        printf("Choose a planet to travel to:\n");
        printf("1. Mercury (%d million km away)\n", mercury.distance);
        printf("2. Venus (%d million km away)\n", venus.distance);
        printf("3. Mars (%d million km away)\n", mars.distance);
        printf("4. Jupiter (%d million km away)\n", jupiter.distance);
        printf("5. Quit game\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Handle user choices
        switch(choice) {
            case 1:
                printf("Traveling to Mercury...\n");
                fuel -= 20; // Decrease fuel for traveling
                distance_traveled += mercury.distance; // Add distance traveled
                cargo += mercury.resources; // Collect resources
                break;
            case 2:
                printf("Traveling to Venus...\n");
                fuel -= 25;
                distance_traveled += venus.distance;
                cargo += venus.resources;
                break;
            case 3:
                printf("Traveling to Mars...\n");
                fuel -= 30;
                distance_traveled += mars.distance;
                cargo += mars.resources;
                break;
            case 4:
                printf("Traveling to Jupiter...\n");
                fuel -= 50;
                distance_traveled += jupiter.distance;
                cargo += jupiter.resources;
                break;
            case 5:
                // Quit the game
                printf("Thanks for playing! Goodbye.\n");
                exit(0);
            default:
                // Handle invalid input
                printf("Invalid choice. Please choose a number between 1 and 5.\n");
                break;
        }

        // Check if the game is over
        if (cargo >= 1500) {
            printf("Congratulations! You collected enough resources to retire and live a comfortable life.\n");
            exit(0);
        }
        else if (fuel < 0) {
            printf("You ran out of fuel and are stranded in space. Game over.\n");
            exit(0);
        }
    }

    return 0;
}