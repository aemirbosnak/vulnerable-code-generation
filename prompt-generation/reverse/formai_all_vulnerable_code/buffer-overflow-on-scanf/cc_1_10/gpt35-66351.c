//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Defining functions for forward, backward, left and right movements of the remote control vehicle.
void forward(int dist){
    printf("Moving Forward %d meters\n",dist);
}

void backward(int dist){
    printf("Moving Backward %d meters\n",dist);
}

void left(int angle){
    printf("Turning Left %d degrees\n",angle);
}

void right(int angle){
    printf("Turning Right %d degrees\n",angle);
}

int main(){
    int choice, distance, angle, i, j, k;

    printf("Welcome to Remote Control Vehicle Simulation Program!\n");
    printf("------------------------------------------------------\n");
    printf("Enter the number corresponding to the action you wish to perform:\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Exit Program\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the distance to be moved forward (in meters): ");
                scanf("%d",&distance);
                forward(distance);
                break;

            case 2:
                printf("\nEnter the distance to be moved backward (in meters): ");
                scanf("%d",&distance);
                backward(distance);
                break;

            case 3:
                printf("\nEnter the angle to turn left (in degrees): ");
                scanf("%d",&angle);
                left(angle);
                break;

            case 4:
                printf("\nEnter the angle to turn right (in degrees): ");
                scanf("%d",&angle);
                right(angle);
                break;

            case 5:
                printf("\nProgram Exiting...");
                exit(0);

            default:
                printf("\nInvalid Choice. Please Try Again.\n");
        }

        // Printing line of asterisks for visual separation
        for(i = 0;i < 40;i++){
            printf("*");
        }
        
        // Printing blank lines for better visual separation
        for(j = 0;j < 2;j++){
            printf("\n");
        }

        // Printing a mock view of the vehicle's location in a grid-like format.
        printf("Remote Control Vehicle Location:\n");
        for(k = 0;k < 10;k++){
            printf("|");
            if(k == 0 || k == 9){
                printf("\t#\t|\n");
            }
            else{
                printf("\t\t|\n");
            }
        }

        // Printing blank lines for better visual separation
        for(j = 0;j < 2;j++){
            printf("\n");
        }
        
        // Printing line of asterisks for visual separation
        for(i = 0;i < 40;i++){
            printf("*");
        }
    }
    return 0;
}