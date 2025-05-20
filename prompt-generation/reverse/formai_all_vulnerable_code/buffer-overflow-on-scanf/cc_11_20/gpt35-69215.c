//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int room[4] = { 0 };  // Array that holds 4 rooms, with 0 indicating unvisited and 1 indicating visited
    int current_room = 1;  // Starting room
    
    printf("Welcome to the Haunted House Simulator.\n");
    printf("You are currently in Room 1.\n");
    
    srand(time(NULL));  // Seed the random number generator
    
    while (1) {
        int doors[2] = { 0 };  // Array that holds which doors are available to the player
        
        // Determine which doors are available based on the current room
        if (current_room == 1) {
            doors[0] = 2;
            doors[1] = 3;
        } else if (current_room == 2) {
            doors[0] = 1;
            doors[1] = 4;
        } else if (current_room == 3) {
            doors[0] = 1;
            doors[1] = 4;
        } else if (current_room == 4) {
            doors[0] = 2;
            doors[1] = 3;
        }
        
        // Print available doors to the player
        printf("Available doors: ");
        if (room[doors[0]-1] == 0) {
            printf("%d ", doors[0]);
        }
        if (room[doors[1]-1] == 0) {
            printf("%d ", doors[1]);
        }
        printf("\n");
        
        // Get the player's chosen door
        int chosen_door = 0;
        while (chosen_door != doors[0] && chosen_door != doors[1]) {
            printf("Which door do you choose? ");
            scanf("%d", &chosen_door);
            if (chosen_door != doors[0] && chosen_door != doors[1]) {
                printf("Invalid choice. Please choose a door that is available.\n");
            }
        }
        
        // Move the player to the chosen room and mark it as visited
        current_room = chosen_door;
        room[current_room-1] = 1;
        
        // Determine whether the player has visited all rooms
        int visited_rooms = 0;
        for (int i = 0; i < 4; i++) {
            if (room[i] == 1) {
                visited_rooms++;
            }
        }
        if (visited_rooms == 4) {
            printf("Congratulations! You have visited all the rooms and successfully escaped the haunted house!\n");
            break;
        }
        
        // Determine whether the player encounters a ghost
        int ghost_encounter = rand() % 5;
        if (ghost_encounter == 0) {
            printf("Oh no! You have encountered a ghost in Room %d!\n", current_room);
            printf("GAME OVER\n");
            break;
        }
    }
    
    return 0;
}