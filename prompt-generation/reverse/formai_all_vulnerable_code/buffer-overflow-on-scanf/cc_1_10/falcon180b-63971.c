//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();

int main() {
    int choice;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    intro();

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Play the game\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                game();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void intro() {
    printf("\nYou wake up in a dark room with no memory of how you got there.\n");
    printf("The only thing you have is a flashlight and a piece of paper with a strange message:\n");
    printf("'Find the key to unlock the door and escape before it's too late.'\n");
    printf("\nPress ENTER to begin your adventure...");
    getchar();
}

void game() {
    int choice, room = 1;
    char key[10] = "KEY";

    printf("\nYou are in room %d.\n", room);
    printf("There is a door to your left and a table with a box on it.\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Open the box\n");
        printf("2. Try to pick the lock\n");
        printf("3. Examine the door\n");
        printf("4. Go back\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room == 1) {
                    printf("You open the box and find a note inside:\n");
                    printf("'The key is hidden in the room with the red door.'\n");
                    room = 2;
                } else {
                    printf("The box is empty.\n");
                }
                break;
            case 2:
                if(strcmp(key, "KEY") == 0) {
                    printf("You successfully pick the lock and open the door.\n");
                    printf("Congratulations! You have escaped!\n");
                    exit(0);
                } else {
                    printf("You try to pick the lock but fail.\n");
                }
                break;
            case 3:
                if(room == 1) {
                    printf("The door is locked and requires a key to open.\n");
                } else {
                    printf("The door is locked and requires a key to open.\n");
                    printf("You notice that the door is painted red.\n");
                }
                break;
            case 4:
                room--;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}