//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_VEHICLES 3
#define NUM_COMMANDS 4

typedef struct {
    char name[20];
    int speed;
    int direction;
    bool isMoving;
} vehicle_t;

vehicle_t vehicles[NUM_VEHICLES] = {
    {"Car 1", 0, 0, false},
    {"Car 2", 0, 0, false},
    {"Car 3", 0, 0, false}
};

char commands[NUM_COMMANDS][20] = {"forward", "backward", "left", "right"};

void moveVehicle(vehicle_t* vehicle, int speed, int direction) {
    vehicle->speed = speed;
    vehicle->direction = direction;
    vehicle->isMoving = true;
}

void stopVehicle(vehicle_t* vehicle) {
    vehicle->isMoving = false;
}

void remoteControl(vehicle_t* vehicle, char* command) {
    int i;
    for (i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command, commands[i]) == 0) {
            moveVehicle(vehicle, 10, i * 90);
            printf("Vehicle %s is moving %s at %d degrees.\n", vehicle->name, command, i * 90);
            break;
        }
    }
}

void main() {
    srand(time(NULL));
    int choice;
    do {
        system("clear");
        printf("Remote Control Vehicle Simulation\n");
        printf("Enter a number to select a vehicle:\n");
        for (int i = 0; i < NUM_VEHICLES; i++) {
            printf("%d. %s\n", i + 1, vehicles[i].name);
        }
        scanf("%d", &choice);
        printf("You selected vehicle %s.\n", vehicles[choice - 1].name);
        while (true) {
            system("clear");
            printf("Enter a command (forward, backward, left, right):\n");
            scanf("%s", vehicles[choice - 1].name);
            remoteControl(&vehicles[choice - 1], vehicles[choice - 1].name);
            printf("Press any key to continue...\n");
            getchar();
        }
    } while (true);
}