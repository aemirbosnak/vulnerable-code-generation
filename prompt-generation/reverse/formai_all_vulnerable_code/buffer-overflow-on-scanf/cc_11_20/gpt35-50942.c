//FormAI DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize home control variables
    int lights = 0;
    int ac = 0;
    int heater = 0;
    int doors = 0;
    int windows = 0;

    while(1)
    {
        //print out menu options
        printf("Welcome to your Smart Home Control Panel!\n");
        printf("------------------------------------------\n");
        printf("1. Turn Lights On/Off\n");
        printf("2. Turn AC On/Off\n");
        printf("3. Turn Heater On/Off\n");
        printf("4. Open/Close Doors\n");
        printf("5. Open/Close Windows\n");
        printf("6. Exit\n");

        //get user selection
        int selection;
        printf("Enter your selection: ");
        scanf("%d", &selection);

        //perform selected action
        switch(selection)
        {
            case 1:
                if(lights == 0)
                {
                    printf("Turning Lights On.\n");
                    lights = 1;
                }
                else
                {
                    printf("Turning Lights Off.\n");
                    lights = 0;
                }
                break;
            case 2:
                if(ac == 0)
                {
                    printf("Turning AC On.\n");
                    ac = 1;
                }
                else
                {
                    printf("Turning AC Off.\n");
                    ac = 0;
                }
                break;
            case 3:
                if(heater == 0)
                {
                    printf("Turning Heater On.\n");
                    heater = 1;
                }
                else
                {
                    printf("Turning Heater Off.\n");
                    heater = 0;
                }
                break;
            case 4:
                if(doors == 0)
                {
                    printf("Opening Doors.\n");
                    doors = 1;
                }
                else
                {
                    printf("Closing Doors.\n");
                    doors = 0;
                }
                break;
            case 5:
                if(windows == 0)
                {
                    printf("Opening Windows.\n");
                    windows = 1;
                }
                else
                {
                    printf("Closing Windows.\n");
                    windows = 0;
                }
                break;
            case 6:
                printf("Exiting Smart Home Control Panel.\n");
                exit(0);
            default:
                printf("Invalid selection.\n");
                break;  
        }
    }
    return 0;
}