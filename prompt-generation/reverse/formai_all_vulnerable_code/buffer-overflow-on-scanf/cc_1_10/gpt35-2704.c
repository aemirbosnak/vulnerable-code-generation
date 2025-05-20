//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

// Data Structure for Remote Vehicle
typedef struct {
    int speed; // speed of vehicle
    int direction; // direction of vehicle (0-360 degrees)
} RemoteVehicle;

// Function to initialize the Remote Vehicle
void initRemoteVehicle(RemoteVehicle* rv) {
    rv->speed = 0; // set speed to 0
    rv->direction = 0; // set direction to 0
}

// Function that takes input from user and makes appropriate changes to Remote Vehicle
void operateRemoteVehicle(RemoteVehicle* rv) {
    int option;
    printf("Choose an option to operate Remote Vehicle:\n");
    printf("1: Increase speed\n");
    printf("2: Decrease speed\n");
    printf("3: Change direction\n");
    printf("4: Exit\n");
    scanf("%d", &option);

    switch(option) {
        case 1: rv->speed++; break;
        case 2: rv->speed--; break;
        case 3:
            printf("Enter direction (0-360 degrees):\n");
            scanf("%d", &rv->direction);
            break;
        case 4: exit(0);
        default: printf("Invalid option!\n");
    }
}

int main() {
    RemoteVehicle rv;
    initRemoteVehicle(&rv);

    while(1) {
        printf("Current Status:\n");
        printf("Speed: %d\n", rv.speed);
        printf("Direction: %d degrees\n\n", rv.direction);
        operateRemoteVehicle(&rv);
    }

    return 0;
}