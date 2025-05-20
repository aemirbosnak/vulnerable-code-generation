//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 50

// Define drone type
typedef struct {
    int battery_level;
    bool connected;
    int x_pos;
    int y_pos;
} drone;

// Define function to simulate battery drain
void drainBattery(drone *d) {
    if (d->battery_level > 0) {
        d->battery_level -= 10;
    } else {
        d->connected = false;
    }
}

// Define function to randomize drone position
void randomizePosition(drone *d) {
    srand(time(NULL));
    d->x_pos = rand() % 100;
    d->y_pos = rand() % 100;
}

// Define function to move drone
void moveDrone(drone *d, int x, int y) {
    if (d->battery_level > 0) {
        d->x_pos += x;
        d->y_pos += y;
        drainBattery(d);
    } else {
        printf("Drone is out of battery. Unable to move.\n");
    }
}

// Define function to connect drone
void connectDrone(drone *d) {
    d->connected = true;
    d->battery_level = 100;
    randomizePosition(d);
}

int main() {
    // Initialize drone
    drone d;
    d.battery_level = 0;
    d.connected = false;
    d.x_pos = 0;
    d.y_pos = 0;

    // Initialize input variables
    char command[MAX_COMMAND_LENGTH];
    int x, y;

    // Loop to receive user commands
    while (strcmp(command, "exit") != 0) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Parse input
        if (sscanf(command, "connect") == 1) {
            connectDrone(&d);
            printf("Drone connected.\n");
        } else if (sscanf(command, "move %d %d", &x, &y) == 2) {
            moveDrone(&d, x, y);
            printf("Drone moved to (%d,%d).\n", d.x_pos, d.y_pos);
        } else if (strcmp(command, "status") == 0) {
            printf("Drone status:\nBattery level: %d%%\nConnected: %s\nPosition: (%d,%d)\n", d.battery_level,
                   d.connected ? "yes" : "no", d.x_pos, d.y_pos);
        } else if (strcmp(command, "exit") != 0) {
            printf("Invalid command.\n");
        }
    }

    // End program
    printf("Program terminated.\n");
    return 0;
}