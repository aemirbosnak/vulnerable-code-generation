//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print random scare messages
void scareMessage(void) {
    int random = rand() % 5; // Generate a random number
    switch (random) {
        case 0:
            printf("You feel a chill run down your spine.\n");
            break;
        case 1:
            printf("You hear a blood-curdling scream from upstairs.\n");
            break;
        case 2:
            printf("Something cold brushes past your shoulder.\n");
            break;
        case 3:
            printf("The door slams shut behind you, making you jump.\n");
            break;
        case 4:
            printf("You see a pair of glowing eyes staring back at you from the darkness.\n");
            break;
        default:
            printf("Error: Could not generate scare message.\n");
            break;
    }
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator
    
    int roomNumber = 1; // Starting room
    int flashlight = 1; // Flashlight is on by default
    int hasKey = 0; // Player does not have the key
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in the foyer of an old, dark mansion.\n");
    printf("Your mission is to find the key to unlock the front door and escape the house!\n");
    printf("Good luck...\n\n");
    
    // Main game loop
    while (roomNumber != 0) { // Room 0 is outside (end of the game)
        // Print current room description and options
        switch (roomNumber) {
            case 1:
                printf("You are in the foyer. There is a coat rack and a large staircase.\n");
                printf("What do you want to do?\n");
                printf("1. Look at the coat rack\n");
                printf("2. Go up the staircase\n");
                printf("3. Turn on/off the flashlight\n");
                scanf("%d", &roomNumber);
                break;
                
            case 2:
                printf("You are upstairs. There are three doors.\n");
                printf("What do you want to do?\n");
                printf("1. Try the first door\n");
                printf("2. Try the second door\n");
                printf("3. Try the third door\n");
                printf("4. Go back down the stairs\n");
                scanf("%d", &roomNumber);
                break;
                
            case 3:
                printf("You are in a bedroom. There is a bed, a dresser, and a window.\n");
                printf("What do you want to do?\n");
                printf("1. Look under the bed\n");
                printf("2. Look in the dresser\n");
                printf("3. Look out the window\n");
                printf("4. Go back to the hallway\n");
                scanf("%d", &roomNumber);
                break;
                
            case 4:
                printf("You are in a bathroom. There is a shower, a sink, and a toilet.\n");
                printf("What do you want to do?\n");
                printf("1. Look in the shower\n");
                printf("2. Look in the sink\n");
                printf("3. Look in the toilet\n");
                printf("4. Go back to the hallway\n");
                scanf("%d", &roomNumber);
                break;
                
            case 5:
                printf("You are in a closet. It's very dark.\n");
                printf("What do you want to do?\n");
                printf("1. Look for a light switch\n");
                printf("2. Feel around in the dark\n");
                printf("3. Go back to the hallway\n");
                scanf("%d", &roomNumber);
                break;
                
            case 6:
                printf("You found the key! You can now escape the house!\n");
                hasKey = 1; // Set flag to indicate player has the key
                roomNumber = 2; // Go back to the hallway
                break;
                
            default: // Invalid room number
                printf("Error: Invalid room number (%d).\n", roomNumber);
                break;
        }
        
        // Additional actions that depend on the current room and user input
        switch (roomNumber) {
            case 1:
                if (flashlight) {
                    printf("You turn off the flashlight.\n");
                    flashlight = 0;
                } else {
                    printf("You turn on the flashlight.\n");
                    flashlight = 1;
                }
                scareMessage();
                break;
                
            case 2:
                scareMessage();
                break;
                
            case 3:
                if (!flashlight) {
                    printf("It's too dark to see anything.\n");
                } else {
                    printf("You found a key under the bed!\n");
                    roomNumber = 6; // Go to the "key room"
                }
                scareMessage();
                break;
                
            case 4:
                scareMessage();
                break;
                
            case 5:
                if (flashlight) {
                    printf("You found a light switch and turn it on. There's nothing in the closet.\n");
                } else {
                    printf("You can't see anything in the dark.\n");
                }
                scareMessage();
                break;
                
            default:
                break;
        }
    }
    
    // End of the game
    printf("Congratulations! You escaped the haunted house!\n");
    printf("Thanks for playing.\n");

    return 0;
}