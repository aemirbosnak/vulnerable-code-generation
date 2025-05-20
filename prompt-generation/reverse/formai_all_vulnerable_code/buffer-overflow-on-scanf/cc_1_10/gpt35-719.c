//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 50

typedef struct {
    int position;
    int speed;
    bool isMoving;
} RemoteVehicle;

void moveVehicle(RemoteVehicle* vehicle) {
    if(vehicle->isMoving) {
        vehicle->position += vehicle->speed;
    }
}

void adjustSpeed(RemoteVehicle* vehicle, int speed) {
    if(speed < 0) {
        speed = 0;
    } else if(speed > MAX_SPEED) {
        speed = MAX_SPEED;
    }
    
    vehicle->speed = speed;
}

int main() {
    RemoteVehicle car = {0, 0, false};
    int userSpeed;
    char userChoice;
    
    printf("Welcome to the Remote Control Vehicle Simulation\n");
    printf("------------------------------------------------\n");
    
    do {
        printf("Current Position: %d\n", car.position);
        printf("Current Speed: %d\n", car.speed);
        printf("Is the vehicle moving? %s\n", car.isMoving ? "Yes" : "No");
        
        printf("\nWhat would you like to do?\n");
        printf("a. Turn the vehicle on/off\n");
        printf("b. Adjust the speed\n");
        printf("c. Move the vehicle\n");
        printf("q. Quit the program\n");
        
        scanf(" %c", &userChoice);
        
        switch(userChoice) {
            case 'a':
                car.isMoving = !car.isMoving;
                break;
            case 'b':
                printf("Enter speed (0-50): ");
                scanf("%d", &userSpeed);
                adjustSpeed(&car, userSpeed);
                break;
            case 'c':
                if(!car.isMoving) {
                    printf("The vehicle is currently turned off.\n");
                } else {
                    moveVehicle(&car);
                    printf("The vehicle has moved to position %d\n", car.position);
                }
                break;
            case 'q':
                printf("Thank you for using the Remote Control Vehicle Simulation!\n");
                break;
            default:
                printf("Invalid choice. Please select a, b, c, or q.\n");
        }
        
        printf("\n");
        
    } while(userChoice != 'q');
    
    return 0;
}