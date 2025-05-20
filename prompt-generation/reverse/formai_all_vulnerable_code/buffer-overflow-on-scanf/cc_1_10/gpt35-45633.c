//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* defining the available actions for the player */
enum Action {NONE, EXPLORE, TAKE, USE, ATTACK, ESCAPE};

/* struct for storing information about each room in the game map */
struct Room {
    const char* description;
    int explored;
    int items;
    int enemies;
    int connected_rooms[4];  /* array of the room IDs for each connected room (North, South, East, West) */
};

/* function prototypes */
void printIntro();
void printMap(struct Room room_list[], int current_room);
void printOptions(struct Room room);
enum Action getAction();
int executeAction(enum Action action, struct Room* room_ptr, int* items_ptr, int* enemies_ptr);
void printEnding(int win);

int main() {

    srand(time(NULL));  /* seeding random number generator */

    /* Game map definition */
    struct Room room_list[] = {
        {"You are in a dusty old hallway. There are doors to the North and South.", 1, 0, 0, {1, -1, -1, -1}},
        {"You are in a dimly lit bedroom. There is a bed with a black silk sheet in the center of the room. ", 0, 1, 1, {2, 0, -1, -1}},
        {"You are in a beautifully decorated sitting room. The walls are covered in gold leaf, and there is a plush red couch in the center. ", 0, 1, 0, {3, 1, -1, -1}},
        {"You are in a dark cellar. The smell of mold and mildew is overwhelming. ", 0, 0, 2, {-1, 2, 2, 2}},  
    };

    int items = 0;
    int enemies = 3;  /* total number of enemies in the game */
    int current_room = 0;

    printIntro();

    /* main game loop */
    while (enemies > 0) {
        struct Room current = room_list[current_room];
        if (!current.explored) {
            /* if room has not yet been explored, print its description and available options */
            printf("%s\n", current.description);
            printOptions(current);
            current.explored = 1; /* mark room as explored */
        }
        enum Action action = getAction();
        int result = executeAction(action, &current, &items, &enemies);
        if (result == -1) {
            /* executeAction() returns -1 if the player dies */
            printEnding(0);
            return 0;
        }
        else if (result == 1) {
            /* executeAction() returns 1 if the player wins */
            printEnding(1);
            return 0;
        }
        /* if player has not won or died, move on to the next turn */
        printf("\n\n");
        current_room = current.connected_rooms[rand() % 4]; /* randomly select one of the connected rooms */
    }
    return 0;
}

void printIntro() {
    printf("You are stranded in a haunted mansion. The only way to get out is by defeating all the ghosts in the building.\n\n");
    printf("You start in a narrow hallway.\n\n");
}

void printMap(struct Room room_list[], int current_room) {
    /* prints a simplified map of the mansion */
    printf("MAP\n");
    printf("1");
    if (current_room == 0) {
        printf("*");
    }
    printf(" --- 2");
    if (current_room == 1) {
        printf("*");
    }
    printf(" --- 3");
    if (current_room == 2) {
        printf("*");
    }
    printf("\n");
    printf("|           |\n");
    printf("|           |\n");
    printf("|           |\n");
    printf("4 ---------|\n");
    printf("|           |\n");
    printf("|           |\n");
    printf("|           |\n");
}

void printOptions(struct Room room) {
    /* prints the available actions for the player */
    printf("AVAILABLE ACTIONS:\n");
    printf("Explore - Look around the room.\n");
    if (room.items) {
        printf("Take - Pick up any items in the room.\n");
    }
    if (room.enemies > 0) {
        printf("Attack - Fight the ghosts in the room.\n");
    }
    if (room.connected_rooms[0] != -1 || room.connected_rooms[1] != -1 || room.connected_rooms[2] != -1 || room.connected_rooms[3] != -1) {
        printf("Escape - Try to leave the room.\n");
    }
}

enum Action getAction() {
    /* reads the player's input and returns the corresponding Action */
    char input[10];
    printf("\nWhat do you want to do? ");
    scanf("%s", input);
    if (strcmp(input, "explore") == 0) {
        return EXPLORE;
    }
    else if (strcmp(input, "take") == 0) {
        return TAKE;
    }
    else if (strcmp(input, "use") == 0) {
        return USE;
    }
    else if (strcmp(input, "attack") == 0) {
        return ATTACK;
    }
    else if (strcmp(input, "escape") == 0) {
        return ESCAPE;
    }
    else {
        printf("Invalid option.\n");
        return NONE;
    }
}

int executeAction(enum Action action, struct Room* room_ptr, int* items_ptr, int* enemies_ptr) {
    /* executes the given action and returns 0 if the game continues, -1 if the player dies, and 1 if the player wins */
    switch (action) {
        case EXPLORE:
            printf("%s\n", room_ptr->description);
            return 0;
        case TAKE:
            if (room_ptr->items) {
                printf("You found a flashlight.\n");
                *items_ptr += 1;  /* increment player's items */
                room_ptr->items = 0;
            }
            else {
                printf("There are no items to pick up in this room.\n");
            }
            return 0;
        case USE:
            if (*items_ptr > 0) {
                printf("You use the flashlight to light up the room, but there are still ghosts around.\n");
            }
            else {
                printf("You don't have any items to use.\n");
            }
            return 0;
        case ATTACK:
            if (room_ptr->enemies > 0) {
                int chance = rand() % 2;  /* randomly determine if attack is successful */
                if (chance == 0) {
                    printf("You missed! The ghosts are coming closer!\n");
                    return 0;
                }
                else {
                    printf("You got one of the ghosts! %d more to go.\n", room_ptr->enemies - 1);
                    room_ptr->enemies -= 1;
                    *enemies_ptr -= 1;
                    if (*enemies_ptr == 0) {
                        return 1;  /* player wins */
                    }
                    else {
                        return 0;
                    }
                }
            }
            else {
                printf("There are no ghosts in this room.\n");
            }
            return 0;
        case ESCAPE:
            if (room_ptr->connected_rooms[0] != -1 || room_ptr->connected_rooms[1] != -1 || room_ptr->connected_rooms[2] != -1 || room_ptr->connected_rooms[3] != -1) {
                printf("You manage to escape to another room.\n");
                return 0;
            }
            else {
                printf("There are no other ways out of this room.\n");
            }
            return 0;
        case NONE:
            return 0;
    }
    return 0;
}

void printEnding(int win) {
    /* prints the game ending message depending on whether the player won or not */
    printf("\n");
    if (win) {
        printf("Congratulations! You have successfully defeated all the ghosts in the mansion and managed to escape.\n");
        printf("You win!\n");
    }
    else {
        printf("You were caught by the ghosts and trapped forever in the haunted mansion.\n");
        printf("You lose!\n");
    }
    printf("\n");
}