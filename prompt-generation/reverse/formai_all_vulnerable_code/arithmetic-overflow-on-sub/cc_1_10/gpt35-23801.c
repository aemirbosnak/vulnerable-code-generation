//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
//PROGRAM: C Drone Remote Control
//AUTHOR: Excited cody
//DATE: Today

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int battery_percentage = 100; //battery starts at 100%
    int altitude = 0; //drone is on the ground
    char move_direction; //direction to move drone in (f = forward, b = backward, l = left, r = right)
    int move_distance; //distance to move drone (in feet)
    
    printf("Welcome to C Drone Remote Control!\n");
    printf("Battery is currently at %d%%\n", battery_percentage);
    printf("Altitude is currently at %d feet\n\n", altitude);
    
    //drone movement loop
    while (battery_percentage > 0) {
        
        printf("Enter a direction to move the drone (f = forward, b = backward, l = left, r = right): ");
        scanf(" %c", &move_direction);
        
        printf("Enter a distance to move the drone (in feet): ");
        scanf("%d", &move_distance);
        
        //drone movement based on user input
        switch(move_direction) {
            
            case 'f':
                printf("Moving drone forward %d feet\n", move_distance);
                altitude += move_distance;
                break;
                
            case 'b':
                printf("Moving drone backward %d feet\n", move_distance);
                altitude -= move_distance;
                break;
                
            case 'l':
                printf("Moving drone left %d feet\n", move_distance);
                break;
                
            case 'r':
                printf("Moving drone right %d feet\n", move_distance);
                break;
                
            default:
                printf("Invalid direction entered. Please try again.\n");
                continue;
        }
        
        //check if drone has crashed
        if (altitude < 0) {
            printf("Drone has crashed! Game over.\n");
            break; //exit drone movement loop
        }
        
        //deplete battery and update status
        battery_percentage -= 10;
        printf("Battery is now at %d%%\n", battery_percentage);
        printf("Altitude is now at %d feet\n\n", altitude);
        
    }
    
    printf("Thank you for using C Drone Remote Control!\n");
    
    return 0;
    
}