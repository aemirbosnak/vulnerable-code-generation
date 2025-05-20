//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOMS 5

int main() {
    int i, j;
    char input[20];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will be exploring a spooky house filled with ghosts and strange happenings!\n");
    printf("Press ENTER to continue.\n");
    getchar();

    printf("\nYou stand outside the old, creaky house. Its windows are boarded up and the paint is peeling.\n");
    printf("You take a deep breath and push open the front door.\n");
    getchar();

    // Set up the rooms
    char *room_names[ROOMS] = {"Entryway", "Living Room", "Dining Room", "Kitchen", "Bedroom"};
    char *room_descriptions[ROOMS] = {
        "You are standing in the entryway. The walls are covered in cobwebs and dust.",
        "You have entered the living room. There is an old couch and a rocking chair in the corner. You hear faint whispers.",
        "You have entered the dining room. The table is set as if for a party, but the chairs are empty. The room is silent.",
        "You have entered the kitchen. The knives are out of their holders and the cupboards are open. Something smells rotten.",
        "You have entered the bedroom. The bed is unmade and the sheets are stained. You hear a faint moaning sound."
    };
    int room_map[ROOMS][ROOMS] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    int room_visited[ROOMS] = {1, 0, 0, 0, 0};
    int current_room = 0;

    // Let the game begin!
    printf("\n%s\n", room_descriptions[current_room]);
    while (1) {
        printf("What do you want to do? (type 'help' for a list of commands)\n");
        scanf("%s", input);
        if (strcmp(input, "help") == 0) {
            printf("\nAvailable commands: move, look, quit\n");
        } else if (strcmp(input, "move") == 0) {
            printf("Where do you want to move? (type the name of the room)\n");
            for (i = 0; i < ROOMS; i++) {
                if (room_map[current_room][i] == 1) {
                    printf("- %s\n", room_names[i]);
                }
            }
            scanf("%s", input);
            for (i = 0; i < ROOMS; i++) {
                if (strcmp(input, room_names[i]) == 0 && room_map[current_room][i] == 1) {
                    current_room = i;
                    if (room_visited[i] == 0) {
                        printf("\n%s\n", room_descriptions[i]);
                        room_visited[i] = 1;
                    } else {
                        printf("\nYou have been here before, and nothing has changed.\n");
                    }
                    break;
                }
            }
            if (i == ROOMS) {
                printf("\nInvalid room name. Please try again.\n");
            }
        } else if (strcmp(input, "look") == 0) {
            printf("\n%s\n", room_descriptions[current_room]);
        } else if (strcmp(input, "quit") == 0) {
            printf("\nThanks for playing!\n");
            break;
        } else {
            printf("\nInvalid command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}