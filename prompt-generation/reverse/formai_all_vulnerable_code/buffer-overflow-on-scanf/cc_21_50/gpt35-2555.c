//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
// Haunted House Simulator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");

    // Initialize variables
    char name[20], choice[10];
    int room = 1, random_room, has_key = 0;

    // Get user's name
    printf("What is your name? ");
    scanf("%s", name);

    // Begin game loop
    while (1) {
        printf("\n\nYou are currently in room %d of the haunted house.\n", room);

        // Randomly generate next room
        srand(time(NULL));
        random_room = (rand() % 5) + 1;

        // Give user options based on the room they are in
        if (room == 1) {
            printf("You see a dusty old key on the table and a door to the east.\n");
            printf("What would you like to do? (take key/east/west) ");
            scanf("%s", choice);

            if (strncmp(choice, "take", 4) == 0 && has_key == 0) {
                printf("You take the key.\n");
                has_key = 1;
            } else if (strncmp(choice, "east", 4) == 0) {
                if (has_key == 1) {
                    printf("You use the key to unlock the door and go through it.\n");
                    room = random_room;
                } else {
                    printf("The door is locked. You need a key to open it.\n");
                }
            } else if (strncmp(choice, "west", 4) == 0) {
                printf("You go back west.\n");
                room = 5;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else if (room == 2) {
            printf("You see a ghostly figure floating in the center of the room and a door to the south.\n");
            printf("What would you like to do? (north/south) ");
            scanf("%s", choice);

            if (strncmp(choice, "south", 5) == 0) {
                printf("You go through the door to the south.\n");
                room = random_room;
            } else if (strncmp(choice, "north", 5) == 0) {
                printf("You can't go that way. The ghostly figure blocks your path.\n");
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else if (room == 3) {
            printf("You see a dark, creepy hallway stretching out ahead of you. You hear strange noises coming from the other end.\n");
            printf("What would you like to do? (north/south) ");
            scanf("%s", choice);

            if (strncmp(choice, "north", 5) == 0) {
                printf("You cautiously make your way down the hallway.\n");
                room = random_room;
            } else if (strncmp(choice, "south", 5) == 0) {
                printf("You go back to the previous room.\n");
                room = 1;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else if (room == 4) {
            printf("You see a small room filled with cobwebs and spiderwebs. There is a door to the north.\n");
            printf("What would you like to do? (take/leave/north) ");
            scanf("%s", choice);

            if (strncmp(choice, "take", 4) == 0) {
                printf("You take a cobweb-covered object. It's too dark to see what it is.\n");
            } else if (strncmp(choice, "leave", 5) == 0) {
                printf("You decide to leave the cobweb-covered object behind.\n");
            } else if (strncmp(choice, "north", 5) == 0) {
                printf("You go through the door to the north.\n");
                room = random_room;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else if (room == 5) {
            printf("You see a large, ornate mirror on the wall and a door to the east.\n");
            printf("What would you like to do? (look/east) ");
            scanf("%s", choice);

            if (strncmp(choice, "look", 4) == 0) {
                printf("You look into the mirror and see a ghostly figure standing behind you.\n");
                printf("What would you like to do? (run/face) ");
                scanf("%s", choice);

                if (strncmp(choice, "run", 3) == 0) {
                    printf("You turn and run out of the room, slamming the door behind you.\n");
                    room = 3;
                } else if (strncmp(choice, "face", 4) == 0) {
                    printf("You turn around to face the figure, but it disappears before your eyes.\n");
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            } else if (strncmp(choice, "east", 4) == 0) {
                printf("You go through the door to the east.\n");
                room = random_room;
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else {
            printf("You have reached an invalid room. Please restart the game.\n");
            break;
        }
    }

    return 0;
}