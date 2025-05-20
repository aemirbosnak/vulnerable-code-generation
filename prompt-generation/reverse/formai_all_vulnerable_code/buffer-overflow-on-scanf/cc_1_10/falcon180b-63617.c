//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void move_forward(int speed);
void turn_left(int angle);
void turn_right(int angle);
void stop_vehicle();
void main_menu();

// Global variables
int speed = 0;
int angle = 0;
int choice;

int main() {
    srand(time(0)); // Seed the random number generator

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("You are Sherlock Holmes, controlling your vehicle through the streets of London.\n");
    printf("Use the following commands to navigate:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop vehicle\n");

    while (1) {
        main_menu();

        switch (choice) {
            case 1:
                printf("Moving forward...\n");
                move_forward(speed);
                break;
            case 2:
                printf("Turning left...\n");
                turn_left(angle);
                break;
            case 3:
                printf("Turning right...\n");
                turn_right(angle);
                break;
            case 4:
                printf("Stopping vehicle...\n");
                stop_vehicle();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void move_forward(int speed) {
    printf("The vehicle moves forward at a speed of %d...\n", speed);
}

void turn_left(int angle) {
    printf("The vehicle turns left by an angle of %d degrees...\n", angle);
}

void turn_right(int angle) {
    printf("The vehicle turns right by an angle of %d degrees...\n", angle);
}

void stop_vehicle() {
    printf("The vehicle comes to a stop...\n");
}

void main_menu() {
    printf("\nMain Menu:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop vehicle\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
}