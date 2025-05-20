//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the C Drone Remote Control System\n\n");

    int battery_life = 100;

    while(battery_life > 0){
        printf("Enter command (0-9): \n");
        int command;
        scanf("%d", &command);
        if(command == 0){
            printf("\nDrone is landing...\n");
            break;
        }
        if(command == 1){
            printf("\nDrone is taking off...\n");
            continue;
        }
        if(command == 2){
            printf("\nDrone is moving forward...\n");
        }
        if(command == 3){
            printf("\nDrone is moving backward...\n");
        }
        if(command == 4){
            printf("\nDrone is moving left...\n");
        }
        if(command == 5){
            printf("\nDrone is moving right...\n");
        }
        if(command == 6){
            printf("\nDrone is ascending...\n");
        }
        if(command == 7){
            printf("\nDrone is descending...\n");
        }
        if(command == 8){
            printf("\nDrone is rotating left...\n");
        }
        if(command == 9){
            printf("\nDrone is rotating right...\n");
        }

        battery_life--;
        printf("Battery life remaining: %d\n", battery_life);
    }

    printf("\nShutting down drone...\n");
    return 0;
}