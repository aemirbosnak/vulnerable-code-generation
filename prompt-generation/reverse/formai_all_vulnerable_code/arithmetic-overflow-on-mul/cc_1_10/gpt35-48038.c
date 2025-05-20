//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void warpSpeed(int distance) { //function declaration 
    //Warpspeed function simulates interstellar travel by sleeping the program for a random amount of seconds within a set range
    //It outputs distance and estimated travel time in hours 
    int travelTime = (distance * rand() % 24) + 1;
    printf("\nWarping through %d light years... \nEstimated travel time: %d hours\n", distance, travelTime);
    sleep(travelTime);
    printf("Arrived at destination!\n\n");
}

int main() {
    printf("Welcome to the Procedural Space Adventure!\n");

    //Spaceship Variables
    int fuel = 100;
    int distance = 0;
    int warpDrive = 0; 

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1: Check Fuel levels\n");
        printf("2: Engage Warp Drive\n");
        printf("3: Land on planet\n");
        printf("4: Quit Program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nFuel Level: %d\n", fuel);
                break;
            case 2:
                if (fuel < 20) {
                    printf("Fuel levels too low. Cannot engage Warp Drive.\n");
                } else {
                    printf("\nEnter light years to travel: ");
                    scanf("%d", &distance);
                    
                    if (distance <= 0) {
                        printf("Invalid input. Light years must be greater than 0.");
                    } else {
                        printf("\nInitiating Warp Speed...\n");
                        fuel -= (distance * 2);
                        warpSpeed(distance);
                        warpDrive += 1;
                    }
                }
                break;
            case 3:
                if (warpDrive < 1) {
                    printf("\nCannot land on planet without using Warp Drive at least once.\n");
                } else {
                    printf("\nLanding on planet...\n");
                    printf("Welcome to planet XYZ!\n");
                }
                break;
            case 4:
                printf("\nProgram terminated.");
                exit(0);
            default:
                printf("Invalid input.\n");
        }

        if (fuel <= 0) {
            printf("\nOut of fuel. You are stranded in space.\n");
            printf("Program terminated.");
            exit(0);
        }
    }
    return 0;
}