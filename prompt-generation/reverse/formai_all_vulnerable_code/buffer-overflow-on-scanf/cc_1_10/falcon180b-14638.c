//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 10

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void move_forward(void) {
    printf("Vehicle moves forward\n");
}

void move_backward(void) {
    printf("Vehicle moves backward\n");
}

void turn_left(void) {
    printf("Vehicle turns left\n");
}

void turn_right(void) {
    printf("Vehicle turns right\n");
}

void start_engine(void) {
    printf("Engine started\n");
}

void stop_engine(void) {
    printf("Engine stopped\n");
}

void add_command(char *cmd, void (*func)(void)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Too many commands\n");
        return;
    }

    strcpy(commands[num_commands].command, cmd);
    commands[num_commands].function = func;

    num_commands++;
}

void execute_command(char *cmd) {
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(cmd, commands[i].command) == 0) {
            (*(commands[i].function))();
            return;
        }
    }

    printf("Invalid command\n");
}

int main(void) {
    add_command("forward", move_forward);
    add_command("backward", move_backward);
    add_command("left", turn_left);
    add_command("right", turn_right);
    add_command("start", start_engine);
    add_command("stop", stop_engine);

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        execute_command(input);
    }

    return 0;
}