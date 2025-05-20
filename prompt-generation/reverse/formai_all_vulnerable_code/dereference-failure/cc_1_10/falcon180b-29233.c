//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DRONE_MAX_COMMANDS 20
#define DRONE_MAX_COMMAND_LENGTH 10

typedef struct drone_command_t {
    char command[DRONE_MAX_COMMAND_LENGTH];
    int (*function)(void);
} drone_command_t;

void drone_takeoff(void) {
    printf("Drone taking off...\n");
}

void drone_land(void) {
    printf("Drone landing...\n");
}

void drone_move_forward(void) {
    printf("Drone moving forward...\n");
}

void drone_move_backward(void) {
    printf("Drone moving backward...\n");
}

void drone_move_left(void) {
    printf("Drone moving left...\n");
}

void drone_move_right(void) {
    printf("Drone moving right...\n");
}

void drone_rotate_left(void) {
    printf("Drone rotating left...\n");
}

void drone_rotate_right(void) {
    printf("Drone rotating right...\n");
}

drone_command_t drone_commands[DRONE_MAX_COMMANDS] = {
    {"takeoff", &drone_takeoff},
    {"land", &drone_land},
    {"forward", &drone_move_forward},
    {"backward", &drone_move_backward},
    {"left", &drone_move_left},
    {"right", &drone_move_right},
    {"rotate_left", &drone_rotate_left},
    {"rotate_right", &drone_rotate_right}
};

void drone_command_handler(char* command) {
    int i;
    for (i = 0; i < DRONE_MAX_COMMANDS; i++) {
        if (strcmp(drone_commands[i].command, command) == 0) {
            (*drone_commands[i].function)();
            break;
        }
    }
    if (i == DRONE_MAX_COMMANDS) {
        printf("Invalid command: %s\n", command);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }
    drone_command_handler(argv[1]);
    return 0;
}