//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int altitude = 0; //initialize drone altitude variable
    int distance = 0; //initialize drone distance variable
    srand(time(0)); //seed random number generator with current time

    printf("Welcome to Drone Remote Control Program!\n");
    printf("The drone is currently hovering at an altitude of %d meters and at a distance of %d meters from the remote control.\n", altitude, distance);

    while(1){
        printf("\nEnter command: ");
        char command;
        scanf(" %c", &command); //get user input for command
        printf("\n");

        switch(command){
            case 'k':
                printf("Drone is taking off\n");
                altitude += (rand() % 51) + 50; //increase altitude by random number between 50-100 meters
                printf("Drone is now hovering at an altitude of %d meters and at a distance of %d meters from the remote control.\n", altitude, distance);
                break;
            
            case 'j':
                printf("Drone is landing\n");
                altitude -= (rand() % 51) + 50; //decrease altitude by random number between 50-100 meters
                if(altitude <= 0){ //if altitude is less than or equal to zero, set altitude to 0 and break out of loop
                    altitude = 0;
                    printf("Drone has landed safely.\n");
                    break;
                }
                printf("Drone is now hovering at an altitude of %d meters and at a distance of %d meters from the remote control.\n", altitude, distance);
                break;

            case 'a':
                printf("Drone is moving left\n");
                distance += (rand() % 11) + 10; //increase distance by random number between 10-20 meters
                printf("Drone is now hovering at an altitude of %d meters and at a distance of %d meters from the remote control.\n", altitude, distance);
                break;

            case 'd':
                printf("Drone is moving right\n");
                distance -= (rand() % 11) + 10; //decrease distance by random number between 10-20 meters
                printf("Drone is now hovering at an altitude of %d meters and at a distance of %d meters from the remote control.\n", altitude, distance);
                break;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}