//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* function prototypes */
void print_boundary();
void print_intro();
void print_ghost();
void print_end();

int main() {
    char name[20];
    int choice, room_num = 1;
    int has_key = 0, has_flashlight = 0;
    int locked_room_num = rand() % 5 + 1;
    char answer;

    /* set random seed */
    srand(time(NULL));

    /* print intro */
    print_intro();

    /* get player name */
    printf("What's your name? ");
    fgets(name, 20, stdin);

    /* game loop */
    while (room_num <= 5) {
        printf("\n\nYou are in room %d.\n\n", room_num);

        /* print ghost in second room */
        if (room_num == 2) {
            print_ghost();
        }

        /* print locked door in random room */
        if (room_num == locked_room_num && !has_key) {
            printf("The door is locked. You need a key to open it.\n");
        }
        else {
            printf("There is a door to the next room.\n");
        }

        /* print flashlight in first room */
        if (room_num == 1 && !has_flashlight) {
            printf("There is a flashlight on the ground.\n");
        }

        /* get player choice */
        printf("What do you want to do?\n");
        printf("1. Go to the next room.\n");
        printf("2. Look for items.\n");
        printf("3. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        /* handle player choice */
        switch (choice) {
            case 1:
                /* move to next room */
                if (room_num == locked_room_num && !has_key) {
                    printf("The door is locked. You need a key to open it.\n");
                }
                else {
                    printf("You go to the next room.\n");
                    room_num++;
                }
                break;
            case 2:
                /* search for items */
                if (room_num == 1 && !has_flashlight) {
                    printf("You pick up the flashlight.\n");
                    has_flashlight = 1;
                }
                else if (room_num == locked_room_num && !has_key) {
                    printf("You found a key!\n");
                    has_key = 1;
                }
                else {
                    printf("You didn't find anything.\n");
                }
                break;
            case 3:
                /* quit game */
                printf("Are you sure you want to quit? (y/n) ");
                scanf(" %c", &answer);
                if (tolower(answer) == 'y') {
                    printf("Thanks for playing, %s!\n", name);
                    return 0;
                }
                break;
            default:
                /* invalid input */
                printf("Invalid input. Please try again.\n");
        }
    }

    /* player reached the end */
    print_end();
    printf("Congratulations, %s! You made it out alive!\n", name);

    return 0;
}

/* function definitions */

void print_boundary() {
    printf("==============================================\n");
}

void print_intro() {
    print_boundary();
    printf("Welcome to the Haunted House Simulator!\n");
    print_boundary();
    printf("You find yourself trapped in a haunted house.\n");
    printf("Find your way out before it's too late!\n");
}

void print_ghost() {
    printf("You see a ghost standing in front of you!\n");
    printf("It vanishes as soon as you blink...\n");
}

void print_end() {
    print_boundary();
    printf("Congratulations, you made it to the END!\n");
    print_boundary();
    printf("          |         |         |\n");
    printf("        _/ \\_     _/ \\_     _/ \\_\n");
    printf("       |     |   |     |   |     |\n");
    printf("        \\_   _/     \\_   _/     \\_\n");
    printf("          | |         | |         |\n");
    printf("          | |         | |         |\n");
    printf("          | |         | |         |\n");
    printf("          | |         | |         |\n");
    printf("       ___| |_     ___| |_     ___| |_\n");
    printf("      /  _|   \\   /  _|   \\   /  _|  \\\n");
    printf("     / /      /  / /      /  / /    |\\\n");
    printf("    /_/      /_/ /_/      /_/ /_/\\_| \\\n");
    printf("                                \\____/\n");
    print_boundary();
}