//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Define the RC vehicle structure
typedef struct {
    int x;
    int y;
    int direction;
} rc_vehicle;

//Function to move the RC vehicle forward or backwards
void move(rc_vehicle *vehicle, int distance) {
    //Get the current direction
    int dir = vehicle->direction;
    //Update the position based on the direction
    switch (dir) {
        case 0: //North
            vehicle->y += distance;
            break;
        case 1: //East
            vehicle->x += distance;
            break;
        case 2: //South
            vehicle->y -= distance;
            break;
        case 3: //West
            vehicle->x -= distance;
            break;
    }
    printf("Moved %d units in direction %d\n", distance, dir);
}

//Function to turn the RC vehicle left or right
void turn(rc_vehicle *vehicle, int degrees) {
    //Update the direction by the given degrees
    vehicle->direction = (vehicle->direction + degrees) % 4;
    printf("Turned %d degrees to face direction %d\n", degrees, vehicle->direction);
}

int main() {
    //Create an RC vehicle at position (0,0) facing North
    rc_vehicle my_vehicle = { 0, 0, 0 };

    //Display the initial position
    printf("Initial position: (%d,%d) facing direction %d\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    //Start main loop to take user input
    while (1) {
        //Get user input
        char input;
        printf("Enter command (F for forward, B for backward, L for left turn, R for right turn): ");
        scanf(" %c", &input);
        input = toupper(input);

        //Perform corresponding action based on user input
        switch (input) {
            case 'F':
                move(&my_vehicle, 1);
                break;
            case 'B':
                move(&my_vehicle, -1);
                break;
            case 'L':
                turn(&my_vehicle, -1);
                break;
            case 'R':
                turn(&my_vehicle, 1);
                break;
            default:
                printf("Invalid input, please try again.\n");
                continue;
        }

        //Display current position
        printf("Current position: (%d,%d) facing direction %d\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);
    }

    return 0;
}