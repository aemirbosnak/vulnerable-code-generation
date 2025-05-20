//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ALTITUDE 100
#define MIN_ALTITUDE 0
#define MAX_SPEED 10
#define MIN_SPEED 0

typedef struct {
    int altitude;
    int speed;
    char direction[10];
    int is_flying;
} Drone;

void initialize_drone(Drone *drone) {
    drone->altitude = MIN_ALTITUDE;
    drone->speed = MIN_SPEED;
    strcpy(drone->direction, "hover");
    drone->is_flying = 0;
}

void take_off(Drone *drone, int altitude) {
    if (altitude < MIN_ALTITUDE || altitude > MAX_ALTITUDE) {
        printf("Altitude must be between %d and %d meters.\n", MIN_ALTITUDE, MAX_ALTITUDE);
        return;
    }
    drone->altitude = altitude;
    drone->is_flying = 1;
    printf("Drone took off to %d meters.\n", drone->altitude);
}

void land(Drone *drone) {
    if (drone->is_flying) {
        drone->altitude = MIN_ALTITUDE;
        drone->is_flying = 0;
        printf("Drone landed safely.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void change_speed(Drone *drone, int speed) {
    if (speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Speed must be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
        return;
    }
    drone->speed = speed;
    printf("Drone speed set to %d.\n", drone->speed);
}

void change_direction(Drone *drone, const char *direction) {
    if (strcmp(direction, "forward") == 0 || strcmp(direction, "backward") == 0 || 
        strcmp(direction, "left") == 0 || strcmp(direction, "right") == 0) {
        strcpy(drone->direction, direction);
        printf("Drone direction set to %s.\n", drone->direction);
    } else {
        printf("Invalid direction. Use forward, backward, left, or right.\n");
    }
}

void display_status(const Drone *drone) {
    printf("Drone Status:\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %d\n", drone->speed);
    printf("Direction: %s\n", drone->direction);
    printf("Flying: %s\n", drone->is_flying ? "Yes" : "No");
}

void drone_control(Drone *drone) {
    char command[50];
    while (1) {
        printf("\nEnter a command (takeoff, land, speed, direction, status, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "takeoff") == 0) {
            int altitude;
            printf("Enter desired altitude (0-100 meters): ");
            scanf("%d", &altitude);
            take_off(drone, altitude);
        } 
        else if (strcmp(command, "land") == 0) {
            land(drone);
        } 
        else if (strcmp(command, "speed") == 0) {
            int speed;
            printf("Enter desired speed (0-10): ");
            scanf("%d", &speed);
            change_speed(drone, speed);
        } 
        else if (strcmp(command, "direction") == 0) {
            char direction[10];
            printf("Enter direction (forward, backward, left, right): ");
            scanf("%s", direction);
            change_direction(drone, direction);
        } 
        else if (strcmp(command, "status") == 0) {
            display_status(drone);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting control interface.\n");
            break;
        } 
        else {
            printf("Unknown command! Try again.\n");
        }
    }
}

int main() {
    Drone my_drone;
    initialize_drone(&my_drone);
    drone_control(&my_drone);
    return 0;
}