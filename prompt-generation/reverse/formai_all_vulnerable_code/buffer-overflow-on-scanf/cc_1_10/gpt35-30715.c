//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to move the car forward
void moveForward(int *position){
    if(*position<500){
        *position = *position + 50;
        printf("\nMoving Forward. Current Position: %d\n", *position);
    }
    else{
        printf("\nCannot Move Forward. Reached the End.\n");
    }
}

// Function to move the car backward
void moveBackward(int *position){
    if(*position > 0){
        *position = *position - 50;
        printf("\nMoving Backward. Current Position: %d\n", *position);
    }
    else{
        printf("\nCannot Move Backward. Already at Starting Position.\n");
    }
}

// Function to turn the car left
void turnLeft(bool *isLeft){
    if(*isLeft){
        printf("\nCar is already facing Left.\n");
    }
    else{
        *isLeft = true;
        printf("\nTurning Left.\n");
    }
}

// Function to turn the car right
void turnRight(bool *isLeft){
    if(!(*isLeft)){
        printf("\nCar is already facing Right.\n");
    }
    else{
        *isLeft = false;
        printf("\nTurning Right.\n");
    }
}

// Function to stop the car
void stop(int *position, bool *isLeft){
    printf("\nStopping the car. Current Position: %d\tDirection: %s\n", *position, (*isLeft)? "Left" : "Right");
}

int main(){
    int position = 0;
    bool isLeft = false;

    printf("\n*** Remote Control Car Simulation ***\n");
    printf("\nStarting Position: %d\tDirection: %s\n", position, (isLeft)? "Left" : "Right");

    int choice = 0;
    while(choice != 5){
        printf("\nChoose an option:\n1. Move Forward\n2. Move Backward\n3. Turn Left\n4. Turn Right\n5. Stop\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                moveForward(&position);
                break;
            case 2:
                moveBackward(&position);
                break;
            case 3:
                turnLeft(&isLeft);
                break;
            case 4:
                turnRight(&isLeft);
                break;
            case 5:
                stop(&position, &isLeft);
                break;
            default:
                printf("\nInvalid Option. Try Again.\n");
        }
    }

    printf("\n*** Car Simulation Ended ***\n\n");
    return 0;
}