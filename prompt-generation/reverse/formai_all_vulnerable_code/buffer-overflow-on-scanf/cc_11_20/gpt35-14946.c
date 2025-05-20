//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    
    // Variables to keep track of player's progress
    bool hasKey = false;
    bool hasFlashlight = false;
    bool hasEscaped = false;
    
    // Variables to keep track of player's location
    int currentRoom = 0;
    int nextRoom = 0;
    
    // Map of the haunted house
    int map[8][8] = {
        {7, 4, 2, 6, 6, 3, 0, 0},
        {3, 2, 5, 5, 4, 7, 0, 0},
        {5, 1, 7, 1, 6, 2, 0, 0},
        {7, 7, 4, 5, 3, 5, 0, 0},
        {4, 5, 6, 3, 7, 1, 0, 0},
        {3, 7, 2, 6, 5, 4, 0, 0},
        {2, 4, 1, 7, 1, 3, 0, 0},
        {6, 3, 7, 2, 4, 5, 0, 0}
    };
    
    printf("Welcome to the haunted house simulator!\n");
    
    while (!hasEscaped) {
        printf("You are in room %d.\n", currentRoom);
        
        // Generate random events based on the current room
        switch (currentRoom) {
            case 0:
                printf("This room is empty.\n");
                break;
            case 1:
                printf("You found a key!\n");
                hasKey = true;
                break;
            case 2:
                printf("It's pitch black in here.\n");
                if (!hasFlashlight) {
                    printf("You can't see a thing!\n");
                } else {
                    printf("You turn on your flashlight and see a passage.\n");
                }
                break;
            case 3:
                printf("There's a monster in this room!\n");
                if (hasKey) {
                    printf("You use the key to unlock a secret exit and escape!\n");
                    hasEscaped = true;
                } else {
                    printf("You don't have the key to escape!\n");
                }
                break;
            case 4:
                printf("This room is cold and damp.\n");
                break;
            case 5:
                printf("You found a flashlight!\n");
                hasFlashlight = true;
                break;
            case 6:
                printf("You hear strange noises coming from the walls.\n");
                break;
            case 7:
                printf("This room is covered in cobwebs.\n");
                break;
        }
        
        // Get user input
        printf("Where do you want to go next? (0-7) ");
        scanf("%d", &nextRoom);
        
        // Check if the next room is adjacent to the current room
        bool isValidMove = false;
        for (int i = 0; i < 8; i++) {
            if (map[currentRoom][i] == nextRoom) {
                isValidMove = true;
                break;
            }
        }
        
        if (!isValidMove) {
            printf("You can't get there from here!\n");
        } else {
            currentRoom = nextRoom;
        }
    }
    
    printf("Congratulations, you escaped the haunted house!\n");
    
    return 0;
}