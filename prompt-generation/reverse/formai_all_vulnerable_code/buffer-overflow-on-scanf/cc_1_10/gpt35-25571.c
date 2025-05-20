//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MIN_SPEED 0
#define MAX_SPEED 100
#define DEFAULT_SPEED 50
#define MIN_ALTITUDE 0
#define MAX_ALTITUDE 1000
#define DEFAULT_ALTITUDE 500

// Function prototypes
void print_menu();
void change_speed(int* speed);
void change_altitude(int* altitude);
void takeoff(int speed, int altitude);
void land();

// Main function
int main() {
    int speed = DEFAULT_SPEED;
    int altitude = DEFAULT_ALTITUDE;
    int selected_option = 0;
    printf("Welcome to the C Drone Remote Control program!\n");

    // Loop until user selects option 4 to exit
    while (selected_option != 4) {
        print_menu();
        scanf("%d", &selected_option);
        switch (selected_option) {
            case 1:
                change_speed(&speed);
                break;
            case 2:
                change_altitude(&altitude);
                break;
            case 3:
                takeoff(speed, altitude);
                break;
            case 4:
                land();
                printf("Exiting program...");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to print menu of options
void print_menu() {
    printf("\nSelect an option:\n");
    printf("1. Change speed (0-100)\n");
    printf("2. Change altitude (0-1000)\n");
    printf("3. Takeoff (current speed: %d, current altitude: %d)\n", DEFAULT_SPEED, DEFAULT_ALTITUDE);
    printf("4. Land\n");
}

// Function to change speed
void change_speed(int* speed) {
    int new_speed = 0;
    printf("Enter new speed (0-100): ");
    scanf("%d", &new_speed);
    if (new_speed >= MIN_SPEED && new_speed <= MAX_SPEED) {
        *speed = new_speed;
    } else {
        printf("Invalid speed, please try again.\n");
    }
}

// Function to change altitude
void change_altitude(int* altitude) {
    int new_altitude = 0;
    printf("Enter new altitude (0-1000): ");
    scanf("%d", &new_altitude);
    if (new_altitude >= MIN_ALTITUDE && new_altitude <= MAX_ALTITUDE) {
        *altitude = new_altitude;
    } else {
        printf("Invalid altitude, please try again.\n");
    }
}

// Function to takeoff
void takeoff(int speed, int altitude) {
    printf("Taking off with speed %d and altitude %d...\n", speed, altitude);
    // Code for controlling the drone to takeoff
}

// Function to land
void land() {
    printf("Landing...\n");
    // Code for controlling the drone to land
}