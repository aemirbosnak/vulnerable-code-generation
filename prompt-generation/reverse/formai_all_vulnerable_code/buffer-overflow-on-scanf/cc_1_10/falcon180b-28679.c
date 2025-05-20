//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 50
#define MAX_DRONES 10

typedef struct {
    char name[20];
    int x;
    int y;
    int z;
} Drone;

void add_drone(Drone* drones, int num_drones, char* name) {
    int i;
    for (i = 0; i < num_drones; i++) {
        if (strcmp(drones[i].name, name) == 0) {
            printf("Drone %s already exists.\n", name);
            return;
        }
    }
    strcpy(drones[num_drones].name, name);
    drones[num_drones].x = 0;
    drones[num_drones].y = 0;
    drones[num_drones].z = 0;
    num_drones++;
}

void remove_drone(Drone* drones, int num_drones, char* name) {
    int i;
    for (i = 0; i < num_drones; i++) {
        if (strcmp(drones[i].name, name) == 0) {
            memmove(&drones[i], &drones[i+1], (num_drones - i - 1) * sizeof(Drone));
            num_drones--;
            break;
        }
    }
}

void move_drone(Drone* drones, int num_drones, char* name, int dx, int dy, int dz) {
    int i;
    for (i = 0; i < num_drones; i++) {
        if (strcmp(drones[i].name, name) == 0) {
            drones[i].x += dx;
            drones[i].y += dy;
            drones[i].z += dz;
            break;
        }
    }
}

void list_drones(Drone* drones, int num_drones) {
    int i;
    for (i = 0; i < num_drones; i++) {
        printf("%s: (%d, %d, %d)\n", drones[i].name, drones[i].x, drones[i].y, drones[i].z);
    }
}

int main() {
    Drone drones[MAX_DRONES];
    int num_drones = 0;
    char command[MAX_COMMAND_LENGTH];
    char name[MAX_COMMAND_LENGTH];
    int dx, dy, dz;

    printf("Welcome to the drone remote control!\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter drone name: ");
            scanf("%s", name);
            add_drone(drones, num_drones, name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter drone name: ");
            scanf("%s", name);
            remove_drone(drones, num_drones, name);
        } else if (strcmp(command, "move") == 0) {
            printf("Enter drone name: ");
            scanf("%s", name);
            printf("Enter dx, dy, dz: ");
            scanf("%d %d %d", &dx, &dy, &dz);
            move_drone(drones, num_drones, name, dx, dy, dz);
        } else if (strcmp(command, "list") == 0) {
            list_drones(drones, num_drones);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}