//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

struct adventure_game {
    char *name;
    char *description;
    char *starting_location;
    char *ending_location;
    char *items[5];
};

struct adventure_game game = {
    "Alien Adventure",
    "You are an astronaut on a mission to explore a new planet. You have been sent to a planet on the edge of the galaxy to find evidence of extraterrestrial life. Your spaceship has been damaged in a previous encounter, and you must navigate through the planet's dangerous terrain to reach your destination.",
    "Space",
    "Planet's Surface",
    {"Oxygen Mask", "Food", "Water", "First Aid Kit", "Shield"}
};

void print_instructions() {
    printf("Welcome to %s!\n", game.name);
    printf("You are in %s.\n", game.starting_location);
    printf("You have the following items:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", game.items[i]);
    }
    printf("You can move to the following locations:\n");
    printf("%s\n", game.ending_location);
    printf("Enter a command: ");
}

void move_to_location(char *location) {
    if (strcmp(location, game.ending_location) == 0) {
        printf("You have reached %s!\n", location);
        printf("Congratulations, you have completed the adventure!\n");
        exit(0);
    } else {
        printf("You cannot move to that location.\n");
        printf("Enter a command: ");
    }
}

int main() {
    print_instructions();

    while (1) {
        char command[MAX_LINE_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            char location[MAX_LINE_LENGTH];
            scanf("%s", location);
            move_to_location(location);
        } else if (strcmp(command, "quit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
            printf("Enter a command: ");
        }
    }

    return 0;
}