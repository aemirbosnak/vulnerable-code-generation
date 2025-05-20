//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
/*
 * Space Adventure Game
 *
 * In this game, you will play as a spaceship that is trying to escape
 * from an alien planet. You will be given a series of commands to
 * move your spaceship, and you must use these commands to make it
 * to the escape pod before the planet's atmosphere is too thick.
 *
 * The game will start with a series of prompts, asking you to
 * enter a command. You can enter any command that starts with
 * the word "move" followed by a direction (e.g. "move left").
 * You can also enter the word "status" to see the current state
 * of your spaceship.
 *
 * The game will end when you reach the escape pod, or when the
 * planet's atmosphere becomes too thick.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_SPACESHIP_POSITION 10

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

struct spaceship {
    int position;
    int fuel;
    int oxygen;
    enum direction direction;
};

void print_prompt() {
    printf("> ");
}

void print_status(struct spaceship *ship) {
    printf("You are at position %d, with %d units of fuel and %d units of oxygen.\n",
           ship->position, ship->fuel, ship->oxygen);
}

void move_spaceship(struct spaceship *ship, enum direction direction) {
    switch (direction) {
        case UP:
            ship->position++;
            break;
        case DOWN:
            ship->position--;
            break;
        case LEFT:
            ship->position--;
            break;
        case RIGHT:
            ship->position++;
            break;
        default:
            break;
    }
}

int main() {
    struct spaceship ship;
    ship.position = 0;
    ship.fuel = 100;
    ship.oxygen = 100;
    ship.direction = NONE;

    char command[MAX_COMMAND_LENGTH];
    while (1) {
        print_prompt();
        scanf("%s", command);

        if (strcmp(command, "status") == 0) {
            print_status(&ship);
        } else if (strncmp(command, "move", 4) == 0) {
            enum direction direction = NONE;
            if (strcmp(command + 4, "up") == 0) {
                direction = UP;
            } else if (strcmp(command + 4, "down") == 0) {
                direction = DOWN;
            } else if (strcmp(command + 4, "left") == 0) {
                direction = LEFT;
            } else if (strcmp(command + 4, "right") == 0) {
                direction = RIGHT;
            }
            move_spaceship(&ship, direction);
        } else {
            printf("Invalid command.\n");
        }

        if (ship.position >= MAX_SPACESHIP_POSITION) {
            printf("You have reached the escape pod.\n");
            break;
        }

        if (ship.fuel <= 0 || ship.oxygen <= 0) {
            printf("You have run out of fuel or oxygen.\n");
            break;
        }
    }

    return 0;
}