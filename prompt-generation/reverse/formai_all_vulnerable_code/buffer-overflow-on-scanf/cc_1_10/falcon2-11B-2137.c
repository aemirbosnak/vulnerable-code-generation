//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char shipName[MAX_LEN];
    char planetName[MAX_LEN];
    char command[MAX_LEN];
    int choice;

    printf("Welcome to the space adventure! Please enter your ship name: ");
    scanf("%s", shipName);

    printf("You have just set off on a journey through the unknown reaches of space. What is your destination?\n");
    printf("Type 'planet' to travel to a new planet, or 'back' to return to your ship:\n");

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "planet") == 0) {
            printf("You have arrived at a new planet! What will you do?\n");
            printf("Type 'explore' to investigate the planet, or 'back' to return to your ship:\n");
        } else if (strcmp(command, "back") == 0) {
            printf("You have returned to your ship. What is your next destination?\n");
            printf("Type 'planet' to travel to a new planet, or 'back' to return to your ship:\n");
        } else {
            printf("Invalid command. Please enter 'planet' or 'back':\n");
        }

        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            printf("You have begun exploring the planet. What will you do next?\n");
            printf("Type'search' to look for resources, or 'back' to return to your ship:\n");
        } else if (strcmp(command, "search") == 0) {
            printf("You have found some valuable resources on the planet. You decide to return to your ship.\n");
        } else if (strcmp(command, "back") == 0) {
            printf("You have returned to your ship. What is your next destination?\n");
            printf("Type 'planet' to travel to a new planet, or 'back' to return to your ship:\n");
        } else {
            printf("Invalid command. Please enter 'explore','search', or 'back':\n");
        }

        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "back") == 0) {
            printf("You have returned to your ship. What is your next destination?\n");
            printf("Type 'planet' to travel to a new planet, or 'back' to return to your ship:\n");
        } else if (strcmp(command, "planet") == 0) {
            printf("You have arrived at a new planet! What will you do?\n");
            printf("Type 'explore' to investigate the planet, or 'back' to return to your ship:\n");
        } else {
            printf("Invalid command. Please enter 'planet' or 'back':\n");
        }

        printf("> ");
        scanf("%s", command);
    }

    return 0;
}