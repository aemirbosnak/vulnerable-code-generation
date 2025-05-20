//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to handle player movement
void move(char *direction, int *position, int map_size) {
    if(strcmp(direction, "north") == 0) {
        if(*position >= map_size) {
            printf("You cannot go north any further.\n");
        } else {
            *position += 1;
            printf("You've moved north! You are now at position %d.\n", *position);
        }
    } else if(strcmp(direction, "south") == 0) {
        if(*position <= 1) {
            printf("You cannot go south any further.\n");
        } else {
            *position -= 1;
            printf("You've moved south! You are now at position %d.\n", *position);
        }
    } else {
        printf("I didn't understand that command.\n");
    }
}

int main() {
    printf("Welcome to Grateful Adventure!\n");
    printf("You are on a quest to find the Grateful Gems!\n");
    printf("Your journey starts...\n");

    // set up game variables
    int position = 1;
    int gems_found = 0;
    int map_size = 5;
    char command[10];

    // game loop
    while(1) {
        printf("\nEnter a command (north/south/quit): ");
        scanf("%s", command);

        // handle player movement
        if(strcmp(command, "north") == 0 || strcmp(command, "south") == 0) {
            move(command, &position, map_size);
        } else if(strcmp(command, "quit") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        } else {
            printf("I didn't understand that command.\n");
        }

        // check if player found a gem
        if(position == 3 && gems_found == 0) {
            printf("You found a Grateful Gem! (+10 points)\n");
            gems_found = 1;
        }

        // check if player won
        if(gems_found == 1 && position == map_size) {
            printf("Congratulations! You found all the Grateful Gems!\n");
            printf("Your journey comes to an end with a grateful heart.\n");
            return 0;
        }
    }
}