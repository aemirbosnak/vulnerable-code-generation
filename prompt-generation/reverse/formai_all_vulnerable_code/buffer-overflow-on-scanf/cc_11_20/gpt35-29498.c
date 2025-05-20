//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>

int main() {
    int altitude = 0;
    int speed = 0;
    int direction = 0;
    int power = 0;
    int battery = 100;

    //Drone Status and Controls
    printf("Drone Status: \n");
    printf("Altitude: %d \nSpeed: %d \nDirection: %d \nPower: %d \nBattery: %d%% \n", altitude, speed, direction, power, battery);

    while (1) {

        //Receive commands from remote control
        char command;
        printf("Enter Command: ");
        scanf(" %c", &command);

        //Execute commands
        switch (command) {

            case 'I':
            case 'i':
                printf("Increase Altitude\n");
                altitude += 10;
                break;

            case 'D':
            case 'd':
                printf("Decrease Altitude\n");
                altitude -= 10;
                break;

            case 'F':
            case 'f':
                printf("Increase Speed\n");
                speed += 10;
                break;

            case 'S':
            case 's':
                printf("Decrease Speed\n");
                speed -= 10;
                break;

            case 'L':
            case 'l':
                printf("Turn Left\n");
                direction -= 10;
                break;

            case 'R':
            case 'r':
                printf("Turn Right\n");
                direction += 10;
                break;

            case 'O':
            case 'o':
                printf("Turn On Power\n");
                power = 1;
                break;

            case 'C':
            case 'c':
                printf("Turn Off Power\n");
                power = 0;
                break;

            default:
                printf("Invalid Command\n");
                break;
        }

        //Check for battery level
        if (battery <= 15) {
            printf("Low Battery! Return to base immediately.\n");
        }

        //Check for power status
        if (power == 0) {
            printf("Drone Shutting Down.\n");
            break;
        }

        //Print Drone Status
        printf("Drone Status: \n");
        printf("Altitude: %d \nSpeed: %d \nDirection: %d \nPower: %d \nBattery: %d%% \n", altitude, speed, direction, power, battery);

    }

    return 0;
}