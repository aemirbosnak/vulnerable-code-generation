//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10 //Number of rooms in haunted house
#define GHOST_CHANCE 25 //Percentage chance that a room contains a ghost

int main() {
    srand(time(NULL)); //Seed random number generator
    
    int rooms[ROOMS]; //Array to store the contents of each room
    
    //Initialize rooms with random contents
    for (int i = 0; i < ROOMS; i++) {
        if (rand() % 100 < GHOST_CHANCE) { //Chance the room contains a ghost
            rooms[i] = 1; //1 represents a room with a ghost
        } else {
            rooms[i] = 0; //0 represents an empty room
        }
    }
    
    int current_room = 0; //Start in first room
    int steps = 0; //Keep track of number of steps taken
    
    //Main loop to navigate haunted house
    while (current_room < ROOMS) {
        printf("You are in Room %d\n", current_room + 1); //Show current room number
        
        if (rooms[current_room] == 1) { //If the room has a ghost
            printf("You have encountered a ghost! Game Over.\n");
            break; //End the game
        }
        
        int move; //Variable to store user's move choice
        printf("Which room do you want to move to? (Enter room number): ");
        scanf("%d", &move); //Get user input
        
        if (move == current_room + 1) { //If user tries to stay in same room
            printf("You are already in that room. Try again.\n");
        } else if (move < 1 || move > ROOMS) { //If user chooses an invalid room
            printf("That is not a valid room. Try again.\n");
        } else if (move < current_room + 1) { //If user chooses a room already visited
            printf("You've already been in that room. Try again.\n");
        } else { //If user chooses a new valid room
            current_room = move - 1; //Move to new room
            steps++; //Increment number of steps taken
        }
        
        printf("\n");
    }
    
    printf("You made it out of the haunted house in %d steps! Congratulations!\n", steps);
    
    return 0;
}