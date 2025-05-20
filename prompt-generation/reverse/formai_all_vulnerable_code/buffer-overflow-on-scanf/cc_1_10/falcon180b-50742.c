//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 50

typedef struct drone {
    char name[20];
    int x;
    int y;
    int z;
    int status;
} Drone;

typedef struct command {
    char text[MAX_COMMAND_LENGTH];
    int (*function)(Drone*, char*);
} Command;

void fly_to(Drone* drone, char* params) {
    int x, y, z;
    sscanf(params, "%d,%d,%d", &x, &y, &z);
    drone->x = x;
    drone->y = y;
    drone->z = z;
    printf("Drone %s is flying to (%d, %d, %d)\n", drone->name, x, y, z);
}

void land(Drone* drone, char* params) {
    printf("Drone %s is landing\n", drone->name);
    drone->status = 0;
}

void takeoff(Drone* drone, char* params) {
    printf("Drone %s is taking off\n", drone->name);
    drone->status = 1;
}

int main() {
    int num_drones;
    printf("Enter the number of drones: ");
    scanf("%d", &num_drones);

    Drone drones[MAX_DRONES];
    for (int i = 0; i < num_drones; i++) {
        printf("Enter the name of drone %d: ", i+1);
        scanf("%s", drones[i].name);
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].z = 0;
        drones[i].status = 0;
    }

    int num_commands;
    printf("Enter the number of commands: ");
    scanf("%d", &num_commands);

    Command commands[MAX_COMMANDS];
    for (int i = 0; i < num_commands; i++) {
        printf("Enter the command %d: ", i+1);
        scanf("%s", commands[i].text);
        commands[i].function = &fly_to;
    }

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].text) == 0) {
                commands[i].function(drones, input);
                break;
            }
        }
    }

    return 0;
}