//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ALTITUDE 100
#define MAX_DISTANCE 100

typedef struct {
    int altitude;
    int distance;
} Drone;

void take_off(Drone *drone) {
    if (drone->altitude == 0) {
        printf("Drone is taking off...\n");
        for (int i = 1; i <= MAX_ALTITUDE; i++) {
            sleep(1);
            drone->altitude = i;
            printf("Altitude: %d meters\n", drone->altitude);
        }
        printf("Drone has taken off to an altitude of %d meters.\n", drone->altitude);
    } else {
        printf("Drone is already in the air at %d meters.\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (drone->altitude > 0) {
        printf("Drone is landing...\n");
        for (int i = drone->altitude; i > 0; i--) {
            sleep(1);
            drone->altitude = i - 1;
            printf("Altitude: %d meters\n", drone->altitude);
        }
        printf("Drone has landed safely.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void move(Drone *drone, int distance) {
    if (drone->altitude > 0) {
        if (drone->distance + distance <= MAX_DISTANCE && drone->distance + distance >= 0) {
            printf("Drone is moving %d meters\n", distance);
            for (int i = 0; i < abs(distance); i++) {
                sleep(1);
                drone->distance += (distance > 0) ? 1 : -1;
                printf("Distance: %d meters\n", drone->distance);
            }
            printf("Drone has moved to a distance of %d meters.\n", drone->distance);
        } else {
            printf("Movement exceeds the maximum distance of %d meters.\n", MAX_DISTANCE);
        }
    } else {
        printf("Drone must be in the air to move.\n");
    }
}

void display_status(Drone *drone) {
    printf("Current Status of the Drone:\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Distance: %d meters\n", drone->distance);
}

void menu() {
    printf("Drone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward (positive distance)\n");
    printf("4. Move Backward (negative distance)\n");
    printf("5. Display Status\n");
    printf("6. Exit\n");
}

int main() {
    Drone drone = {0, 0}; // Initialize drone at ground level and distance 0
    int choice, distance;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                take_off(&drone);
                break;
            case 2:
                land(&drone);
                break;
            case 3:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                move(&drone, distance);
                break;
            case 4:
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                move(&drone, -distance);
                break;
            case 5:
                display_status(&drone);
                break;
            case 6:
                printf("Exiting the drone control program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}