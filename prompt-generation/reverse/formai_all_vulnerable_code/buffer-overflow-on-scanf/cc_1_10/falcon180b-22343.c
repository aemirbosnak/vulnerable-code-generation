//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void move_forward(void) {
    printf("Drone is moving forward.\n");
}

void move_backward(void) {
    printf("Drone is moving backward.\n");
}

void turn_left(void) {
    printf("Drone is turning left.\n");
}

void turn_right(void) {
    printf("Drone is turning right.\n");
}

void takeoff(void) {
    printf("Drone is taking off.\n");
}

void land(void) {
    printf("Drone is landing.\n");
}

void emergency_stop(void) {
    printf("Drone is stopping immediately.\n");
}

command_t commands[MAX_COMMANDS] = {
    {"move_forward", move_forward},
    {"move_backward", move_backward},
    {"turn_left", turn_left},
    {"turn_right", turn_right},
    {"takeoff", takeoff},
    {"land", land},
    {"emergency_stop", emergency_stop}
};

int num_commands = sizeof(commands) / sizeof(commands[0]);

void execute_command(char *input) {
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].function();
            return;
        }
    }
    printf("Invalid command.\n");
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        execute_command(input);
    }

    return 0;
}