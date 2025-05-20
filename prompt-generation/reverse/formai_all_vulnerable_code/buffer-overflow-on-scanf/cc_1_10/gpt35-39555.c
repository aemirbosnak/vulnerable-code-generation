//FormAI DATASET v1.0 Category: Robot movement control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Brave Robot Movement Control Program!\n");
    printf("Make sure you have connected your Robot to the COM port and have its port number.\n");
    printf("Please enter the port number of the robot: ");
    int portNum;
    scanf("%d", &portNum);
    
    srand(time(NULL));
    
    printf("\n");
    printf("We will now start the robot movement control program.\n");
    printf("Use 'w' to move forward, 's' to move backward and 'q' to quit the program.\n\n");
    
    char input;
    int movementCount = 0;
    while (input != 'q') {
        printf("Enter a movement command for the robot: ");
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                printf("Moving forward...\n");
                movementCount++;
                break;
            case 's':
                printf("Moving backward...\n");
                movementCount--;
                break;
            case 'q':
                printf("Quitting the program...\n");
                break;
            default:
                printf("Invalid movement command.\n");
        }
        
        if (movementCount >= 10) {
            printf("Warning! Robot may fall off the edge! Please change direction.\n");
        }
        else if (movementCount <= -10) {
            printf("Warning! Robot may fall off the other edge! Please change direction.\n");
        }
        
        int randVal = rand() % 10;
        if (randVal == 0) {
            printf("Sensor detected an obstacle. Changing direction.\n");
            if (movementCount >= 0) {
                movementCount--;
            }
            else {
                movementCount++;
            }
        }
        
        printf("Current location of the robot: %d\n\n", movementCount);
    }
    
    printf("Thank you for using the Brave Robot Movement Control Program!\n");
    
    return 0;
}