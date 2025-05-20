//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int batteryLife = 100;
    int signalStrength = 50;
    int distance = 0;
    int speed = 0;
    int direction = 0;
    int switchState = 0;
    int isMoving = 0;

    printf("Welcome to the Surrealist Remote Control Vehicle Simulation!\n\n");
    printf("The battery life is at %d%% and the signal strength is at %d%%.\n", batteryLife, signalStrength);
    printf("The vehicle is currently located %d meters from your position and is not moving.\n\n", distance);

    while (batteryLife > 0) {
        printf("Enter an action to control the vehicle (1 = forward, 2 = reverse, 3 = left, 4 = right, 5 = stop): ");
        scanf("%d", &switchState);

        if (switchState == 5) {
            isMoving = 0;
            speed = 0;
            printf("The vehicle has stopped.\n\n");
        } else {
            isMoving = 1;
            speed = (rand() % 10) + 1;
            printf("The vehicle is now moving at %d m/s.\n\n", speed);
        }

        switch(direction) {
            case 0:
                distance += speed;
                printf("The vehicle has moved %d meters forward.\n", distance);
                break;
            case 1:
                distance -= speed;
                printf("The vehicle has moved %d meters backward.\n", distance);
                break;
            case 2:
                printf("The vehicle is turning left.\n");
                break;
            case 3:
                printf("The vehicle is turning right.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        batteryLife -= 10;
        signalStrength -= 5;

        printf("\nThe battery life is now at %d%% and the signal strength is at %d%%.\n", batteryLife, signalStrength);
        printf("The vehicle is currently located %d meters from your position.\n", distance);
        printf("**************************************************\n\n");
    }

    printf("Battery life is at 0%%. Vehicle is out of battery and can no longer function.\n");
    return 0;
}