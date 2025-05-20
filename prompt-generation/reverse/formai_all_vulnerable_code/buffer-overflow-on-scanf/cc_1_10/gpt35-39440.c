//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPEED 50

struct Vehicle {
    char *name;
    int speed;
    int direction;
    bool powerOn;
}; // structure for the vehicle

void displayInstructions() {
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Here are your options:\n");
    printf("P - Power On/Off\n");
    printf("S - Increase Speed\n");
    printf("B - Decrease Speed\n");
    printf("D - Turn Right\n");
    printf("A - Turn Left\n");
    printf("Q - Quit\n");
}

void displayVehicle(struct Vehicle *v) {
    printf("\nCurrent Status of %s:\n", v->name);
    printf("Speed: %d\n", v->speed);
    printf("Direction: %d degrees\n", v->direction);
    printf("Power Status: %s\n", v->powerOn ? "ON" : "OFF");
}

void powerOnOff(struct Vehicle *v) {
    if (v->powerOn) {
        v->powerOn = false;
        v->speed = 0;
        v->direction = 0;
        printf("%s has been turned off.\n", v->name);
    } else {
        v->powerOn = true;
        v->speed = 0;
        v->direction = 0;
        printf("%s has been turned on.\n", v->name);
    }
}

void increaseSpeed(struct Vehicle *v) {
    if (!v->powerOn) {
        printf("Cannot increase speed - Vehicle is turned off.\n");
    } else if (v->speed == MAX_SPEED) {
        printf("Cannot increase speed - Vehicle is at maximum speed.\n");
    } else {
        v->speed += 10;
        printf("Speed increased to %d.\n", v->speed);
    }
}

void decreaseSpeed(struct Vehicle *v) {
    if (!v->powerOn) {
        printf("Cannot decrease speed - Vehicle is turned off.\n");
    } else if (v->speed == 0) {
        printf("Cannot decrease speed - Vehicle is at minimum speed.\n");
    } else {
        v->speed -= 10;
        printf("Speed decreased to %d.\n", v->speed);
    }
}

void turnLeft(struct Vehicle *v) {
    if (!v->powerOn) {
        printf("Cannot turn left - Vehicle is turned off.\n");
    } else {
        v->direction -= 15;
        printf("Vehicle turned left to %d degrees.\n", v->direction);
    }
}

void turnRight(struct Vehicle *v) {
    if (!v->powerOn) {
        printf("Cannot turn right - Vehicle is turned off.\n");
    } else {
        v->direction += 15;
        printf("Vehicle turned right to %d degrees.\n", v->direction);
    }
}

int main() {
    struct Vehicle car;
    car.name = "Remote Control Car";
    car.powerOn = false;
    
    displayInstructions();
    char choice;
    
    while (true) {
        printf("\nEnter Command: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'P':
                powerOnOff(&car);
                break;
            case 'S':
                increaseSpeed(&car);
                break;
            case 'B':
                decreaseSpeed(&car);
                break;
            case 'A':
                turnLeft(&car);
                break;
            case 'D':
                turnRight(&car);
                break;
            case 'Q':
                printf("Shutting down the Remote Control Vehicle Simulation. Goodbye!");
                return 0;
            default:
                printf("Invalid command. Please try again.");
                break;  
        }
        displayVehicle(&car);
    }
    return 0;
}