//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x, y, z; // Drone coordinates
    float speed;   // Drone speed
} Drone;

void initializeDrone(Drone *drone) {
    drone->x = 0.0;
    drone->y = 0.0;
    drone->z = 0.0;
    drone->speed = 1.0; // Set default speed
}

void moveDrone(Drone *drone, const char *direction) {
    if (strcmp(direction, "up") == 0) {
        drone->z += drone->speed;
    } else if (strcmp(direction, "down") == 0) {
        drone->z -= drone->speed;
    } else if (strcmp(direction, "left") == 0) {
        drone->x -= drone->speed;
    } else if (strcmp(direction, "right") == 0) {
        drone->x += drone->speed;
    } else if (strcmp(direction, "forward") == 0) {
        drone->y += drone->speed;
    } else if (strcmp(direction, "backward") == 0) {
        drone->y -= drone->speed;
    } else {
        printf("Invalid direction!\n");
    }
}

void reportStatus(const Drone *drone) {
    printf("Drone Status:\n");
    printf("Position: (%.2f, %.2f, %.2f)\n", drone->x, drone->y, drone->z);
    printf("Speed: %.2f\n", drone->speed);
}

void changeSpeed(Drone *drone, float newSpeed) {
    if (newSpeed > 0) {
        drone->speed = newSpeed;
        printf("Speed changed to %.2f\n", drone->speed);
    } else {
        printf("Speed must be positive!\n");
    }
}

void showHelp() {
    printf("Available commands:\n");
    printf("1. move [up, down, left, right, forward, backward]\n");
    printf("2. status\n");
    printf("3. speed [new_speed]\n");
    printf("4. help\n");
    printf("5. exit\n");
}

int main() {
    Drone drone;
    initializeDrone(&drone);

    char command[100];
    char direction[20];
    float newSpeed;

    printf("Drone Remote Control Initialized.\n");
    showHelp();

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "move %s", direction) == 1) {
            moveDrone(&drone, direction);
        } else if (strcmp(command, "status\n") == 0) {
            reportStatus(&drone);
        } else if (sscanf(command, "speed %f", &newSpeed) == 1) {
            changeSpeed(&drone, newSpeed);
        } else if (strcmp(command, "help\n") == 0) {
            showHelp();
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting Drone Remote Control. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Type 'help' for list of commands.\n");
        }
    }

    return 0;
}