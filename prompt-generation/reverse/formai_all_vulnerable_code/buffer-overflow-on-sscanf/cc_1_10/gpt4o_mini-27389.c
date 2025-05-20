//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    int battery_level;
    int altitude;
    char direction[10];
} Drone;

void initialize_drone(Drone *drone) {
    drone->battery_level = 100; // Battery percentage
    drone->altitude = 0; // Altitude in meters
    strcpy(drone->direction, "Hovering"); // Default direction
}

void takeoff(Drone *drone) {
    if (drone->battery_level <= 0) {
        printf("Battery too low to take off!\n");
        return;
    }
    drone->altitude = 10; // Take off to 10 meters
    drone->battery_level -= 10; // Consume battery
    printf("Drone has taken off to an altitude of %d meters.\n", drone->altitude);
}

void land(Drone *drone) {
    drone->altitude = 0; // Set altitude to zero
    printf("Drone has landed safely.\n");
}

void move(Drone *drone, const char *new_direction) {
    if (drone->altitude <= 0) {
        printf("Drone is not flying. Please take off first!\n");
        return;
    }
    strcpy(drone->direction, new_direction);
    drone->battery_level -= 5; // Consume battery for moving
    printf("Drone is now moving %s.\n", new_direction);
}

void check_battery(Drone *drone) {
    printf("Battery Level: %d%%\n", drone->battery_level);
}

void display_commands() {
    printf("\nAvailable Commands:\n");
    printf("1. TAKEOFF\n");
    printf("2. LAND\n");
    printf("3. MOVE [direction]\n");
    printf("4. CHECK BATTERY\n");
    printf("5. EXIT\n");
}

int main() {
    Drone drone;
    initialize_drone(&drone);
    
    char command[MAX_COMMAND_LENGTH];
    char direction[10];
    
    printf("Welcome to the Drone Remote Control System!\n");
    while (1) {
        display_commands();
        
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline
        
        if (strcmp(command, "TAKEOFF") == 0) {
            takeoff(&drone);
        }
        else if (strcmp(command, "LAND") == 0) {
            land(&drone);
        }
        else if (sscanf(command, "MOVE %s", direction) == 1) {
            move(&drone, direction);
        }
        else if (strcmp(command, "CHECK BATTERY") == 0) {
            check_battery(&drone);
        }
        else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting the Drone Remote Control System.\n");
            break;
        }
        else {
            printf("Invalid command! Please try again.\n");
        }
        sleep(1); // Simulate delay between commands
    }
    
    return 0;
}