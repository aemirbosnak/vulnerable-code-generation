//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define constants */
#define MAX_SPEED 100
#define MAX_ANGLE 90
#define MAX_DISTANCE 1000

/* Define typedef for vehicle struct */
typedef struct vehicle {
    int speed;
    int angle;
    int distance;
    bool isTurnedOn;
} Vehicle;

/* Define function prototypes */
void printInstructions();
void printVehicle(Vehicle* v);
void accelerate(Vehicle* v, int speed);
void decelerate(Vehicle* v, int speed);
void turnLeft(Vehicle* v, int angle);
void turnRight(Vehicle* v, int angle);
void moveForward(Vehicle* v, int distance);

int main() {
    /* Initialize vehicle */
    Vehicle myVehicle;
    myVehicle.speed = 0;
    myVehicle.angle = 0;
    myVehicle.distance = 0;
    myVehicle.isTurnedOn = false;

    /* Print instructions */
    printInstructions();

    /* Prompt user for input */
    while (true) {
        printf("Enter a command (1-6): ");
        int command;
        scanf("%d", &command);

        /* Execute command based on user input */
        switch (command) {
            case 1:
                accelerate(&myVehicle, MAX_SPEED);
                break;
            case 2:
                decelerate(&myVehicle, MAX_SPEED);
                break;
            case 3:
                turnLeft(&myVehicle, MAX_ANGLE);
                break;
            case 4:
                turnRight(&myVehicle, MAX_ANGLE);
                break;
            case 5:
                moveForward(&myVehicle, MAX_DISTANCE);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid command.\n");
                break;
        }

        /* Print updated vehicle information */
        printVehicle(&myVehicle);
    }

    /* Exit program */
    return 0;
}

/* Function to print instructions */
void printInstructions() {
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Use the following commands to control the vehicle:\n");
    printf("1. Accelerate (max speed: %d mph)\n", MAX_SPEED);
    printf("2. Decelerate\n");
    printf("3. Turn left (max angle: %d degrees)\n", MAX_ANGLE);
    printf("4. Turn right\n");
    printf("5. Move forward (max distance: %d miles)\n", MAX_DISTANCE);
    printf("6. Exit simulator\n");
}

/* Function to print vehicle information */
void printVehicle(Vehicle* v) {
    printf("Current vehicle information:\n");
    printf("Speed: %d mph\n", v->speed);
    printf("Angle: %d degrees\n", v->angle);
    printf("Distance: %d miles\n", v->distance);
    printf("Ignition: %s\n", v->isTurnedOn ? "on" : "off");
}

/* Function to accelerate */
void accelerate(Vehicle* v, int speed) {
    if (v->isTurnedOn && v->speed + speed <= MAX_SPEED) {
        v->speed += speed;
    } else {
        printf("Cannot accelerate.\n");
    }
}

/* Function to decelerate */
void decelerate(Vehicle* v, int speed) {
    if (v->isTurnedOn && v->speed - speed >= 0) {
        v->speed -= speed;
    } else {
        printf("Cannot decelerate.\n");
    }
}

/* Function to turn left */
void turnLeft(Vehicle* v, int angle) {
    if (v->isTurnedOn) {
        v->angle -= angle;
        if (v->angle < -180) {
            v->angle += 360;
        } else if (v->angle > 180) {
            v->angle -= 360;
        }
    } else {
        printf("Cannot turn left.\n");
    }
}

/* Function to turn right */
void turnRight(Vehicle* v, int angle) {
    if (v->isTurnedOn) {
        v->angle += angle;
        if (v->angle < -180) {
            v->angle += 360;
        } else if (v->angle > 180) {
            v->angle -= 360;
        }
    } else {
        printf("Cannot turn right.\n");
    }
}

/* Function to move forward */
void moveForward(Vehicle* v, int distance) {
    if (v->isTurnedOn) {
        v->distance += distance;
    } else {
        printf("Cannot move forward.\n");
    }
}