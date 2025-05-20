//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Define the structure of a remote control vehicle
typedef struct {
    char name[20];
    int speed;
    int direction;
} Vehicle;

// Function to initialize a vehicle
void initVehicle(Vehicle* v) {
    strcpy(v->name, "Remote Control Vehicle");
    v->speed = 0;
    v->direction = STOP;
}

// Function to move a vehicle forward
void moveForward(Vehicle* v) {
    printf("Moving %s forward...\n", v->name);
}

// Function to turn a vehicle left
void turnLeft(Vehicle* v) {
    printf("Turning %s left...\n", v->name);
}

// Function to turn a vehicle right
void turnRight(Vehicle* v) {
    printf("Turning %s right...\n", v->name);
}

// Function to stop a vehicle
void stopVehicle(Vehicle* v) {
    printf("Stopping %s...\n", v->name);
}

// Function to simulate a remote control vehicle
void simulateVehicle(Vehicle* v) {
    int choice;

    while(1) {
        printf("\nWhat would you like to do with %s?\n", v->name);
        printf("1. Move forward\n2. Turn left\n3. Turn right\n4. Stop\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                moveForward(v);
                break;
            case 2:
                turnLeft(v);
                break;
            case 3:
                turnRight(v);
                break;
            case 4:
                stopVehicle(v);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
        sleep(1);
    }
}

int main() {
    srand(time(0));

    Vehicle v;
    initVehicle(&v);

    simulateVehicle(&v);

    return 0;
}