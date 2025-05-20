//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(){

    int power = 0; //the current power of the drone
    int direction = 0; //the current direction of the drone
    int altitude = 0; //the current altitude of the drone

    //initialize communication with the drone
    printf("Initializing connection with the drone...\n\n");

    //loop until the user exits the program
    while(1){

        //display current status
        printf("Drone Status:\n");
        printf("Power: %d\n", power);
        printf("Direction: %d\n", direction);
        printf("Altitude: %d\n\n", altitude);

        //prompt the user for input
        printf("Enter a command (p: power, d: direction, a: altitude, q: quit): ");
        char command = getchar();
        getchar(); //clear the newline character from the input buffer

        //process user input
        switch(command){
            case 'p':
                printf("Enter desired power (0-100): ");
                scanf("%d", &power);
                getchar(); //clear the newline character from the input buffer
                printf("Power set to %d\n\n", power);
                break;
            case 'd':
                printf("Enter desired direction (0-359): ");
                scanf("%d", &direction);
                getchar(); //clear the newline character from the input buffer
                printf("Direction set to %d\n\n", direction);
                break;
            case 'a':
                printf("Enter desired altitude (0-100): ");
                scanf("%d", &altitude);
                getchar(); //clear the newline character from the input buffer
                printf("Altitude set to %d\n\n", altitude);
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command\n\n");
        }

    }

    return 0;
}