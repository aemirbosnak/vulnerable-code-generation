//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LEN 20

typedef struct {
    char command[MAX_COMMAND_LEN];
    void (*function)(void);
} command_t;

void move_forward(void) {
    printf("Drone is moving forward.\n");
}

void move_backward(void) {
    printf("Drone is moving backward.\n");
}

void move_left(void) {
    printf("Drone is moving left.\n");
}

void move_right(void) {
    printf("Drone is moving right.\n");
}

void takeoff(void) {
    printf("Drone is taking off.\n");
}

void land(void) {
    printf("Drone is landing.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"forward", move_forward},
        {"backward", move_backward},
        {"left", move_left},
        {"right", move_right},
        {"takeoff", takeoff},
        {"land", land}
    };

    int num_commands = 0;
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].command, argv[1]) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command. Available commands: ");
    for (int i = 0; i < MAX_COMMANDS; i++) {
        printf("%s ", commands[i].command);
    }
    printf("\n");

    return 1;
}