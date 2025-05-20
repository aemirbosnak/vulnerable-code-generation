//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

// Defining the structure of the Remote Control Vehicle
struct remote_control_vehicle{
    int speed;
    int direction;
    bool isMoving;
};

// Function to print the current state of the Vehicle
void printState(struct remote_control_vehicle *vehicle){
    printf("The Vehicle is currently ");
    if(!vehicle->isMoving){
        printf("stopped\n");
        return;
    }
    printf("moving ");
    if(vehicle->direction == 1){
        printf("forward ");
    }
    else{
        printf("backward ");
    }
    printf("at a speed of %d\n", vehicle->speed);
}

int main(){
    // Initializing the Vehicle
    struct remote_control_vehicle vehicle;
    vehicle.isMoving = false;
    vehicle.speed = 0;
    vehicle.direction = 1;

    // Instructions
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Press 'Q' to exit the program\n");
    printf("Press 'S' to stop the Vehicle\n");
    printf("Press 'F' to move the Vehicle forward\n");
    printf("Press 'B' to move the Vehicle backward\n");
    printf("Press 'U' to increase the speed of the Vehicle\n");
    printf("Press 'D' to decrease the speed of the Vehicle\n");
    printf("--------------------------------------------------\n");

    // Taking Inputs and Controlling the Vehicle
    char input = ' ';
    while(input != 'Q'){
        printf("Enter your choice: ");
        scanf(" %c", &input);
        input = toupper(input);

        switch(input){
            case 'S':
                vehicle.isMoving = false;
                vehicle.speed = 0;
                break;

            case 'F':
                vehicle.isMoving = true;
                vehicle.direction = 1;
                break;

            case 'B':
                vehicle.isMoving = true;
                vehicle.direction = -1;
                break;

            case 'U':
                if(vehicle.speed < 10){
                    vehicle.speed++;
                }
                break;

            case 'D':
                if(vehicle.speed > 0){
                    vehicle.speed--;
                }
                break;

            case 'Q':
                break;

            default:
                printf("Wrong input! Please enter again.\n");
                continue;
        }

        // Printing the current state of the Vehicle
        printState(&vehicle);
    }

    return 0;
}