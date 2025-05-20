//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define DRONE_MAX_SPEED 100
#define DRONE_MIN_SPEED 0
#define DRONE_MAX_ALTITUDE 50
#define DRONE_MIN_ALTITUDE 0
#define DRONE_MAX_BATTERY 100
#define DRONE_MIN_BATTERY 0

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int speed;
    int altitude;
    int battery;
} DroneCommand;

void parse_command(DroneCommand* command, char* input) {
    strcpy(command->command, input);
    char* delimiter = strtok(command->command, ":");
    if (delimiter == NULL) {
        command->speed = 0;
        command->altitude = 0;
        command->battery = 0;
    } else {
        command->speed = atoi(delimiter);
        delimiter = strtok(NULL, ":");
        if (delimiter == NULL) {
            command->altitude = 0;
            command->battery = 0;
        } else {
            command->altitude = atoi(delimiter);
            delimiter = strtok(NULL, ":");
            if (delimiter == NULL) {
                command->battery = 0;
            } else {
                command->battery = atoi(delimiter);
            }
        }
    }
}

void execute_command(DroneCommand* command) {
    if (command->speed >= DRONE_MIN_SPEED && command->speed <= DRONE_MAX_SPEED) {
        printf("Drone speed set to %d\n", command->speed);
    } else {
        printf("Invalid speed value\n");
    }

    if (command->altitude >= DRONE_MIN_ALTITUDE && command->altitude <= DRONE_MAX_ALTITUDE) {
        printf("Drone altitude set to %d\n", command->altitude);
    } else {
        printf("Invalid altitude value\n");
    }

    if (command->battery >= DRONE_MIN_BATTERY && command->battery <= DRONE_MAX_BATTERY) {
        printf("Drone battery set to %d\n", command->battery);
    } else {
        printf("Invalid battery value\n");
    }
}

int main() {
    DroneCommand command;
    char input[MAX_COMMAND_LENGTH];

    while (true) {
        printf("Enter command (speed:altitude:battery): ");
        scanf("%s", input);
        parse_command(&command, input);
        execute_command(&command);
    }

    return 0;
}