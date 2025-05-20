//FormAI DATASET v1.0 Category: Smart home automation ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BEDROOM_LIGHT 1
#define KITCHEN_LIGHT 2
#define LIVINGROOM_LIGHT 3
#define ALARM 4
#define AC 5

int main()
{
    bool bedroomLightOn = false;
    bool kitchenLightOn = false;
    bool livingroomLightOn = false;
    bool alarmOn = false;
    bool acOn = false;

    printf("Welcome to your Smart Home Automation System\n");

    while(true)
    {
        printf("\nMain Menu\n");
        printf("1 - Turn on/off bedroom light\n");
        printf("2 - Turn on/off kitchen light\n");
        printf("3 - Turn on/off living room light\n");
        printf("4 - Turn on/off alarm\n");
        printf("5 - Turn on/off air conditioning\n");
        printf("6 - Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case BEDROOM_LIGHT:
                if(bedroomLightOn)
                {
                    printf("Turning off bedroom light\n");
                    bedroomLightOn = false;
                }
                else
                {
                    printf("Turning on bedroom light\n");
                    bedroomLightOn = true;
                }
                break;

            case KITCHEN_LIGHT:
                if(kitchenLightOn)
                {
                    printf("Turning off kitchen light\n");
                    kitchenLightOn = false;
                }
                else
                {
                    printf("Turning on kitchen light\n");
                    kitchenLightOn = true;
                }
                break;

            case LIVINGROOM_LIGHT:
                if(livingroomLightOn)
                {
                    printf("Turning off living room light\n");
                    livingroomLightOn = false;
                }
                else
                {
                    printf("Turning on living room light\n");
                    livingroomLightOn = true;
                }
                break;

            case ALARM:
                if(alarmOn)
                {
                    printf("Turning off alarm\n");
                    alarmOn = false;
                }
                else
                {
                    printf("Turning on alarm\n");
                    alarmOn = true;
                }
                break;

            case AC:
                if(acOn)
                {
                    printf("Turning off air conditioning\n");
                    acOn = false;
                }
                else
                {
                    printf("Turning on air conditioning\n");
                    acOn = true;
                }
                break;

            case 6:
                printf("Goodbye!\n");
                return 0;
                break;

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}