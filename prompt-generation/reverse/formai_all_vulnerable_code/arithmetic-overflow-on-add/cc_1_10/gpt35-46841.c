//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

int main(){
    int choice, x, y, distance;
    int carX = 0, carY = 0; //initial position of the car is (0,0)

    printf("Welcome to GPS Navigation Simulation! \n");

    while(1){
        printf("\nPlease enter a number to choose an option: \n");
        printf("1. Show current location\n");
        printf("2. Set destination\n");
        printf("3. Start driving\n");
        printf("4. Exit program\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Current location: (%d, %d)\n", carX, carY);
                break;
            case 2:
                printf("Please enter the x coordinate of your destination: ");
                scanf("%d", &x);
                printf("Please enter the y coordinate of your destination: ");
                scanf("%d", &y);
                distance = abs(x - carX) + abs(y - carY); //calculating the distance
                printf("Your destination is %d units away\n", distance);
                break;
            case 3:
                if(distance==0){
                    printf("You have reached your destination!\n");
                    carX = x; //update the car's position to the destination
                    carY = y;
                    distance = 0; //reset the distance
                }
                else{
                    printf("You are currently %d units away from your destination.\n", distance);
                }
                break;
            case 4:
                printf("Thank you for using GPS Navigation Simulation!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}