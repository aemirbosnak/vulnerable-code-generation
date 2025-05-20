//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTIONS 4
#define MAX_SPEEDS 4

// Define the structure for a movement command
typedef struct {
    char direction;
    int speed;
} movement_command_t;

// Define the structure for a movement sequence
typedef struct {
    int num_commands;
    movement_command_t commands[MAX_DIRECTIONS];
} movement_sequence_t;

// Define the function for executing a movement command
void execute_command(movement_command_t command) {
    if (command.direction == 'F') {
        printf("Moving forward at speed %d\n", command.speed);
    } else if (command.direction == 'B') {
        printf("Moving backward at speed %d\n", command.speed);
    } else if (command.direction == 'L') {
        printf("Turning left at speed %d\n", command.speed);
    } else if (command.direction == 'R') {
        printf("Turning right at speed %d\n", command.speed);
    }
}

// Define the function for executing a movement sequence
void execute_sequence(movement_sequence_t sequence) {
    for (int i = 0; i < sequence.num_commands; i++) {
        execute_command(sequence.commands[i]);
    }
}

// Define the function for parsing a movement command string
movement_command_t parse_command(char* command_string) {
    movement_command_t command;
    char* token = strtok(command_string, " ");
    command.direction = token[0];
    command.speed = atoi(token + 1);
    return command;
}

// Define the function for parsing a movement sequence string
movement_sequence_t parse_sequence(char* sequence_string) {
    movement_sequence_t sequence;
    char* token = strtok(sequence_string, ";");
    while (token!= NULL) {
        movement_command_t command = parse_command(token);
        sequence.commands[sequence.num_commands++] = command;
        token = strtok(NULL, ";");
    }
    return sequence;
}

// Define the main function for the robot movement control program
int main() {
    movement_sequence_t sequence = parse_sequence("F 3;L 2;B 1;R 4");
    execute_sequence(sequence);
    return 0;
}