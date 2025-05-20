//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the directions the car can move in
enum Direction { FORWARD, BACKWARD, LEFT, RIGHT };

// Define the car's state
struct Car {
    int x;  // Car's X coordinate
    int y;  // Car's Y coordinate
    int direction;  // Car's current direction
};

// Function to initialize the car's state
void initCar(struct Car *car) {
    car->x = 0;
    car->y = 0;
    car->direction = FORWARD;
}

// Function to move the car in the specified direction
void moveCar(struct Car *car, enum Direction direction) {
    switch (direction) {
        case FORWARD:
            car->y++;
            break;
        case BACKWARD:
            car->y--;
            break;
        case LEFT:
            car->x--;
            break;
        case RIGHT:
            car->x++;
            break;
    }
}

// Function to print the car's current state
void printCar(struct Car *car) {
    printf("Car is at (%d, %d) facing %s\n", car->x, car->y, car->direction == FORWARD ? "forward" : car->direction == BACKWARD ? "backward" : car->direction == LEFT ? "left" : "right");
}

// Main function to simulate the car's movement
int main() {
    // Initialize the car
    struct Car car;
    initCar(&car);

    // Get the user's input for the car's movement
    char input[10];
    printf("Enter a direction (forward, backward, left, right): ");
    scanf("%s", input);

    // Convert the user's input to a direction enum
    enum Direction direction;
    if (strcmp(input, "forward") == 0) {
        direction = FORWARD;
    } else if (strcmp(input, "backward") == 0) {
        direction = BACKWARD;
    } else if (strcmp(input, "left") == 0) {
        direction = LEFT;
    } else if (strcmp(input, "right") == 0) {
        direction = RIGHT;
    } else {
        printf("Invalid direction entered.\n");
        return -1;
    }

    // Move the car in the specified direction
    moveCar(&car, direction);

    // Print the car's new state
    printCar(&car);

    return 0;
}