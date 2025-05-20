//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Let's power up the drone...\n");
    int power = 0;
    printf("Press 1 to power up the drone: ");
    scanf("%d", &power);
    // check if the input is valid
    if(power == 1){
        printf("Drone is now powered up!\n");
    }else{
        printf("Invalid input. Please try again.\n");
        return 0;
    }
    // main loop of the program
    char command[10];
    while(1){
        printf("Type in the command ('takeoff', 'land', 'move', 'stop', 'battery', 'exit'): ");
        scanf("%s", command);
        // check if the input is valid
        if(strcmp(command, "takeoff") != 0 && 
           strcmp(command, "land") != 0 && 
           strcmp(command, "move") != 0 && 
           strcmp(command, "stop") != 0 && 
           strcmp(command, "battery") != 0 && 
           strcmp(command, "exit") != 0){
            printf("Invalid command. Please try again.\n");
            continue;
        }
        // if the command is 'takeoff'
        if(strcmp(command, "takeoff") == 0){
            printf("Drone is taking off...\n");
        }
        // if the command is 'land'
        if(strcmp(command, "land") == 0){
            printf("Drone is landing...\n");
        }
        // if the command is 'move'
        if(strcmp(command, "move") == 0){
            int x = 0, y = 0, z = 0;
            printf("Enter the x, y, and z coordinates (separate with a space): ");
            scanf("%d %d %d", &x, &y, &z);
            printf("Drone is moving to (%d, %d, %d)...\n", x, y, z);
        }
        // if the command is 'stop'
        if(strcmp(command, "stop") == 0){
            printf("Drone is stopping...\n");
        }
        // if the command is 'battery'
        if(strcmp(command, "battery") == 0){
            int battery = 75;
            printf("Battery level is %d%%.\n", battery);
        }
        // if the command is 'exit'
        if(strcmp(command, "exit") == 0){
            printf("Exiting program...\n");
            return 0;
        }
    }
    return 0;
}