//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[20];
    int speed = 10;
    float altitude = 0.0;
    int battery = 100;
    int isConnected = 0;

    printf("Welcome to C Drone Remote Control!\n");

    while(1)
    {
        printf("Enter a command: ");
        scanf("%s", command);

        if(strcmp(command, "takeoff") == 0)
        {
            if(isConnected == 0)
            {
                printf("Error: Drone not connected.\n");
            }
            else if(altitude > 0.0)
            {
                printf("Error: Drone already airborne.\n");
            }
            else if(battery <= 10)
            {
                printf("Error: Battery too low for takeoff.\n");
            }
            else
            {
                altitude = 10.0;
                printf("Drone has taken off.\n");
            }
        }
        else if(strcmp(command, "land") == 0)
        {
            if(isConnected == 0)
            {
                printf("Error: Drone not connected.\n");
            }
            else if(altitude == 0.0)
            {
                printf("Error: Drone already on ground.\n");
            }
            else
            {
                altitude = 0.0;
                printf("Drone has landed.\n");
            }
        }
        else if(strcmp(command, "connect") == 0)
        {
            if(isConnected == 1)
            {
                printf("Error: Drone already connected.\n");
            }
            else
            {
                isConnected = 1;
                printf("Drone connected.\n");
            }
        }
        else if(strcmp(command, "disconnect") == 0)
        {
            if(isConnected == 0)
            {
                printf("Error: Drone not connected.\n");
            }
            else
            {
                isConnected = 0;
                printf("Drone disconnected.\n");
            }
        }
        else if(strcmp(command, "up") == 0)
        {
            if(isConnected == 0)
            {
                printf("Error: Drone not connected.\n");
            }
            else if(altitude == 0.0)
            {
                printf("Error: Drone on ground.\n");
            }
            else
            {
                altitude += 5.0;
                printf("Drone has gone up by 5 meters.\n");
            }
        }
        else if(strcmp(command, "down") == 0)
        {
            if(isConnected == 0)
            {
                printf("Error: Drone not connected.\n");
            }
            else if(altitude == 0.0)
            {
                printf("Error: Drone on ground.\n");
            }
            else if(altitude <= 5.0)
            {
                altitude = 0.0;
                printf("Drone has landed.\n");
            }
            else
            {
                altitude -= 5.0;
                printf("Drone has gone down by 5 meters.\n");
            }
        }
        else if(strcmp(command, "speedup") == 0)
        {
            if(speed >= 30)
            {
                printf("Error: Speed is already at maximum.\n");
            }
            else
            {
                speed += 5;
                printf("Speed increased by 5km/hr.\n");
            }
        }
        else if(strcmp(command, "speeddown") == 0)
        {
            if(speed <= 5)
            {
                printf("Error: Speed is already at minimum.\n");
            }
            else
            {
                speed -= 5;
                printf("Speed decreased by 5km/hr.\n");
            }
        }
        else if(strcmp(command, "battery") == 0)
        {
            printf("Battery level: %d%%\n", battery);
        }
        else if(strcmp(command, "exit") == 0)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Error: Invalid command.\n");
        }
        
        //Decreasing battery on every command
        if(battery>0 && strcmp(command,"takeoff")==0)
        {
            battery-=10;
        }

        if(battery<=20)
        {
            printf("Warning! Battery level is below 20%%\n");
        }
        if(battery<=10)
        {
            printf("Error! Drone shutting down due to low battery.\n");
            break;
        }
    }

    return 0;
}