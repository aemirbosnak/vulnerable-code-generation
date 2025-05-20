//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1
#define AC_OFF 0
#define AC_ON 1

int main()
{
    int light_status = LIGHT_OFF;
    int ac_status = AC_OFF;

    printf("Welcome to your smart home! \n");

    while(1)
    {
        char command[20];

        printf("Enter command (turn on/off light, turn on/off AC, exit): ");
        scanf("%s", command);

        if(strcmp(command, "turn on light") == 0)
        {
            if(light_status == LIGHT_OFF)
            {
                printf("Turning on the light... \n");
                light_status = LIGHT_ON;
            }
            else
            {
                printf("The light is already on. \n");
            }
        }

        else if(strcmp(command, "turn off light") == 0)
        {
            if(light_status == LIGHT_ON)
            {
                printf("Turning off the light... \n");
                light_status = LIGHT_OFF;
            }
            else
            {
                printf("The light is already off. \n");
            }
        }

        else if(strcmp(command, "turn on AC") == 0)
        {
            if(ac_status == AC_OFF)
            {
                printf("Turning on the AC... \n");
                ac_status = AC_ON;
            }
            else
            {
                printf("The AC is already on. \n");
            }
        }

        else if(strcmp(command, "turn off AC") == 0)
        {
            if(ac_status == AC_ON)
            {
                printf("Turning off the AC... \n");
                ac_status = AC_OFF;
            }
            else
            {
                printf("The AC is already off. \n");
            }
        }

        else if(strcmp(command, "exit") == 0)
        {
            printf("Thank you for using your smart home. \n");
            break;
        }

        else
        {
            printf("Invalid command. \n");
        }
    }

    return 0;
}