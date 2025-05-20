//FormAI DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light_on = 0;
    int light_brightness = 0;
    
    printf("Welcome to Smart Home Light Control System!\n");
    
    while(1)
    {
        printf("\n");
        printf("What do you want to do?\n");
        printf("1. Turn on/off the light\n");
        printf("2. Adjust light brightness\n");
        printf("3. Exit\n");
        
        int option;
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                if (light_on == 0)
                {
                    printf("Turning on the light...\n");
                    light_on = 1;
                }
                else
                {
                    printf("Turning off the light...\n");
                    light_on = 0;
                }
                break;
            case 2:
                printf("Enter light brightness (0 - 100):\n");
                scanf("%d", &light_brightness);
                printf("Setting light brightness to %d\n", light_brightness);
                break;
            case 3:
                printf("Exiting Smart Home Light Control System...\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}