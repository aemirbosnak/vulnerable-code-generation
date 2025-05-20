//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

enum {
    FORWARD = 'f',
    BACKWARD = 'b',
    LEFT = 'l',
    RIGHT = 'r',
    STOP ='s'
};

typedef struct {
    char command;
    int duration;
} Command;

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command commands[MAX_COMMANDS];
    int num_commands = 0;

    printf("Enter commands (f for forward, b for backward, l for left, r for right, s for stop, followed by duration in milliseconds):\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (num_commands >= MAX_COMMANDS) {
            printf("Maximum number of commands reached.\n");
            break;
        }

        char *command = strtok(input, " ");
        int duration = atoi(strtok(NULL, " "));

        if (command == NULL || duration <= 0) {
            printf("Invalid command.\n");
            continue;
        }

        switch (command[0]) {
            case 'f':
                commands[num_commands].command = FORWARD;
                break;
            case 'b':
                commands[num_commands].command = BACKWARD;
                break;
            case 'l':
                commands[num_commands].command = LEFT;
                break;
            case 'r':
                commands[num_commands].command = RIGHT;
                break;
            case's':
                commands[num_commands].command = STOP;
                break;
            default:
                printf("Invalid command.\n");
                continue;
        }

        commands[num_commands].duration = duration;
        num_commands++;
    }

    if (num_commands == 0) {
        printf("No valid commands entered.\n");
        return 1;
    }

    int current_command = 0;
    while (1) {
        usleep(commands[current_command].duration * 1000);

        switch (commands[current_command].command) {
            case FORWARD:
                printf("Moving forward...\n");
                break;
            case BACKWARD:
                printf("Moving backward...\n");
                break;
            case LEFT:
                printf("Turning left...\n");
                break;
            case RIGHT:
                printf("Turning right...\n");
                break;
            case STOP:
                printf("Stopping...\n");
                break;
            default:
                break;
        }

        current_command = (current_command + 1) % num_commands;
    }

    return 0;
}