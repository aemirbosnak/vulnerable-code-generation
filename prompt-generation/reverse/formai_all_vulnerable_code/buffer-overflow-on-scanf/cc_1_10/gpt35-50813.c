//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a haunted house
void simulateHauntedHouse() {
    // Initialize random seed and variables
    srand(time(NULL));
    int roomNum = rand() % 5 + 1;
    int steps = 0;

    // Display introductory message
    printf("Welcome to the haunted house simulator!\n");
    printf("You are currently in the foyer.\n");

    // Game loop
    while (roomNum != 5) {
        // Get user input
        char direction;
        printf("Which direction would you like to go? (N, S, E, W)\n");
        scanf(" %c", &direction);

        // Choose next room based on user input and update steps counter
        switch(direction) {
            case 'N':
                printf("You are now in the attic.\n");
                roomNum = 1;
                steps++;
                break;
            case 'S':
                printf("You are now in the basement.\n");
                roomNum = 2;
                steps++;
                break;
            case 'E':
                printf("You are now in the kitchen.\n");
                roomNum = 3;
                steps++;
                break;
            case 'W':
                printf("You are now in the living room.\n");
                roomNum = 4;
                steps++;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Introduce spooky events based on current room
        if (roomNum == 1) {
            printf("You hear strange whispers and creaking noises coming from the walls.\n");
        } else if (roomNum == 2) {
            printf("You feel a cold breeze and hear faint laughter in the distance.\n");
        } else if (roomNum == 3) {
            printf("You smell something rotten and notice the cabinets are all wide open.\n");
        } else if (roomNum == 4) {
            printf("You see an old rocking chair moving on its own.\n");
        }
    }

    // Display victory message and total steps taken
    printf("Congratulations, you made it out of the haunted house!\n");
    printf("It took you %d steps to escape.\n", steps);
}

// Main function to run program
int main() {
    simulateHauntedHouse();
    return 0;
}