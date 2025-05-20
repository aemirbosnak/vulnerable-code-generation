//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Drone is taking off\n");
}

void land(void) {
    printf("Drone is landing\n");
}

void move_forward(void) {
    printf("Drone is moving forward\n");
}

void move_backward(void) {
    printf("Drone is moving backward\n");
}

void move_left(void) {
    printf("Drone is moving left\n");
}

void move_right(void) {
    printf("Drone is moving right\n");
}

void rotate_left(void) {
    printf("Drone is rotating left\n");
}

void rotate_right(void) {
    printf("Drone is rotating right\n");
}

void emergency_stop(void) {
    printf("Drone is stopping immediately\n");
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {
        {"takeoff", takeoff},
        {"land", land},
        {"forward", move_forward},
        {"backward", move_backward},
        {"left", move_left},
        {"right", move_right},
        {"rotate_left", rotate_left},
        {"rotate_right", rotate_right},
        {"stop", emergency_stop}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}