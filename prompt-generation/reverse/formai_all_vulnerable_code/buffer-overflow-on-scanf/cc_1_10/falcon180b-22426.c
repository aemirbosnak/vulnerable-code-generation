//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define GHOST_ROOM 4

// Function to generate random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display the current room
void display_room(int room_num) {
    printf("You are in room %d.\n", room_num);
}

// Function to move the player to a new room
void move_player(int *current_room) {
    int new_room = rand_range(0, ROOMS - 1);

    if (new_room == GHOST_ROOM) {
        printf("You have encountered a ghost! Game over.\n");
        exit(1);
    }

    *current_room = new_room;
    printf("You have moved to room %d.\n", *current_room);
}

// Function to check if the player has won the game
int check_win(int current_room) {
    if (current_room == ROOMS - 1) {
        printf("Congratulations! You have escaped the haunted house.\n");
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int current_room = 0;

    while (1) {
        display_room(current_room);

        int choice;
        printf("What do you want to do?\n");
        printf("1. Move to a new room\n");
        printf("2. Check your inventory\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            move_player(&current_room);
            break;

        case 2:
            printf("You don't have any inventory items yet.\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice.\n");
        }

        if (check_win(current_room)) {
            return 0;
        }
    }

    return 0;
}