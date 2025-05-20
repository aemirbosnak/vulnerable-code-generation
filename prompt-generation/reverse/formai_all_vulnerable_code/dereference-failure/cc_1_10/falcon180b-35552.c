//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DRONES 100
#define MAX_COMMANDS 10
#define COMMAND_LENGTH 20

struct drone {
    char name[COMMAND_LENGTH];
    int x, y, z;
};

struct command {
    char name[COMMAND_LENGTH];
    int (*function)(struct drone *);
};

void move(struct drone *drone) {
    drone->x += 10;
    drone->y += 10;
    drone->z += 10;
}

void rotate(struct drone *drone) {
    drone->z += 45;
}

int main() {
    int num_drones, num_commands;
    printf("Enter the number of drones: ");
    scanf("%d", &num_drones);

    struct drone *drones = malloc(num_drones * sizeof(struct drone));

    for (int i = 0; i < num_drones; i++) {
        printf("Enter the name of drone %d: ", i + 1);
        scanf("%s", drones[i].name);
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].z = 0;
    }

    printf("Enter the number of commands: ");
    scanf("%d", &num_commands);

    struct command *commands = malloc(num_commands * sizeof(struct command));

    for (int i = 0; i < num_commands; i++) {
        printf("Enter the name of command %d: ", i + 1);
        scanf("%s", commands[i].name);
        commands[i].function = NULL;
    }

    int choice;
    while (1) {
        printf("\n1. Move\n2. Rotate\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < num_drones; i++) {
                move(&drones[i]);
            }
        } else if (choice == 2) {
            for (int i = 0; i < num_drones; i++) {
                rotate(&drones[i]);
            }
        } else if (choice == 3) {
            break;
        }
    }

    free(drones);
    free(commands);

    return 0;
}