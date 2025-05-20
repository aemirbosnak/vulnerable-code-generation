//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int room = 1;
    int choice;
    int ghost = 0;
    int key_found = 0;
    int door_locked = 1;

    srand(time(NULL)); // Initialize the random number generator

    printf("Welcome to the Cyberpunk Haunted House Simulator.\n");
    printf("You find yourself inside a dimly lit room.\n");

    while(room != 0) {
        printf("\n");

        if(room == 1) { // Starting room
            printf("You are in a dimly lit room with a door to the east.\n");

            if(ghost == 1) {
                printf("There is a ghost floating in the corner of the room!\n");
            }

            printf("What would you like to do? \n");
            printf("\t1. Go east \n");
            printf("\t2. Look around the room \n");
            printf("\t3. Quit the game \n");

            scanf("%d", &choice);

            if(choice == 1) {
                if(door_locked == 0) {
                    room = 2; // Move to room 2
                    printf("You unlock the door and enter the next room.\n");
                }
                else {
                    printf("The door is locked.\n");
                }
            }
            else if(choice == 2) {
                printf("You look around the room and find a key hidden in the corner.\n");
                key_found = 1;
            }
            else if(choice == 3) {
                printf("Goodbye.\n");
                room = 0;
            }
            else {
                printf("Invalid choice.\n");
            }

            if(rand() % 2 == 0 && ghost == 0) { // There is a 50/50 chance of a ghost appearing
                ghost = 1;
            }
        }
        else if(room == 2) { // Second room
            printf("You are in a large room with 3 doors, one to the north, one to the west, and one to the east.\n");

            if(ghost == 1) {
                printf("The ghost is floating in front of the door to the east.\n");
            }

            printf("What would you like to do? \n");
            printf("\t1. Go north \n");
            printf("\t2. Go west \n");
            printf("\t3. Go east \n");
            printf("\t4. Look around the room \n");
            printf("\t5. Quit the game \n");

            scanf("%d", &choice);

            if(choice == 1) {
                room = 3; // Move to room 3
                printf("You enter the next room.\n");
            }
            else if(choice == 2) {
                room = 4; // Move to room 4
                printf("You enter the next room.\n");
            }
            else if(choice == 3) {
                if(ghost == 0) {
                    room = 5; // Move to room 5
                    printf("You enter the next room.\n");
                }
                else {
                    printf("The ghost is blocking the door.\n");
                }
            }
            else if(choice == 4) {
                printf("You look around the room and find nothing of interest.\n");
            }
            else if(choice == 5) {
                printf("Goodbye.\n");
                room = 0;
            }
            else {
                printf("Invalid choice.\n");
            }
        }
        else if(room == 3) { // Third room
            printf("You are in a small room with a strange looking machine in the center.\n");

            printf("What would you like to do? \n");
            printf("\t1. Inspect the machine \n");
            printf("\t2. Go back \n");
            printf("\t3. Quit the game \n");

            scanf("%d", &choice);

            if(choice == 1) {
                if(key_found == 1) {
                    printf("You use the key to unlock a hidden compartment on the machine.\n");
                    printf("Inside, you find a powerful cybernetic implant.\n");
                    printf("You gain a special ability!\n");
                }
                else {
                    printf("You inspect the machine but find nothing of interest.\n");
                }
            }
            else if(choice == 2) {
                room = 2; // Move back to room 2
                printf("You go back to the previous room.\n");
            }
            else if(choice == 3) {
                printf("Goodbye.\n");
                room = 0;
            }
            else {
                printf("Invalid choice.\n");
            }
        }
        else if(room == 4) { // Fourth room
            printf("You are in a small room with a window overlooking the city.\n");

            printf("What would you like to do? \n");
            printf("\t1. Look out the window \n");
            printf("\t2. Go back \n");
            printf("\t3. Quit the game \n");

            scanf("%d", &choice);

            if(choice == 1) {
                printf("You look out the window and see a dystopian city filled with neon lights.\n");
            }
            else if(choice == 2) {
                room = 2; // Move back to room 2
                printf("You go back to the previous room.\n");
            }
            else if(choice == 3) {
                printf("Goodbye.\n");
                room = 0;
            }
            else {
                printf("Invalid choice.\n");
            }
        }
        else if(room == 5) { // Fifth room
            printf("You are in a small room with a door to the south.\n");

            if(ghost == 1) {
                printf("The ghost is blocking the door.\n");
            }
            else {
                printf("What would you like to do? \n");
                printf("\t1. Go south \n");
                printf("\t2. Quit the game \n");

                scanf("%d", &choice);

                if(choice == 1) {
                    room = 0; // Escape the house and win the game
                    printf("You open the door and escape the haunted house! Congratulations!\n");
                }
                else if(choice == 2) {
                    printf("Goodbye.\n");
                    room = 0;
                }
                else {
                    printf("Invalid choice.\n");
                }
            }
        }
    }

    return 0;
}