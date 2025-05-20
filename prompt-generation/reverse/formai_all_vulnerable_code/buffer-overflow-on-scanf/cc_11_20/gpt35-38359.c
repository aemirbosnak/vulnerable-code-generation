//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
#include <stdio.h>

int main() {

    //initialize drone variables
    int altitude = 0;
    int battery = 100;
    int direction = 0; // 0: North, 1: East, 2: South, 3: West
    
    while (1) { //continuously take user input and control the drone
        
        //display current drone status
        printf("\n\n\n------------------------");
        printf("\nCurrent Drone Status:");
        printf("\nAltitude: %d ft", altitude);
        printf("\nBattery Life: %d%%", battery);
        
        if (direction == 0) {
            printf("\nDirection: North");
        } else if (direction == 1) {
            printf("\nDirection: East");
        } else if (direction == 2) {
            printf("\nDirection: South");
        } else {
            printf("\nDirection: West");
        }
        
        printf("\n------------------------");
        
        //take user input
        printf("\nWhat would you like to do?\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Change direction\n");
        printf("4. Land drone\n");
        
        int input;
        scanf("%d", &input);
        
        //perform action based on user input
        switch (input) {
            case 1:
                if (altitude == 100) {
                    printf("\nCannot increase altitude - already at maximum height.");
                } else {
                    altitude += 10;
                    battery -= 2;
                    printf("\nAltitude increased to %d ft.", altitude);
                }
                break;
            case 2:
                if (altitude == 0) {
                    printf("\nCannot decrease altitude - already at ground level.");
                } else {
                    altitude -= 10;
                    battery -= 2;
                    printf("\nAltitude decreased to %d ft.", altitude);
                }
                break;
            case 3:
                printf("\nWhich direction would you like to change to? (0: North, 1: East, 2: South, 3: West)");
                int newDir;
                scanf("%d", &newDir);
                if (newDir < 0 || newDir > 3) {
                    printf("\nInvalid direction input.");
                } else {
                    direction = newDir;
                    printf("\nDrone direction changed.");
                }
                break;
            case 4:
                printf("\nLanding drone...");
                while (altitude > 0) {
                    altitude -= 10;
                    battery -= 2;
                    printf("\nDescending to %d ft...", altitude);
                }
                printf("\nLanded.\n\n");
                return 0; //exit program
                break;
            default:
                printf("\nInvalid input.");
                break;
        }
    }
    return 0;
}