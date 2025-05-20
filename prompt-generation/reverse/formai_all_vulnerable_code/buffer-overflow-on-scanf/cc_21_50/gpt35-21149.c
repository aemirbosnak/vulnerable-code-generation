//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int room = 1; // Starting room
    char choice; // User's choice
    printf("You have entered a haunted house...\n");
    sleep(2); // Wait 2 seconds
    while (1) { // Loop until user exits
        switch (room) {
            case 1: // Entrance
                printf("You are standing in the entrance of the haunted house.\n");
                printf("There is a door to your left, a door to your right, and a staircase leading up.\n");
                printf("Which way would you like to go? (L/R/U/X)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'L') {
                    room = 2; // Go left
                } else if (choice == 'R') {
                    room = 3; // Go right
                } else if (choice == 'U') {
                    room = 4; // Go up
                } else if (choice == 'X') {
                    printf("You have exited the haunted house.\n");
                    return 0; // Exit program
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 2: // Left room
                printf("You have entered the left room.\n");
                printf("There is a chair in the middle of the room, facing away from you.\n");
                printf("What would you like to do? (S/T/U)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'S') {
                    printf("You approach the chair and try to move it, but it won't budge.\n");
                } else if (choice == 'T') {
                    printf("You tap the chair lightly, but there is no response.\n");
                } else if (choice == 'U') {
                    printf("You walk to the other side of the room, but there is nothing there.\n");
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 3: // Right room
                printf("You have entered the right room.\n");
                printf("There is a table in the center of the room, covered with a red cloth.\n");
                printf("What would you like to do? (L/O/U)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'L') {
                    printf("You lift the cloth and find a key underneath.\n");
                } else if (choice == 'O') {
                    printf("You try to open the drawers of the table, but they are locked.\n");
                } else if (choice == 'U') {
                    printf("You look up, but there is nothing interesting on the ceiling.\n");
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 4: // Upstairs
                printf("You have reached the upstairs landing.\n");
                printf("There are three doors: one to the left, one to the right, and one straight ahead.\n");
                printf("Which door would you like to enter? (L/R/S)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'L') {
                    room = 5; // Go left
                } else if (choice == 'R') {
                    room = 6; // Go right
                } else if (choice == 'S') {
                    room = 7; // Go straight
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 5: // Left upstairs room
                printf("You have entered the left upstairs room.\n");
                printf("There is a book on the desk, open to a page entitled 'Haunted House Trivia'.\n");
                sleep(2); // Wait 2 seconds
                printf("\nHaunted House Trivia:\n");
                printf("What is the capital of Transylvania?\n");
                printf("A) Dracula\n");
                printf("B) Bucharest\n");
                printf("C) Frankenstein\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'B') {
                    printf("Correct!\n");
                } else {
                    printf("Wrong answer. You have been cursed.\n");
                }
                break;
            case 6: // Right upstairs room
                printf("You have entered the right upstairs room.\n");
                printf("There is a bed in the middle of the room with a skeleton lying in it.\n");
                printf("What would you like to do? (T/L/U)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'T') {
                    printf("You try to touch the skeleton, but it crumbles to dust.\n");
                } else if (choice == 'L') {
                    printf("You lift up the pillow and find a piece of paper with a code on it: 666.\n");
                } else if (choice == 'U') {
                    printf("You look up, but there is nothing interesting on the ceiling.\n");
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 7: // Straight upstairs room
                printf("You have entered the straight upstairs room.\n");
                printf("The room is empty except for a large mirror against the wall.\n");
                printf("What would you like to do? (L/S/U)\n");
                scanf(" %c", &choice); // Get user's choice
                if (choice == 'L') {
                    printf("You look into the mirror and see a ghostly figure standing behind you.\n");
                } else if (choice == 'S') {
                    printf("You cautiously approach the mirror and touch it, but nothing happens.\n");
                } else if (choice == 'U') {
                    printf("You look up, but there is nothing interesting on the ceiling.\n");
                } else {
                    printf("Invalid input.\n");
                }
                break;
            default:
                printf("Invalid room.\n");
                break;
        }
    }
    return 0;
}