//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void display_room(char* room_name);
void move_to_next_room(char* room_name);
void pick_up_item(char* item_name);

int main() {
    // Initialize room variables
    char current_room[50];
    char next_room[50];
    char item_picked[50];

    // Initialize current room and next room with default values
    strcpy(current_room, "You are in the living room");
    strcpy(next_room, "You are in the bedroom");

    // Welcome message
    printf("Welcome to the adventure game! You are in the living room.\n");

    // Loop until user wants to exit
    while (1) {
        // Display current room
        printf("Current room: %s\n", current_room);

        // Get user input for action
        printf("What do you want to do? 1. Move to next room 2. Pick up item 3. Quit\n");
        int action = scanf("%d", &action);

        // Process user input
        if (action == 1) {
            // Move to next room
            strcpy(current_room, next_room);
            strcpy(next_room, "You are in the kitchen");
        } else if (action == 2) {
            // Pick up item
            printf("What item do you want to pick up? 1. Book 2. Key\n");
            int item_index = scanf("%d", &item_index);
            strcpy(item_picked, "You picked up the ");
            switch (item_index) {
                case 1:
                    strcat(item_picked, "book");
                    break;
                case 2:
                    strcat(item_picked, "key");
                    break;
                default:
                    printf("Invalid item index\n");
            }
            printf("You picked up the %s.\n", item_picked);
        } else if (action == 3) {
            // Exit game
            printf("Exiting game...\n");
            break;
        } else {
            // Invalid input
            printf("Invalid input\n");
        }
    }

    // Display final room
    printf("Final room: %s\n", current_room);

    // Free memory
    free(current_room);
    free(next_room);
    free(item_picked);

    return 0;
}