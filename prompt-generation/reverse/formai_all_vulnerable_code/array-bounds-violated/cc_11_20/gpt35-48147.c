//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining max length of player name and input command
#define MAX_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 20

int main() {
    // initializing variables
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int points = 0;
    int room = 1;
    int gameRunning = 1;

    // getting the player's name
    printf("What is your name?\n");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1]='\0'; // removes the newline character from the name

    // game loop
    while (gameRunning) {
        switch (room) {
            case 1:
                printf("\n%s, you are stranded on an island. You see a jungle to the east and a beach to the west.", name);
                printf("\nWhat would you like to do? (go east/go west)");
                fgets(command, sizeof(command), stdin);
                command[strlen(command)-1]='\0'; // removes the newline character from the command

                if (strcmp(command, "go east") == 0) {
                    printf("\nYou walk into the jungle and find a stream. You drink from it and gain 5 points.");
                    points += 5;
                    room = 2;
                }
                else if (strcmp(command, "go west") == 0) {
                    printf("\nYou walk along the beach and find some coconuts. You eat them and gain 3 points.");
                    points += 3;
                    room = 3;
                }
                break;

            case 2:
                printf("\nYou are in the jungle. You see a cave to the north and a waterfall to the south.");
                printf("\nWhat would you like to do? (go north/go south/quit)");
                fgets(command, sizeof(command), stdin);
                command[strlen(command)-1]='\0'; // removes the newline character from the command

                if (strcmp(command, "go north") == 0) {
                    printf("\nYou find a treasure chest in the cave. You open it and gain 10 points.");
                    points += 10;
                    room = 4;
                }
                else if (strcmp(command, "go south") == 0) {
                    printf("\nYou go towards the waterfall and get caught in a strong current. You lose 5 points.");
                    points -= 5;
                    room = 3;
                }
                else if (strcmp(command, "quit") == 0) {
                    printf("\nYou quit the game. Your final score is %d points.", points);
                    gameRunning = 0;
                }
                break;

            case 3:
                printf("\nYou are back on the beach. You see the jungle to the east and a cliff to the south.");
                printf("\nWhat would you like to do? (go east/go south/quit)");
                fgets(command, sizeof(command), stdin);
                command[strlen(command)-1]='\0'; // removes the newline character from the command

                if (strcmp(command, "go east") == 0) {
                    room = 2;
                }
                else if (strcmp(command, "go south") == 0) {
                    printf("\nYou climb down the cliff and find a cave. You enter it and gain 8 points.");
                    points += 8;
                    room = 4;
                }
                else if (strcmp(command, "quit") == 0) {
                    printf("\nYou quit the game. Your final score is %d points.", points);
                    gameRunning = 0;
                }
                break;

            case 4:
                printf("\nYou are in the treasure room! You win the game with a score of %d points.", points);
                gameRunning = 0;
                break;
        }
    }

    return 0;
}