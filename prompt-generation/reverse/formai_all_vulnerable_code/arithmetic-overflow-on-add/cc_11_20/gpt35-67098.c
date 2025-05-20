//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to delay program execution for a certain amount of time */
void delay(int seconds) {
    clock_t end_time;
    end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time);
}

int main() {
    int room_number = 1; /* Start in the first room */
    int flashlight_on = 0; /* Flashlight is off by default */
    int ghost_number = 0; /* Number of ghosts encountered */
    srand(time(NULL)); /* Seed random number generator */

    /* Print welcome message */
    printf("Welcome to the Haunted House Simulator!\n\n");

    /* Enter game loop */
    while (room_number >= 1 && room_number <= 10) {
        printf("You are in room %d.\n", room_number);

        /* If the flashlight is on, the player can see the ghosts */
        if (flashlight_on) {
            ghost_number = rand() % 2; /* Random number between 0 and 1 */
            if (ghost_number == 0) {
                printf("You see a ghost! Spooky...\n");
            } else {
                printf("You see two ghosts! Double spooky...\n");
            }
        }

        /* Room descriptions */
        switch (room_number) {
            case 1:
                printf("You are in the foyer. There is a staircase going up and a hallway going to the right.\n");
                break;
            case 2:
                printf("You are in the hallway. There are doors on either side.\n");
                break;
            case 3:
                printf("You are in the bathroom. The tiles are cracked and the mirror is shattered.\n");
                break;
            case 4:
                printf("You are in the master bedroom. The bed is unmade and a closet is open.\n");
                break;
            case 5:
                printf("You are in the kids bedroom. Toys are scattered everywhere and the sheets are stained.\n");
                break;
            case 6:
                printf("You are in the study. A desk is cluttered with papers and books.\n");
                break;
            case 7:
                printf("You are in the kitchen. There are dirty dishes in the sink and expired food in the fridge.\n");
                break;
            case 8:
                printf("You are in the dining room. A table is set for a meal, but the chairs are knocked over.\n");
                break;
            case 9:
                printf("You are in the living room. The TV is on but there is no one in sight.\n");
                break;
            case 10:
                printf("You are in the basement. It's dark and musty.\n");
                break;
        }

        /* Prompt player for action */
        printf("What do you want to do?\n");
        printf("1. Go forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Turn around\n");
        printf("5. Toggle flashlight on/off\n");
        printf("6. Quit\n");

        /* Take player input */
        int choice;
        scanf("%d", &choice);

        /* Handle player actions */
        switch (choice) {
            case 1:
                /* Move forward to the next room */
                printf("You move forward.\n");
                room_number++;
                break;
            case 2:
                /* Turn left */
                printf("You turn left.\n");
                break;
            case 3:
                /* Turn right */
                printf("You turn right.\n");
                break;
            case 4:
                /* Turn around */
                printf("You turn around.\n");
                break;
            case 5:
                /* Toggle flashlight on/off */
                if (flashlight_on) {
                    printf("You turn off the flashlight.\n");
                    flashlight_on = 0;
                } else {
                    printf("You turn on the flashlight.\n");
                    flashlight_on = 1;
                }
                break;
            case 6:
                /* Quit game */
                printf("You quit the game. Thanks for playing!\n");
                return 0;
            default:
                /* Handle invalid input */
                printf("Invalid input. Please try again.\n");
                break;
        }

        /* Delay program execution for suspense */
        delay(1);
    }

    /* End of game */
    printf("You made it out of the haunted house! Congratulations!\n");
    return 0;
}