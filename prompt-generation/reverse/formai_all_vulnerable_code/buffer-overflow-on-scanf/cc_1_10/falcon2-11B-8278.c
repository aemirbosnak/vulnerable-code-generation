//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_COMMAND_LENGTH 20

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[]) {
    char roomName[MAX_ROOM_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the C Text-Based Adventure Game!\n");

    // Define rooms
    char* rooms[4] = {"Forest", "Cave", "Castle", "End"};

    // Define descriptions
    char* descriptions[4] = {
        "You find yourself in a dense forest. You see a small stream nearby.",
        "You enter a dark and damp cave. You hear the sound of dripping water.",
        "You stand before a majestic castle. A sign reads, 'Beware of dragons'.",
        "You reach the end of the game."
    };

    // Define commands
    char* commands[4] = {
        "north", "south", "east", "west", "look", "exit"
    };

    int currentRoom = 0;

    while (currentRoom < 4) {
        printf("You are in the %s.\n", rooms[currentRoom]);
        printf("The description is: %s\n", descriptions[currentRoom]);
        printf("What do you want to do?\n");

        // Read command
        scanf("%s", command);

        // Check if command is valid
        if (strlen(command) > 0 && strcmp(command, "exit")!= 0) {
            printf("You can't do that!\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            return EXIT_SUCCESS;
        } else {
            printf("You moved to the %s.\n", rooms[currentRoom]);
            printf("The description is: %s\n", descriptions[currentRoom]);
        }
    }

    return EXIT_FAILURE;
}