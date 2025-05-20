//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

void display_intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing at the entrance of a spooky old house.\n");
    printf("Will you dare to step inside?\n");
    printf("Good luck!\n\n");
}

void display_room(int room) {
    switch (room) {
        case 0:
            printf("You are in the living room. It's dark and dusty.\n");
            printf("You can go to the kitchen or upstairs.\n");
            break;
        case 1:
            printf("You are in the kitchen. You smell something rotten.\n");
            printf("You can go back to the living room or into the cellar.\n");
            break;
        case 2:
            printf("You are upstairs. You see a flickering light down the hallway.\n");
            printf("You can go back down or investigate the light.\n");
            break;
        case 3:
            printf("You are in the cellar. It's cold and filled with strange sounds.\n");
            printf("You can go back to the kitchen or try to open a mysterious door.\n");
            break;
        case 4:
            printf("You have entered a room filled with ghosts!\n");
            printf("Choose wisely to escape!\n");
            break;
        default:
            printf("You have exited the house. Goodbye!\n");
            break;
    }
}

int next_room(int current_room) {
    int choice;
    printf("Enter your choice (1: move, 2: quit): ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        return -1; // Quit game
    }

    switch (current_room) {
        case 0:
            printf("Where do you want to go? (1: kitchen, 2: upstairs): ");
            scanf("%d", &choice);
            return (choice == 1) ? 1 : 2;
        case 1:
            printf("Where do you want to go? (1: living room, 2: cellar): ");
            scanf("%d", &choice);
            return (choice == 1) ? 0 : 3;
        case 2:
            printf("Where do you want to go? (1: back down, 2: investigate flicker): ");
            scanf("%d", &choice);
            return (choice == 1) ? 0 : 4;
        case 3:
            printf("Where do you want to go? (1: kitchen, 2: open door): ");
            scanf("%d", &choice);
            return (choice == 1) ? 1 : 4;
        case 4:
            return -1; // End game if ghosts encountered
        default:
            return -1; // End game
    }
}

void special_event() {
    int event_result = rand() % 3;
    if (event_result == 0) {
        printf("You've been caught by a ghost! You must escape!\n");
    } else if (event_result == 1) {
        printf("You found a hidden treasure! You are safe!\n");
    } else {
        printf("A creepy sound echoes around you, but nothing happens...\n");
    }
}

int main() {
    int current_room = 0;
    int exit_game = 0;

    srand(time(NULL)); // Initialize random seed
    display_intro();

    while (!exit_game) {
        display_room(current_room);
        exit_game = next_room(current_room);
        
        if (current_room == 4) {
            special_event();
            exit_game = 1; // End the game after special event
        } else if (exit_game == -1) {
            printf("Exiting the haunted house. Thank you for playing!\n");
            break;
        }

        current_room = exit_game;
    }

    return 0;
}