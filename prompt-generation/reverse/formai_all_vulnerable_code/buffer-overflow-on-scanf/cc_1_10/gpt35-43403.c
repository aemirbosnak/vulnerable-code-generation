//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*
 * This program demonstrates how to use the C language to implement a simple 
 * text adventure game. The player is given a description of each room, and 
 * has to move through various rooms to find the treasure.
 *
 * This program is written in the style of Ada Lovelace, one of the early 
 * pioneers of computer programming. Ada Lovelace was known for her creativity
 * and her ability to use math and logic to solve complex problems.
 */

#include <stdio.h>
#include <stdlib.h>

/* Define the different rooms in the game */
enum ROOM {
    ENTRYWAY,
    LIVING_ROOM,
    KITCHEN,
    BEDROOM,
    BATHROOM,
    TREASURE_ROOM
};

/* Define a struct to hold information about each room */
struct Room {
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
};

/* Declare a function to create a new room */
struct Room* newRoom(char* description, struct Room* north, 
    struct Room* south, struct Room* east, struct Room* west);

/* Declare a function to print out the player's current location */
void printLocation(struct Room* playerLocation);

/* The main function */
int main() {
    /* Create the different rooms in the game */
    struct Room* entryway = newRoom("You are in the entryway. There is a coat rack by the door.", NULL, LIVING_ROOM, KITCHEN, NULL);
    struct Room* livingRoom = newRoom("You are in the living room. There is a couch and a TV.", NULL, NULL, BEDROOM, ENTRYWAY);
    struct Room* kitchen = newRoom("You are in the kitchen. There is a fridge and a stove.", ENTRYWAY, BATHROOM, TREASURE_ROOM, LIVING_ROOM);
    struct Room* bedroom = newRoom("You are in the bedroom. There is a bed and a dresser.", LIVING_ROOM, NULL, NULL, BATHROOM);
    struct Room* bathroom = newRoom("You are in the bathroom. There is a sink and a toilet.", BEDROOM, NULL, NULL, KITCHEN);
    struct Room* treasureRoom = newRoom("You have found the treasure! Congratulations!", NULL, NULL, NULL, KITCHEN);

    /* Set the player's starting location */
    struct Room* playerLocation = entryway;

    /* Print the player's starting location */
    printf("You are in the entryway. There is a coat rack by the door.\n");

    /* Loop until the player finds the treasure */
    while (playerLocation != treasureRoom) {
        /* Get the player's next move */
        printf("Which direction do you want to go? (n/s/e/w)\n");
        char direction;
        scanf("%c", &direction);
        getchar();  /* Clear the newline character from the input buffer */

        /* Move the player in the chosen direction */
        switch(direction) {
            case 'n':
                if (playerLocation->north != NULL) {
                    playerLocation = playerLocation->north;
                    printLocation(playerLocation);
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 's':
                if (playerLocation->south != NULL) {
                    playerLocation = playerLocation->south;
                    printLocation(playerLocation);
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'e':
                if (playerLocation->east != NULL) {
                    playerLocation = playerLocation->east;
                    printLocation(playerLocation);
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'w':
                if (playerLocation->west != NULL) {
                    playerLocation = playerLocation->west;
                    printLocation(playerLocation);
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }
    }

    /* Print the victory message */
    printf("Congratulations! You have found the treasure!\n");

    /* Free the memory used by the rooms */
    free(entryway);
    free(livingRoom);
    free(kitchen);
    free(bedroom);
    free(bathroom);
    free(treasureRoom);

    return 0;
}

/* This function creates a new room with the given description and exits */
struct Room* newRoom(char* description, struct Room* north, 
    struct Room* south, struct Room* east, struct Room* west) {
    struct Room* room = (struct Room*)malloc(sizeof(struct Room));
    room->description = description;
    room->north = north;
    room->south = south;
    room->east = east;
    room->west = west;
    return room;
}

/* This function prints out the player's current location */
void printLocation(struct Room* playerLocation) {
    printf("%s\n", playerLocation->description);
}