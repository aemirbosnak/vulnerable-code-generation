//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 80

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly_forward(void) {
    printf("Thy drone doth fly forward with great haste.\n");
}

void fly_backward(void) {
    printf("Thy drone doth retreat backward with grace.\n");
}

void fly_left(void) {
    printf("Thy drone doth veer leftward with agility.\n");
}

void fly_right(void) {
    printf("Thy drone doth turn rightward with skill.\n");
}

void ascend(void) {
    printf("Thy drone doth ascend towards the heavens.\n");
}

void descend(void) {
    printf("Thy drone doth descend towards the earth.\n");
}

command_t commands[] = {
    {"forward", fly_forward},
    {"backward", fly_backward},
    {"left", fly_left},
    {"right", fly_right},
    {"ascend", ascend},
    {"descend", descend},
};

int num_commands = sizeof(commands) / sizeof(commands[0]);

void process_command(char *input) {
    char *token = strtok(input, " ");
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(token, commands[i].command) == 0) {
            commands[i].function();
            return;
        }
    }

    printf("Verily, I know not the command '%s'.\n", token);
}

int main(void) {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Drone Remote Control!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        process_command(input);
    }

    return 0;
}