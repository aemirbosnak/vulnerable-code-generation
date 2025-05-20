//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare and initialize the rooms
    char rooms[ROOMS][20] = {
        "Entrance",
        "Foyer",
        "Kitchen",
        "Dining Room",
        "Living Room",
        "Library",
        "Bedroom",
        "Bathroom",
        "Attic",
        "Basement"
    };
    
    // Declare and initialize the state of each room
    int roomStates[ROOMS] = {0};
    int playerPos = 0;
    int isRunning = 1;
    
    // Game loop
    while(isRunning) {
        // Print an introduction message
        printf("You are in the %s.\n", rooms[playerPos]);
        
        // Check the state of the room
        if(roomStates[playerPos] == 0) {
            printf("The room is quiet.\n");
        } else {
            printf("You hear something moving in the room.\n");
        }
        
        // Get user input
        printf("Which direction do you want to go (n/s/e/w)? ");
        char input;
        scanf("%c", &input);
        
        // Handle user input
        if(input == 'n' && playerPos < ROOMS - 1) {
            playerPos++;
        } else if(input == 's' && playerPos > 0) {
            playerPos--;
        } else if(input == 'e' || input == 'w') {
            // Check if the room is haunted
            if(roomStates[playerPos] == 1) {
                printf("You feel a cold breeze and hear a strange noise. You're too scared to go this way.\n");
            } else {
                // Determine the probability of encountering a ghost
                int probability = rand() % 10;
                if(probability < 3) {
                    printf("As you move through the room, you hear a faint whisper and feel a chill down your spine. You're sure something is watching you.\n");
                    roomStates[playerPos] = 1;
                } else {
                    printf("You move through the room without incident.\n");
                }
                
                // Move the player
                if(input == 'e' && playerPos < ROOMS - 1) {
                    playerPos++;
                } else if(input == 'w' && playerPos > 0) {
                    playerPos--;
                }
            }
        }
        
        // Check if the player has reached the end
        if(playerPos == ROOMS - 1) {
            printf("You have reached the end of the haunted house!\n");
            isRunning = 0;
        }
        
        // Clear the input buffer
        fflush(stdin);
    }
    
    return 0;
}