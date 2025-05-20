//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5
#define SPEED 10

//Function to move the car
void moveCar(int direction, int speed) {
    printf("The car is moving %d at a speed of %d\n", direction, speed);
}

//Function to turn the car
void turnCar(int direction) {
    printf("The car is turning %d\n", direction);
}

//Function to stop the car
void stopCar() {
    printf("The car has stopped\n");
}

//Function to control the car
void controlCar(int action) {
    if(action == UP) {
        moveCar(UP, SPEED);
    }
    else if(action == DOWN) {
        moveCar(DOWN, SPEED);
    }
    else if(action == LEFT) {
        turnCar(LEFT);
    }
    else if(action == RIGHT) {
        turnCar(RIGHT);
    }
    else if(action == STOP) {
        stopCar();
    }
    else {
        printf("Invalid action\n");
    }
}

//Function to simulate the remote control
void simulateRemote() {
    int action;
    srand(time(NULL));
    action = rand() % 6;
    controlCar(action);
}

int main() {
    int choice;
    do {
        printf("Enter 1 to simulate the remote control\n");
        printf("Enter 2 to exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            simulateRemote();
        }
    } while(choice!= 2);
    return 0;
}