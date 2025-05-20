//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInput() {
    // Helper function to clear input buffer
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void gameLoop() {
    // Main game loop
    char playerName[20];
    printf("Welcome to the Surrealist Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", playerName);
    printf("Hello, %s! Let's begin.\n", playerName);
    
    // Initialize game variables
    int gameOver = 0;
    int room = 1; // Player starts in Room 1
    int hasKey = 0;
    
    // Main game logic
    while (!gameOver) {
        switch (room) {
            case 1:
                printf("You are in Room 1. There is a door to the north.\n");
                if (hasKey) {
                    printf("You have a key.\n");
                }
                printf("What do you want to do? ");
                char action[10];
                scanf("%s", action);
                clearInput();
                if (strcmp(action, "go") == 0) {
                    printf("You go north and enter Room 2.\n");
                    room = 2;
                } else if (strcmp(action, "pickup") == 0) {
                    printf("There is nothing to pickup here.\n");
                } else if (strcmp(action, "use") == 0) {
                    printf("There is nothing to use here.\n");
                } else if (strcmp(action, "look") == 0) {
                    printf("You see a key on the ground.\n");
                } else {
                    printf("I'm sorry, I don't understand that command.\n");
                }
                break;
            case 2:
                printf("You are in Room 2. There is a door to the east and a door to the west.\n");
                printf("What do you want to do? ");
                scanf("%s", action);
                clearInput();
                if (strcmp(action, "go") == 0) {
                    printf("Which direction? ");
                    char direction[10];
                    scanf("%s", direction);
                    clearInput();
                    if (strcmp(direction, "east") == 0) {
                        printf("You go east and enter Room 3.\n");
                        room = 3;
                    } else if (strcmp(direction, "west") == 0) {
                        printf("You go west and enter Room 1.\n");
                        room = 1;
                    } else {
                        printf("I'm sorry, I don't understand that direction.\n");
                    }
                } else if (strcmp(action, "pickup") == 0) {
                    printf("There is nothing to pickup here.\n");
                } else if (strcmp(action, "use") == 0) {
                    printf("There is nothing to use here.\n");
                } else if (strcmp(action, "look") == 0) {
                    printf("You see a locked door to the north.\n");
                } else {
                    printf("I'm sorry, I don't understand that command.\n");
                }
                break;
            case 3:
                printf("You are in Room 3. There is a locked door to the north.\n");
                if (hasKey) {
                    printf("You have a key.\n");
                }
                printf("What do you want to do? ");
                scanf("%s", action);
                clearInput();
                if (strcmp(action, "go") == 0) {
                    printf("There is no clear exit from this room.\n");
                } else if (strcmp(action, "pickup") == 0) {
                    printf("There is nothing to pickup here.\n");
                } else if (strcmp(action, "use") == 0) {
                    printf("What would you like to use? ");
                    char item[10];
                    scanf("%s", item);
                    clearInput();
                    if (strcmp(item, "key") == 0) {
                        if (hasKey) {
                            printf("You have already used the key.\n");
                        } else {
                            printf("You use the key to unlock the door to the north.\n");
                            printf("You go north and enter the final room.\n");
                            room = 4;
                        }
                    } else {
                        printf("You can't use that item here.\n");
                    }
                } else if (strcmp(action, "look") == 0) {
                    printf("You see a key on the floor.\n");
                } else {
                    printf("I'm sorry, I don't understand that command.\n");
                }
                break;
            case 4:
                printf("You are in the final room. There is a note on the desk.\n");
                printf("What do you want to do? ");
                scanf("%s", action);
                clearInput();
                if (strcmp(action, "go") == 0) {
                    printf("There is no clear exit from this room.\n");
                } else if (strcmp(action, "pickup") == 0) {
                    printf("There is nothing else to pickup here.\n");
                } else if (strcmp(action, "use") == 0) {
                    printf("There is nothing else to use here.\n");
                } else if (strcmp(action, "look") == 0) {
                    printf("The note reads: 'Congratulations! You have completed the game.'\n");
                } else if (strcmp(action, "read") == 0) {
                    printf("The note reads: 'Congratulations! You have completed the game.'\n");
                    printf("Thank you for playing, %s!\n", playerName);
                    gameOver = 1;
                } else {
                    printf("I'm sorry, I don't understand that command.\n");
                }
                break;
            default:
                printf("Game over.\n");
                gameOver = 1;
        }
    }
}

int main() {
    gameLoop();
    return 0;
}