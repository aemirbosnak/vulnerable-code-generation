//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
    OFF,
    ON,
} DroneState;

typedef struct {
    DroneState state;
    float altitude;
    float direction; // Degrees from North
} Drone;

void takeoff(Drone *drone) {
    if (drone->state == OFF) {
        drone->state = ON;
        drone->altitude = 10.0; // let's say it takes off to 10 meters
        drone->direction = 0.0;  // facing North
        printf("Drone taking off! Altitude: %.2f meters\n", drone->altitude);
    } else {
        printf("Drone is already in the air.\n");
    }
}

void land(Drone *drone) {
    if (drone->state == ON) {
        drone->state = OFF;
        drone->altitude = 0.0;
        printf("Drone landing. Altitude: %.2f meters\n", drone->altitude);
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void fly(Drone *drone, float distance, float direction) {
    if (drone->state == ON) {
        drone->direction = direction;
        printf("Drone flying %.2f meters to the %s.\n", distance, (direction == 0.0 ? "North" : (direction == 90.0 ? "East" : (direction == 180.0 ? "South" : "West"))));
    } else {
        printf("Please take off the drone first.\n");
    }
}

void capture_photo() {
    printf("Photo captured!\n");
}

void display_menu() {
    printf("\nDrone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Fly\n");
    printf("4. Capture Photo\n");
    printf("5. Exit\n");
}

int main() {
    Drone drone = { OFF, 0.0, 0.0 };
    int choice;
    float distance, direction;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeoff(&drone);
                break;
            case 2:
                land(&drone);
                break;
            case 3:
                printf("Enter distance (in meters): ");
                scanf("%f", &distance);
                printf("Enter direction (0=N, 90=E, 180=S, 270=W): ");
                scanf("%f", &direction);
                fly(&drone, distance, direction);
                break;
            case 4:
                if (drone.state == ON) {
                    capture_photo();
                } else {
                    printf("Drone is not in the air. Take off first.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}