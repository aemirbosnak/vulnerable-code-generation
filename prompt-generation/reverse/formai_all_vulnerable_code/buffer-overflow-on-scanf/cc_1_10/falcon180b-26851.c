//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int rooms = 10;
    int current_room = 0;
    int ghosts_encountered = 0;
    int treasure_found = 0;
    int turns = 0;
    int ghost_room;
    int treasure_room;
    int door_open = 0;
    char door_state;
    srand(time(0)); //initialize random seed

    printf("Welcome to the Haunted House!\n");
    printf("You have %d turns to find the treasure and escape.\n", turns);
    printf("Choose your first move:\n");
    printf("1. Go forward\n");
    printf("2. Go back\n");
    scanf("%d", &choice);

    while(turns > 0 &&!treasure_found) {
        switch(choice) {
            case 1:
                if(current_room < rooms-1) {
                    current_room++;
                    if(current_room == ghost_room) {
                        ghosts_encountered++;
                    } else if(current_room == treasure_room) {
                        treasure_found = 1;
                    }
                } else {
                    printf("You reached the end of the house.\n");
                }
                break;
            case 2:
                if(current_room > 0) {
                    current_room--;
                } else {
                    printf("You can't go back any further.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
        turns--;
    }

    if(treasure_found) {
        printf("Congratulations! You found the treasure and escaped the haunted house!\n");
    } else {
        printf("Sorry, you ran out of turns and didn't find the treasure.\n");
    }

    return 0;
}