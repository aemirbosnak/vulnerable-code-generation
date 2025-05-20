//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    // initialize variables
    int room_number = 1;
    int choice;
    int ghost_encounter = 0;
    int clock = 0;
    
    while (room_number <= 10) {
        printf("\nYou are currently in room %d of the haunted house.\n", room_number);
        printf("What would you like to do?\n");
        printf("1. Search the room\n");
        printf("2. Move to the next room\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            // generate random events
            srand(time(NULL) + clock);
            int event = rand() % 3;
            
            if (event == 0) {
                printf("\nYou found a creepy doll in the corner of the room...\n");
                printf("Suddenly, you hear a strange noise coming from the hallway!\n");
                printf("You quickly move on to the next room.\n");
            } else if (event == 1) {
                printf("\nYou found an old key in the room!\n");
                printf("As you turn around to leave, you feel a cold gust of wind on the back of your neck...\n");
                printf("You quickly move on to the next room.\n");
            } else {
                printf("\nYou found an old book in the room...\n");
                printf("As you read through the pages, you start to hear whispers in your ear...\n");
                printf("You quickly move on to the next room.\n");
            }
        
        } else {
            // increase room number and time
            room_number += 1;
            clock += 1;
            
            // generate ghost encounter
            srand(time(NULL) + clock);
            int ghost_prob = rand() % 3;
            
            if (ghost_prob == 0) {
                printf("\nAs you move to the next room, you suddenly feel a cold chill run down your spine...\n");
                printf("You turn around and see a ghostly figure looming behind you!\n");
                printf("You scream and run out of the haunted house!\n");
                ghost_encounter = 1;
                break;
            } else {
                printf("\nYou move to the next room...\n");
            }
        }
    }
    
    if (ghost_encounter == 0) {
        printf("\nCongratulations! You made it through the haunted house without encountering any ghosts!\n");
    } else {
        printf("\nGame over! You encountered a ghost and ran out of the haunted house!\n");
    }
    
    return 0;
}