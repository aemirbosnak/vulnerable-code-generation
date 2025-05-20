//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS_PER_ROOM 3

// Function to display the room description
void displayRoom(char* description) {
    printf("\n\n---------------------\n");
    printf("%s\n", description);
    printf("---------------------\n");
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define arrays for rooms and ghosts
    char* rooms[MAX_ROOMS] = {"A dark, dusty hallway",
                              "An old dining room with a chandelier",
                              "A creepy kitchen with rusted knives",
                              "A spooky bedroom with creaky floorboards",
                              "An abandoned library with dusty books",
                              "A cold and damp basement",
                              "A musty attic with cobwebs",
                              "A sinister study with a pentagram",
                              "A haunted bathroom with a blood-stained tub",
                              "A cursed nursery with broken toys"};
    char* ghosts[MAX_GHOSTS_PER_ROOM] = {"A spectral figure in a white gown",
                                         "A ghostly apparition of a young child",
                                         "A mysterious shadow that glides along the walls"};

    // Initialize variables for the game
    int currentRoom = rand() % MAX_ROOMS;
    bool gameOver = false;

    // Display the starting room
    displayRoom(rooms[currentRoom]);

    while(!gameOver) {
        // Determine the number of ghosts in the current room
        int numGhosts = rand() % (MAX_GHOSTS_PER_ROOM + 1);
        if(numGhosts > 0) {
            printf("You sense a chill in the air... you are not alone.\n");
            // Display the ghosts in the current room
            for(int i=0; i<numGhosts; i++) {
                printf("- %s\n", ghosts[rand() % MAX_GHOSTS_PER_ROOM]);
            }
        }

        // Ask the player what to do next
        printf("\nWhat do you do? (1) Explore another room (2) Try to leave\n");
        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Change to a random room
                currentRoom = rand() % MAX_ROOMS;
                displayRoom(rooms[currentRoom]);
                break;
            case 2:
                // Check if the player is leaving from the front door
                if(currentRoom == 0) {
                    printf("\nYou made it out alive! Congratulations!\n");
                    gameOver = true;
                } else {
                    printf("\nThat door won't budge. You are trapped in this house...\n");
                } 
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    // Game over
    printf("\n\nThank you for playing the Haunted House Simulator!\n");

    return 0;
}