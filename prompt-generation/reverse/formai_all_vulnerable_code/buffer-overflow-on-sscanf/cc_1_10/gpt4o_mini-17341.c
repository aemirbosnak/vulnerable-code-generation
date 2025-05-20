//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 100

typedef enum {
    STOPPED,
    MOVING_FORWARD,
    MOVING_BACKWARD
} VehicleState;

typedef struct {
    VehicleState state;
    int speed; // Speed in km/h
} RemoteControlVehicle;

void initializeVehicle(RemoteControlVehicle *vehicle) {
    vehicle->state = STOPPED;
    vehicle->speed = 0;
}

void displayVehicleStatus(RemoteControlVehicle *vehicle) {
    const char *stateStr = (vehicle->state == STOPPED) ? "STOPPED"
                            : (vehicle->state == MOVING_FORWARD) ? "MOVING FORWARD"
                            : "MOVING BACKWARD";
    printf("Vehicle Status: %s | Speed: %d km/h\n", stateStr, vehicle->speed);
}

void startMovingForward(RemoteControlVehicle *vehicle, int speed) {
    if (speed < 0) {
        printf("Speed must be non-negative.\n");
        return;
    }
    vehicle->state = MOVING_FORWARD;
    vehicle->speed = speed;
    printf("Vehicle started moving forward at %d km/h.\n", speed);
}

void startMovingBackward(RemoteControlVehicle *vehicle, int speed) {
    if (speed < 0) {
        printf("Speed must be non-negative.\n");
        return;
    }
    vehicle->state = MOVING_BACKWARD;
    vehicle->speed = speed;
    printf("Vehicle started moving backward at %d km/h.\n", speed);
}

void stopVehicle(RemoteControlVehicle *vehicle) {
    vehicle->state = STOPPED;
    vehicle->speed = 0;
    printf("Vehicle has stopped.\n");
}

void changeSpeed(RemoteControlVehicle *vehicle, int speed) {
    if (speed < 0) {
        printf("Speed must be non-negative.\n");
        return;
    }
    if (vehicle->state == STOPPED) {
        printf("Vehicle is stopped, please start moving before adjusting speed.\n");
    } else {
        vehicle->speed = speed;
        printf("Vehicle speed adjusted to %d km/h.\n", speed);
    }
}

int main() {
    RemoteControlVehicle myVehicle;
    initializeVehicle(&myVehicle);

    char command[MAX_BUFFER_SIZE];
    int speed;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Commands: forward [speed], backward [speed], stop, status, exit\n");
    
    while (1) {
        printf("\nEnter command: ");
        fgets(command, MAX_BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation...\n");
            break;
        } else if (strcmp(command, "stop") == 0) {
            stopVehicle(&myVehicle);
        } else if (sscanf(command, "forward %d", &speed) == 1) {
            startMovingForward(&myVehicle, speed);
        } else if (sscanf(command, "backward %d", &speed) == 1) {
            startMovingBackward(&myVehicle, speed);
        } else if (strcmp(command, "status") == 0) {
            displayVehicleStatus(&myVehicle);
        } else if (sscanf(command, "speed %d", &speed) == 1) {
            changeSpeed(&myVehicle, speed);
        } else {
            printf("Invalid command. Please try again.\n");
        }
        
        // Simulate some time passing for vehicle state
        sleep(1);
    }

    return 0;
}