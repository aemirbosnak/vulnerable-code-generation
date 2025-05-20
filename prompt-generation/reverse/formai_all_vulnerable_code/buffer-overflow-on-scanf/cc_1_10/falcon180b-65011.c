//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 5
#define MAX_COMMAND_LENGTH 20

struct command {
    char name[MAX_COMMAND_LENGTH];
    void (*function)();
};

void takeoff() {
    printf("Drone takes off!\n");
}

void land() {
    printf("Drone lands safely.\n");
}

void forward() {
    printf("Drone moves forward.\n");
}

void backward() {
    printf("Drone moves backward.\n");
}

void left() {
    printf("Drone turns left.\n");
}

void right() {
    printf("Drone turns right.\n");
}

void emergency_land() {
    printf("Emergency landing initiated.\n");
}

int main() {
    struct command commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands++] = (struct command) {"takeoff", takeoff};
    commands[num_commands++] = (struct command) {"land", land};
    commands[num_commands++] = (struct command) {"forward", forward};
    commands[num_commands++] = (struct command) {"backward", backward};
    commands[num_commands++] = (struct command) {"left", left};
    commands[num_commands++] = (struct command) {"right", right};
    commands[num_commands++] = (struct command) {"emergency_land", emergency_land};

    char input[MAX_COMMAND_LENGTH];

    while (true) {
        printf("Enter command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                (*commands[i].function)();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}