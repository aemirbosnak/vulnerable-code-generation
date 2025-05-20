//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define ROOMS 5 // number of rooms in the haunted house

int main()
{
    char rooms[ROOMS][30] = {"Foyer", "Kitchen", "Living Room", "Bedroom", "Basement"};
    int current_room = 0; // starting room is the foyer
    int exit_room = 4; // exit room is the basement
    int has_key = 0; // player does not have the key at the beginning
    int moves = 0; // count the number of moves taken by the player

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in the %s.\n", rooms[current_room]);

    while (current_room != exit_room) {
        printf("What do you want to do?\n");
        printf("1. Move to another room.\n2. Search the current room.\n3. Quit.\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Which room do you want to move to?\n");
            for (int i = 0; i < ROOMS; i++) {
                if (i != current_room) {
                    printf("%d. %s\n", i+1, rooms[i]);
                }
            }
            int room_choice;
            scanf("%d", &room_choice);
            if (room_choice >= 1 && room_choice <= ROOMS && room_choice != current_room+1) {
                printf("You move to the %s.\n", rooms[room_choice-1]);
                current_room = room_choice-1;
                moves++;
            } else {
                printf("Invalid choice. Please try again.\n");
            }
        } else if (choice == 2) {
            if (current_room == 3 && !has_key) {
                printf("You found a key!\n");
                has_key = 1;
                moves++;
            } else {
                printf("You search but find nothing.\n");
                moves++;
            }
        } else if (choice == 3) {
            printf("You quit the game.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    if (current_room == exit_room && has_key) {
        printf("Congratulations! You found the exit in %d moves.\n", moves);
    } else {
        printf("Game over. You did not find the exit.\n");
    }

    return 0;
}