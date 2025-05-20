//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the random number generator
    srand(time(NULL));

    // Room description and item assignments
    char* rooms[] = {"Entrance", "Living Room", "Kitchen", "Dining Room", "Bedroom", "Bathroom", "Basement"};
    char* items[] = {"Ghost", "Skeleton", "Candlestick", "Book", "Knife", "Rope", "Poison"};

    // Initializing room and item indexes
    int room_index = 0;
    int item_index = 0;

    // Starting the simulation
    printf("Welcome to the Haunted House Simulator!\n");
    while (1) {
        printf("You are in the %s. ", rooms[room_index]);

        // Checking if there is an item in the room and selecting a random item if there is
        if (rand() % 2 == 1) {
            item_index = rand() % 7;
            printf("You see a %s in the room. ", items[item_index]);
        }

        // Checking if the player has found all the items
        if (item_index == 6) {
            printf("You have found all the items! Congratulations, you have escaped the haunted house!\n");
            break;
        }

        // Generating a random number between 0 and 3 for the player's next move
        int direction = rand() % 4;
        switch(direction) {
            case 0:
                printf("You move North.\n");
                if (room_index == 0) {
                    printf("You are at a dead end. You cannot go North.\n");
                }
                else {
                    room_index--;
                }
                break;
            case 1:
                printf("You move South.\n");
                if (room_index == 6) {
                    printf("You are at a dead end. You cannot go South.\n");
                }
                else {
                    room_index++;
                }
                break;
            case 2:
                printf("You move East.\n");
                if (room_index == 3 || room_index == 5) {
                    printf("You are at a dead end. You cannot go East.\n");
                }
                else {
                    room_index += 2;
                }
                break;
            case 3:
                printf("You move West.\n");
                if (room_index == 0 || room_index == 2 || room_index == 4) {
                    printf("You are at a dead end. You cannot go West.\n");
                }
                else {
                    room_index -= 2;
                }
                break;
            default:
                break;
        }
    }

    // End of the program
    return 0;
}