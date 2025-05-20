//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 256
#define DRONE_STATUS_OK 0
#define DRONE_STATUS_ERROR -1

typedef struct {
    float altitude;
    float speed;
    float latitude;
    float longitude;
    char status[20];
} Drone;

void initialize_drone(Drone* drone) {
    drone->altitude = 0.0;
    drone->speed = 0.0;
    drone->latitude = 0.0;
    drone->longitude = 0.0;
    strcpy(drone->status, "Idle");
}

void print_drone_status(const Drone* drone) {
    printf("Drone Status:\n");
    printf("Altitude: %.2f m\n", drone->altitude);
    printf("Speed: %.2f m/s\n", drone->speed);
    printf("Latitude: %.6f\n", drone->latitude);
    printf("Longitude: %.6f\n", drone->longitude);
    printf("Status: %s\n", drone->status);
}

void take_off(Drone* drone) {
    strcpy(drone->status, "Flying");
    drone->altitude = 100.0;
    drone->speed = 10.0;
    printf("Drone is taking off...\n");
}

void land_drone(Drone* drone) {
    if (drone->altitude > 0) {
        strcpy(drone->status, "Landing");
        while (drone->altitude > 0) {
            drone->altitude -= 10.0; // Decrease altitude
            sleep(1);
            printf("Landing... Current altitude: %.2f m\n", drone->altitude);
        }
        strcpy(drone->status, "Idle");
        drone->speed = 0.0;
        printf("Drone has landed.\n");
    }
}

void move_drone(Drone* drone, float latitude_change, float longitude_change) {
    if (strcmp(drone->status, "Flying") == 0) {
        drone->latitude += latitude_change;
        drone->longitude += longitude_change;
        printf("Drone moving to Latitude: %.6f, Longitude: %.6f\n", drone->latitude, drone->longitude);
    } else {
        printf("Drone is not flying. Please take off first.\n");
    }
}

void change_speed(Drone* drone, float new_speed) {
    if (new_speed >= 0) {
        drone->speed = new_speed;
        printf("Drone speed set to: %.2f m/s\n", drone->speed);
    } else {
        printf("Speed cannot be negative.\n");
    }
}

void signal_handler(int signal) {
    printf("\nExiting drone control program. Goodbye!\n");
    exit(0);
}

int main() {
    // Registering the signal handler for graceful exit
    signal(SIGINT, signal_handler);
    
    Drone my_drone;
    initialize_drone(&my_drone);

    char command[MAX_COMMAND_LENGTH];
    float latitude_change, longitude_change, new_speed;

    printf("Welcome to the Drone Remote Control Program.\n");
    printf("Commands: takeoff, land, move <lat_change> <long_change>, speed <new_speed>, status, exit\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "takeoff") == 0) {
            take_off(&my_drone);
        } else if (strcmp(command, "land") == 0) {
            land_drone(&my_drone);
        } else if (sscanf(command, "move %f %f", &latitude_change, &longitude_change) == 2) {
            move_drone(&my_drone, latitude_change, longitude_change);
        } else if (sscanf(command, "speed %f", &new_speed) == 1) {
            change_speed(&my_drone, new_speed);
        } else if (strcmp(command, "status") == 0) {
            print_drone_status(&my_drone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return DRONE_STATUS_OK;
}