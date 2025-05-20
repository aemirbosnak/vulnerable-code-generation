//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_GHOSTS 5
#define MAX_MESSAGES 3

const char* rooms[MAX_ROOMS] = {"Kitchen", "Living Room", "Dining Room", "Bedroom", "Basement"};

const char* ghostNames[MAX_GHOSTS] = {"Ghost of Helen", "Ghost of John", "Ghost of Catherine", "Ghost of Robert", "Ghost of Elizabeth"};

const char* messages[MAX_MESSAGES] = {"You hear a faint whisper.", "You feel a cold breeze.", "You smell a rotten stench."};

int main() {
    srand(time(NULL)); // Set up random number generator seed
    
    int currentRoom = 0; // Starting room
    int hasKey = 0; // Player does not have key at start
    int numGhosts = 0; // No ghosts present at start
    
    printf("*** Welcome to the Haunted House Simulator! ***\n\n");
    printf("You find yourself standing in the foyer of an old, abandoned house.\n");
    printf("The air is thick with dust and cobwebs hang from the ceiling.\n\n");
    
    // Game loop
    while (1) {
        // Print current room
        printf("\nYou are currently in the %s.\n", rooms[currentRoom]);
        
        // Random event
        int event = rand() % 3;
        if (event == 0) {
            printf("%s\n", messages[rand() % MAX_MESSAGES]);
        } else if (event == 1 && numGhosts < MAX_GHOSTS) {
            int ghostIndex = rand() % MAX_GHOSTS;
            printf("You encounter the %s!\n", ghostNames[ghostIndex]);
            numGhosts++;
        }
        
        // Player input
        printf("\nWhat do you want to do?\n");
        printf("1. Move to another room\n");
        if (currentRoom == 1 && !hasKey) {
            printf("2. Search the living room\n");
        }
        if (numGhosts > 0 && event != 1) {
            printf("3. Run!\n");
        }
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        // Handle player choice
        switch(choice) {
            case 1:
                printf("\nWhere do you want to go?\n");
                for (int i = 0; i < MAX_ROOMS; i++) {
                    if (i != currentRoom) {
                        printf("%d. %s\n", i+1, rooms[i]);
                    }
                }
                printf("Enter your choice: ");
                
                int roomChoice;
                scanf("%d", &roomChoice);
                
                if (roomChoice < 1 || roomChoice > MAX_ROOMS || roomChoice == currentRoom+1) {
                    printf("Invalid choice. You stay in the %s.\n", rooms[currentRoom]);
                } else {
                    printf("You move to the %s.\n", rooms[roomChoice-1]);
                    currentRoom = roomChoice-1;
                }
                
                break;
            case 2:
                if (currentRoom == 1 && !hasKey) {
                    printf("You search the living room and find a key!\n");
                    hasKey = 1;
                } else {
                    printf("There's nothing to search here.\n");
                }
                break;
            case 3:
                if (numGhosts > 0 && event != 1) {
                    printf("You run away from the ghosts and end up back in the foyer.\n");
                    currentRoom = 0;
                    numGhosts = 0;
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        
        // Check win condition
        if (currentRoom == 0 && hasKey && numGhosts == 0) {
            printf("\n*** Congratulations, you escaped the haunted house! ***\n");
            break;
        }
    }
    
    printf("\nThanks for playing!\n");
    
    return 0; // End program
}