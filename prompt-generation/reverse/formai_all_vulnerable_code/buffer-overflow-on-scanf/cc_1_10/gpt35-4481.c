//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize variables
    int speed, direction;
    float battery_level;
    char command;

    //print welcome message
    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    //get initial battery level
    printf("Please enter the initial battery level (in percentage):\n");
    scanf("%f", &battery_level);

    //prompt user for commands
    printf("Please enter the command (s - speed, d - direction, b - battery, q - quit):\n");

    //listen for commands
    while(1)
    {
        //get command from user
        scanf(" %c", &command);

        //handle commands
        switch(command)
        {
            case 's':
                //get speed from user
                printf("Please enter the speed (1-10):\n");
                scanf("%d", &speed);
                //simulate vehicle speed
                printf("Vehicle speed set to %d.\n", speed);
                break;
            case 'd':
                //get direction from user
                printf("Please enter the direction (0-360):\n");
                scanf("%d", &direction);
                //simulate vehicle direction
                printf("Vehicle direction set to %d degrees.\n", direction);
                break;
            case 'b':
                //display battery level
                printf("Battery level: %.2f%%.\n", battery_level);
                break;
            case 'q':
                //exit program
                printf("Goodbye!\n");
                exit(0);
            default:
                //handle invalid commands
                printf("Invalid command.\n");
                break;
        }

        //decrease battery level by 1% for each command
        battery_level -= 1;

        //check battery level
        if(battery_level <= 0)
        {
            //stop simulation and display low battery warning
            printf("Battery level too low. Simulation stopping.\n");
            break;
        }
    }

    return 0;
}