//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int batteryLevel = 100; // initialize battery level at 100%
    int speed = 0; // initialize speed at 0
    int altitude = 0; // initialize altitude at ground level
    
    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Your battery level is currently at %d%%\n", batteryLevel);
    
    //while loop to continuously prompt user for input
    while(1) {
        char input;
        printf("\nEnter 's' to change speed, 'a' to change altitude, 'q' to quit:\n");
        scanf(" %c", &input);
        
        switch(input) {
            case 's':
                printf("Enter speed (0-10): ");
                scanf("%d", &speed);
                
                if(speed > 10) {
                    printf("Invalid input! Maximum speed is 10.\n");
                    speed = 10;
                }
                else if(speed < 0) {
                    printf("Invalid input! Minimum speed is 0.\n");
                    speed = 0;
                }
                
                printf("Speed changed to %d\n", speed);
                break;
                
            case 'a':
                printf("Enter altitude (0-100): ");
                scanf("%d", &altitude);
                
                if(altitude > 100) {
                    printf("Invalid input! Maximum altitude is 100.\n");
                    altitude = 100;
                }
                else if(altitude < 0) {
                    printf("Invalid input! Minimum altitude is 0.\n");
                    altitude = 0;
                }
                
                printf("Altitude changed to %d\n", altitude);
                break;
                
            case 'q':
                printf("Shutting down drone...\n");
                exit(0);
                
            default:
                printf("Invalid input!\n");
                break;
        }
        
        //reduce battery level by 5% after every input received
        batteryLevel -= 5;
        
        if(batteryLevel <= 0) {
            printf("Battery level critically low! Drone shutting down...\n");
            exit(0);
        }
        
        printf("\nBattery level is now at %d%%\n", batteryLevel);
    }
    
    return 0;
}