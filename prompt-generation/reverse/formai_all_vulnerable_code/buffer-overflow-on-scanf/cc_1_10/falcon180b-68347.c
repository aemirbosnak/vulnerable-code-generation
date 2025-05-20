//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Function to move the vehicle
void moveVehicle(int direction){
    if(direction == UP){
        printf("Vehicle is moving forward.\n");
    }
    else if(direction == DOWN){
        printf("Vehicle is moving backward.\n");
    }
    else if(direction == LEFT){
        printf("Vehicle is turning left.\n");
    }
    else if(direction == RIGHT){
        printf("Vehicle is turning right.\n");
    }
    else if(direction == STOP){
        printf("Vehicle has stopped.\n");
    }
}

// Function to change the speed of the vehicle
void changeSpeed(int speed){
    if(speed == 1){
        printf("Vehicle speed is slow.\n");
    }
    else if(speed == 2){
        printf("Vehicle speed is medium.\n");
    }
    else if(speed == 3){
        printf("Vehicle speed is fast.\n");
    }
}

// Function to change the direction of the vehicle
void changeDirection(int direction){
    if(direction == 1){
        printf("Vehicle is moving forward.\n");
    }
    else if(direction == 2){
        printf("Vehicle is moving backward.\n");
    }
    else if(direction == 3){
        printf("Vehicle is turning left.\n");
    }
    else if(direction == 4){
        printf("Vehicle is turning right.\n");
    }
}

int main(){
    int choice, speed = 1, direction = 1;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move the vehicle\n");
    printf("2. Change the speed of the vehicle\n");
    printf("3. Change the direction of the vehicle\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the direction (1-4): ");
            scanf("%d", &direction);
            moveVehicle(direction);
            break;
        case 2:
            printf("Enter the speed (1-3): ");
            scanf("%d", &speed);
            changeSpeed(speed);
            break;
        case 3:
            printf("Enter the direction (1-4): ");
            scanf("%d", &direction);
            changeDirection(direction);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}