//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void room_one();
void room_two();
void room_three();
void room_four();

int main() {
    int current_room = 1;

    // game loop
    while (current_room <= 4) {
        switch (current_room) {
            case 1:
                room_one();
                break;

            case 2:
                room_two();
                break;

            case 3:
                room_three();
                break;

            case 4:
                room_four();
                break;
        }

        current_room++;
    }

    printf("Congratulations! You have completed the adventure game.\n");

    return 0;
}

// First Room
void room_one() {
    char name[20];

    printf("Welcome to room one. Please enter your name: ");
    scanf("%s", name);

    printf("\nWelcome, %s! You have entered a room with a door to the north.\n", name);

    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Approach the door\n");
        printf("2. Look around the room\n");
        printf("3. Quit game\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou go to the door and find that it is locked. You need to find a key.\n");
                break;

            case 2:
                printf("\nYou look around the room and see a table with a drawer.\n");
                break;

            case 3:
                printf("\nGoodbye. Thanks for playing!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while (choice != 1);

    printf("\nYou open the drawer and find a key. You can now unlock the door and proceed to the next room.\n");
}

// Second Room
void room_two() {
    printf("Welcome to room two. You have entered a room with two doors, one to the north and one to the west.\n");

    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Go through the door to the north\n");
        printf("2. Go through the door to the west\n");
        printf("3. Look around the room\n");
        printf("4. Quit game\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou go through the door to the north and find yourself in a new room.\n");
                break;

            case 2:
                printf("\nYou go through the door to the west and find yourself back in the first room.\n");
                break;

            case 3:
                printf("\nYou look around the room and see nothing of interest.\n");
                break;

            case 4:
                printf("\nGoodbye. Thanks for playing!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 1);
}

// Third Room
void room_three() {
    printf("Welcome to room three. You have entered a room with a chest at the center.\n");

    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Open the chest\n");
        printf("2. Look around the room\n");
        printf("3. Quit game\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou open the chest and find a map. The map shows you the way to the next room.\n");
                break;

            case 2:
                printf("\nYou look around the room and see a painting on the wall.\n");
                break;

            case 3:
                printf("\nGoodbye. Thanks for playing!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while (choice != 1);
}

// Fourth Room
void room_four() {
    printf("Welcome to room four. You have entered a room with a final door to the north.\n");

    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Go through the final door\n");
        printf("2. Look around the room\n");
        printf("3. Quit game\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCongratulations, you have completed the adventure game!\n");
                break;

            case 2:
                printf("\nYou look around the room and notice a window. You can climb out of it if you need to escape.\n");
                break;

            case 3:
                printf("\nGoodbye. Thanks for playing!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while (choice != 1);
}