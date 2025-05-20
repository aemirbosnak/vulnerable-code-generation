//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random number generator
    
    int batteryLevel = 100; //initial battery level
    int distanceTraveled = 0; //initial distance traveled
    int carSpeed = 0; //initial car speed
    int carDirection = 0; //initial car direction (0 is forward, 1 is backward)
    int userChoice;
    
    printf("Welcome to the RC Car Simulator!\n");
    
    //main loop
    while(batteryLevel > 0) {
        printf("\nBattery Level: %d\n", batteryLevel);
        printf("Distance Traveled: %d\n", distanceTraveled);
        printf("Car Speed: %d\n", carSpeed);
        printf("Car Direction: %s\n", carDirection == 0 ? "Forward" : "Backward");
        
        printf("\nWhat would you like to do?\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Change Direction\n");
        printf("4. Drive Forward\n");
        printf("5. Drive Backward\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &userChoice);
        
        switch(userChoice) {
            case 1:
                carSpeed += 5;
                break;
            case 2:
                carSpeed -= 5;
                break;
            case 3:
                carDirection = carDirection == 0 ? 1 : 0;
                break;
            case 4:
                if(carDirection == 0) {
                    distanceTraveled += carSpeed;
                } else {
                    distanceTraveled -= carSpeed;
                }
                batteryLevel -= (rand() % 5) + 1; //decrease battery level randomly
                break;
            case 5:
                if(carDirection == 1) {
                    distanceTraveled += carSpeed;
                } else {
                    distanceTraveled -= carSpeed;
                }
                batteryLevel -= (rand() % 5) + 1; //decrease battery level randomly
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
        
        //check if battery level is zero
        if(batteryLevel <= 0) {
            printf("\nBattery level is too low. Car has stopped.\n");
            return 0;
        }
        
        //check if distance traveled is greater than 1000
        if(distanceTraveled > 1000) {
            printf("\nCongratulations! You have completed the race.\n");
            return 0;
        }
        
        //slow down car if speed is too high
        if(carSpeed > 40) {
            printf("\nWarning! Car speed is too high. Slowing down.\n");
            carSpeed -= 10;
        }
        
        //change direction randomly
        if(rand() % 10 == 0) {
            carDirection = carDirection == 0 ? 1 : 0;
            printf("\nCar has changed direction.\n");
        }
    }
}