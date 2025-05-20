//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to C Drone Remote Control!\n");
    
    int batteryLevel = 100;
    int altitude = 0;
    int direction = 0; // 0 for forward, 1 for backward, 2 for left, 3 for right
    int speed = 0; // in meters per second
    
    while(1) { // program runs until user terminates
        printf("\nBattery Level: %d%%\n\n", batteryLevel);
        printf("Drone Altitude: %d meters\n", altitude);
        
        // Menu options
        printf("\n\t1. Increase altitude\n");
        printf("\t2. Decrease altitude\n");
        printf("\t3. Change direction\n");
        printf("\t4. Change speed\n");
        printf("\t5. Land drone\n");
        printf("\t6. Exit program\n");
        
        int choice; // user's menu choice
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(altitude < 100) {
                    altitude += 5;
                    printf("\nIncreasing altitude...\n");
                }
                else {
                    printf("\nMaximum altitude reached!\n");
                }
                break;
                
            case 2:
                if(altitude > 0) {
                    altitude -= 5;
                    printf("\nDecreasing altitude...\n");
                }
                else {
                    printf("\nDrone already on the ground!\n");
                }
                break;
                
            case 3:
                printf("\nEnter direction (0: forward, 1: backward, 2: left, 3: right): ");
                scanf("%d", &direction);
                switch(direction) {
                    case 0:
                        printf("\nGoing forward...\n");
                        break;
                    case 1:
                        printf("\nGoing backward...\n");
                        break;
                    case 2:
                        printf("\nGoing left...\n");
                        break;
                    case 3:
                        printf("\nGoing right...\n");
                        break;
                    default:
                        printf("\nInvalid direction entered!\n");
                }
                break;
                
            case 4:
                printf("\nEnter speed (meters per second): ");
                scanf("%d", &speed);
                if(speed < 0 || speed > 30) {
                    printf("\nInvalid speed entered! Please enter a speed between 0 and 30 m/s.\n");
                }
                else {
                    printf("\nChanging speed to %d m/s...\n", speed);
                }
                break;
                
            case 5:
                printf("\nLanding drone...\n");
                altitude = 0;
                break;
                
            case 6:
                printf("\nExiting program...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice entered!\n");
        }
        
        // Decrease battery level by 2% after every action
        if(batteryLevel > 0) {
            batteryLevel -= 2;
        }
        else {
            printf("\nBattery level too low. Returning drone to base...\n");
            altitude = 0;
            batteryLevel = 100;
            direction = 0;
            speed = 0;
        }
    }
    
    return 0;
}