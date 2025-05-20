//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // welcome the user
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You have just entered a haunted house and need to find your way out.\n");
    printf("As you navigate the rooms, be on the lookout for ghouls and ghosts!\n\n");
    
    // define the rooms and their properties
    char rooms[6][20] = {"Living Room", "Dining Room", "Kitchen", "Bedroom", "Bathroom", "Basement"};
    int visited[6] = {0, 0, 0, 0, 0, 0};
    int is_ghost[6] = {0, 1, 0, 0, 1, 1};
    int current_room = 0;
    
    // start the game loop
    while (1) {
        // print the current room and its description
        printf("\nYou are in the %s.\n", rooms[current_room]);
        
        if (is_ghost[current_room]) {
            printf("Oh no! There is a ghost in here!\n");
        } else {
            printf("This room appears to be safe.\n");
        }
        
        // mark the room as visited
        visited[current_room] = 1;
        
        // check if the player has won by visiting all the rooms
        int all_visited = 1;
        for (int i = 0; i < 6; i++) {
            if (!visited[i]) {
                all_visited = 0;
            }
        }
        if (all_visited) {
            printf("\nCongratulations! You have made it out of the haunted house!\n");
            break;
        }
        
        // ask the player which room to move to
        int valid_room = 0;
        int room_number;
        while (!valid_room) {
            printf("\nWhich room would you like to move to?\n");
            printf("0: Living Room\n1: Dining Room\n2: Kitchen\n3: Bedroom\n4: Bathroom\n5: Basement\n");
            scanf("%d", &room_number);
            if (room_number < 0 || room_number > 5 || visited[room_number]) {
                printf("Invalid room selection. Please try again.\n");
            } else {
                valid_room = 1;
                current_room = room_number;
            }
        }
        
        // check if the player has encountered a ghost
        if (is_ghost[current_room]) {
            int random_number = rand() % 3;
            if (random_number == 0) {
                printf("\nYou have been scared by the ghost and have lost 2 health points.\n");
            } else {
                printf("\nYou manage to avoid the ghost and move on.\n");
            }
        } else {
            printf("\nYou move on to the next room.\n");
        }
    }
    
    return 0;
}