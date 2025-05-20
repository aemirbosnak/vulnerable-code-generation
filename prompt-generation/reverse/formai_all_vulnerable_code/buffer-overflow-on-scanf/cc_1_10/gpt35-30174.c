//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int room = 1;
char direction[20];

void move_player(char *direction) {
    if (strcmp(direction, "north") == 0 && room == 1) {
        printf("You walk north and enter the castle courtyard.\n");
        room = 2;
    } else if (strcmp(direction, "south") == 0 && room == 2) {
        printf("You walk south and exit the castle.\n");
        room = 1;
    } else if (strcmp(direction, "east") == 0 && room == 2) {
        printf("You walk east and enter the castle dungeon.\n");
        room = 3;
    } else if (strcmp(direction, "west") == 0 && room == 3) {
        printf("You walk west and find a treasure chest!\n");
        room = 4;
    } else {
        printf("Invalid command, try again.\n");
    }
}

void display_room() {
    switch (room) {
        case 1:
            printf("You are standing outside an old castle.\n");
            printf("You see a large wooden door to the north.\n");
            printf("Type 'north' to enter.\n");
            break;
        case 2:
            printf("You are in the castle courtyard.\n");
            printf("You can go north or south.\n");
            printf("Type 'north' to go into the castle.\n");
            printf("Type 'south' to exit the castle.\n");
            break;
        case 3:
            printf("You are in the castle dungeon.\n");
            printf("You can go east or west.\n");
            printf("Type 'east' to go to the treasure room.\n");
            printf("Type 'west' to go back to the courtyard.\n");
            break;
        case 4:
            printf("You found the treasure chest!\n");
            printf("You win the game!\n");
            exit(0);
        default:
            printf("Invalid room number.\n");
            break;
    }
}

int main() {
    printf("Welcome to Castle Adventure!\n");
    printf("Type 'help' for a list of commands.\n\n");
    
    while (1) {
        display_room();
        printf("What is your command? ");
        scanf("%s", direction);

        if (strcmp(direction, "help") == 0) {
            printf("List of commands:\n");
            printf("north - go north\n");
            printf("south - go south\n");
            printf("east - go east\n");
            printf("west - go west\n");
            printf("help - display this list of commands\n\n");
        } else {
            move_player(direction);
        }
    }

    return 0;
}