//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int battery_level; // in percentage
    int altitude; // in meters
    int x; // x position
    int y; // y position
} Drone;

void initialize_drone(Drone *drone) {
    drone->battery_level = 100;
    drone->altitude = 0;
    drone->x = 0;
    drone->y = 0;
    printf("Drone initialized. Battery level: %d%%, Position: (%d, %d), Altitude: %d m\n",
           drone->battery_level, drone->x, drone->y, drone->altitude);
}

void take_off(Drone *drone) {
    if (drone->battery_level <= 0) {
        printf("Error: Drone battery is empty! Please recharge.\n");
        return;
    }
    drone->altitude = 10; // Take off to 10 meters
    drone->battery_level -= 10; // Consumes battery
    printf("Drone took off. Current altitude: %d m, Battery level: %d%%\n",
           drone->altitude, drone->battery_level);
}

void land(Drone *drone) {
    if (drone->altitude <= 0) {
        printf("Drone is already on the ground.\n");
        return;
    }
    drone->altitude = 0; // Land the drone
    printf("Drone landed. Current altitude: %d m\n", drone->altitude);
}

void move(Drone *drone, int dx, int dy) {
    if (drone->altitude <= 0) {
        printf("Error: Drone must be in the air to move!\n");
        return;
    }
    drone->x += dx;
    drone->y += dy;
    drone->battery_level -= 5; // Consumes some battery
    printf("Drone moved to position (%d, %d). Battery level: %d%%\n",
           drone->x, drone->y, drone->battery_level);
}

void check_battery(Drone *drone) {
    printf("Current battery level: %d%%\n", drone->battery_level);
}

int main() {
    Drone myDrone;
    initialize_drone(&myDrone);

    char command[20];
    int dx, dy;

    while (1) {
        printf("Enter command (takeoff, land, move <dx> <dy>, battery, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "takeoff") == 0) {
            take_off(&myDrone);
        } else if (strcmp(command, "land") == 0) {
            land(&myDrone);
        } else if (sscanf(command, "move %d %d", &dx, &dy) == 2) {
            move(&myDrone, dx, dy);
        } else if (strcmp(command, "battery") == 0) {
            check_battery(&myDrone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the drone control program.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }

        if (myDrone.battery_level <= 0) {
            printf("Drone battery is empty! The drone will land.\n");
            land(&myDrone);
            break;
        }
    }

    return 0;
}