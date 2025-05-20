//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int location;
} Room;

int main() {
    char choice;
    int room_num = 0;

    Room rooms[] = {
        {"Bedroom", 1},
        {"Kitchen", 2},
        {"Living Room", 3},
        {"Bathroom", 4},
        {"Garden", 5}
    };

    while (1) {
        printf("Welcome to the Claude Shannon Adventure Game!\n");
        printf("What room would you like to visit? (1-5)\n");
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("You are in the Bedroom.\n");
            printf("Would you like to:\n");
            printf("1. Go to the Kitchen.\n");
            printf("2. Stay in the Bedroom.\n");
            scanf(" %c", &choice);

            if (choice == '1') {
                room_num = 2;
            } else if (choice == '2') {
                continue;
            } else {
                printf("Invalid choice.\n");
                continue;
            }
        } else if (choice == '2') {
            printf("You are in the Kitchen.\n");
            printf("Would you like to:\n");
            printf("1. Go to the Bedroom.\n");
            printf("2. Go to the Living Room.\n");
            scanf(" %c", &choice);

            if (choice == '1') {
                room_num = 1;
            } else if (choice == '2') {
                room_num = 3;
            } else {
                printf("Invalid choice.\n");
                continue;
            }
        } else if (choice == '3') {
            printf("You are in the Living Room.\n");
            printf("Would you like to:\n");
            printf("1. Go to the Bedroom.\n");
            printf("2. Go to the Bathroom.\n");
            scanf(" %c", &choice);

            if (choice == '1') {
                room_num = 1;
            } else if (choice == '2') {
                room_num = 4;
            } else {
                printf("Invalid choice.\n");
                continue;
            }
        } else if (choice == '4') {
            printf("You are in the Bathroom.\n");
            printf("Would you like to:\n");
            printf("1. Go to the Bedroom.\n");
            printf("2. Go to the Living Room.\n");
            scanf(" %c", &choice);

            if (choice == '1') {
                room_num = 1;
            } else if (choice == '2') {
                room_num = 3;
            } else {
                printf("Invalid choice.\n");
                continue;
            }
        } else if (choice == '5') {
            printf("You are in the Garden.\n");
            printf("Would you like to:\n");
            printf("1. Go to the Bedroom.\n");
            printf("2. Go to the Kitchen.\n");
            scanf(" %c", &choice);

            if (choice == '1') {
                room_num = 1;
            } else if (choice == '2') {
                room_num = 2;
            } else {
                printf("Invalid choice.\n");
                continue;
            }
        } else {
            printf("Invalid choice.\n");
            continue;
        }

        printf("You have chosen Room %d.\n", room_num);
        printf("---------------------\n");

        if (room_num == 1) {
            printf("You are in the Bedroom. The bed is unmade and there is a book lying on the nightstand.\n");
        } else if (room_num == 2) {
            printf("You are in the Kitchen. There is a fridge and a stove in the room. You see a bowl of fruit on the counter.\n");
        } else if (room_num == 3) {
            printf("You are in the Living Room. There is a couch and a coffee table in the room. You see a TV on the wall.\n");
        } else if (room_num == 4) {
            printf("You are in the Bathroom. There is a sink, a toilet, and a shower in the room. You see a towel on the floor.\n");
        } else if (room_num == 5) {
            printf("You are in the Garden. There is a pond and a swing set in the garden. You see a cat sitting on a bench.\n");
        }

        printf("What would you like to do?\n");
        printf("1. Look around.\n");
        printf("2. Pick up an item.\n");
        printf("3. Leave the room.\n");
        printf("4. Exit the game.\n");
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("You look around the room.\n");
        } else if (choice == '2') {
            printf("You pick up an item.\n");
        } else if (choice == '3') {
            printf("You leave the room.\n");
        } else if (choice == '4') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Thanks for playing! See you next time.\n");

    return 0;
}