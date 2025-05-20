//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int health;
    int attack_power;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 100, 20},
    {"Mrs. Smith", 2, 80, 15},
    {"Mr. Brown", 3, 60, 10},
    {"Ms. White", 4, 40, 5},
    {"Mr. Green", 5, 20, 2}
};

int main() {
    int i, j, ghost_num, room_num;
    char command;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game
    ghost_num = 0;
    room_num = 1;

    // Loop until the player exits the game
    while (1) {
        // Display the current room
        printf("You are in room %d.\n", room_num);

        // List the ghosts in the current room
        for (i = 0; i < MAX_GHOSTS; i++) {
            if (ghosts[i].room == room_num) {
                printf("Ghost: %s (%d health).\n", ghosts[i].name, ghosts[i].health);
            }
        }

        // Get the player's command
        printf("Enter a command (move, attack, flee): ");
        scanf("%c", &command);

        // Process the player's command
        switch (command) {
            case 'm':
                // Move to a new room
                room_num = rand() % MAX_GHOSTS + 1;
                break;
            case 'a':
                // Attack a ghost
                for (i = 0; i < MAX_GHOSTS; i++) {
                    if (ghosts[i].room == room_num) {
                        ghosts[i].health -= 10;
                        if (ghosts[i].health <= 0) {
                            printf("Ghost: %s has been defeated.\n", ghosts[i].name);
                            ghost_num--;
                        } else {
                            printf("Ghost: %s has been damaged.\n", ghosts[i].name);
                        }
                    }
                }
                break;
            case 'f':
                // Flee from the current room
                room_num = rand() % MAX_GHOSTS + 1;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Check if the player has won or lost
        if (ghost_num == 0) {
            printf("You have won! You have escaped the haunted house.\n");
            break;
        } else if (room_num == MAX_GHOSTS) {
            printf("You have lost! You have been trapped in the haunted house.\n");
            break;
        }
    }

    return 0;
}