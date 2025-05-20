//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOSTS 5

struct Ghost {
    char name[20];
    int room_num;
    int activity_level;
    int trigger_chance;
};

void main() {
    srand(time(NULL));
    struct Ghost ghosts[NUM_GHOSTS] = {
        {"Sarah", 1, 3, 20},
        {"Jack", 2, 2, 15},
        {"Mary", 3, 4, 12},
        {"Adam", 4, 3, 18},
        {"Emily", 5, 2, 10}
    };

    int current_room = 1;
    char input[20];

    while (1) {
        // Display the current room
        printf("You are in room %d.\n", current_room);

        // Listen for user input
        printf("Enter a command: ");
        scanf("%s", input);

        // Check if the user wants to move to another room
        if (strcmp(input, "move") == 0) {
            // Get the room number the user wants to move to
            printf("Enter the room number you want to go to: ");
            scanf("%d", &current_room);

            // Check if the room number is valid
            if (current_room < 1 || current_room > 5) {
                printf("Invalid room number.\n");
            }
        }

        // Check if the user has triggered a ghost
        for (int i = 0; i < NUM_GHOSTS; i++) {
            if (current_room == ghosts[i].room_num && rand() % ghosts[i].trigger_chance == 0) {
                printf("Suddenly, you hear a noise and feel a cold hand brush against your skin. You are haunted by %s.\n", ghosts[i].name);
            }
        }

        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    return;
}