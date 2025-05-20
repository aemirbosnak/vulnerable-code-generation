//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10 // define the number of rooms in the haunted house

int main() {
    srand(time(NULL)); // set seed for random number generation
    
    char rooms[ROOMS][50] = {
        "Living Room", "Bedroom", "Kitchen", "Dining Room", "Bathroom",
        "Basement", "Attic", "Hallway", "Study", "Library"
    }; // list of the different rooms in the haunted house
    
    int occupants[ROOMS] = {0}; // array to store number of occupants in each room
    occupants[0] = rand() % 10 + 1; // set random number of occupants in the first room
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your goal is to escape the haunted house without getting caught by the ghosts!\n");
    printf("You start in the %s with %d other people.\n", rooms[0], occupants[0]);
    
    int currentRoom = 0; // set initial room to the first room
    int steps = 0; // count number of steps taken
    
    while (currentRoom != ROOMS - 1) { // keep playing until the player reaches the exit
        printf("You are currently in the %s with %d other people.\n", rooms[currentRoom], occupants[currentRoom]);
        printf("Which room would you like to move to? (Enter a number between 1 and 10)\n");
        
        int choice;
        scanf("%d", &choice); // get user input
        
        if (choice < 1 || choice > 10 || choice == currentRoom + 1) { // handle invalid inputs
            printf("Invalid choice. Try again.\n");
            continue;
        }
        
        currentRoom = choice - 1; // move to the chosen room
        occupants[currentRoom] += rand() % 5 + 1; // generate random number of occupants in the new room
        
        if (rand() % 100 < 10 * steps / ROOMS) { // 10% chance of encountering a ghost in each room
            printf("You have encountered a ghost! You are now trapped in the %s forever.\n", rooms[currentRoom]);
            printf("GAME OVER.\n");
            return 0; // end the game
        }
        
        steps++; // increment the number of steps taken
    }
    
    printf("Congratulations, you have escaped the haunted house!\n");
    printf("You took %d steps to get to the exit.\n", steps);
    
    return 0; // end the game
}