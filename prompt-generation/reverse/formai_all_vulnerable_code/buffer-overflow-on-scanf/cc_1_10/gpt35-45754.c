//FormAI DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

#define TOTAL_LIGHTS 5 // total number of lights in the house

int lights_status[TOTAL_LIGHTS]; // array to store the current status of all lights (0: off, 1: on)

void turnOnLight(int light_number)
{
    lights_status[light_number] = 1;
    printf("Light %d turned on!\n", light_number+1);
}

void turnOffLight(int light_number)
{
    lights_status[light_number] = 0;
    printf("Light %d turned off!\n", light_number+1);
}

void printLightsStatus()
{
    printf("Current status of lights: ");
    for(int i=0; i<TOTAL_LIGHTS; i++)
    {
        printf("%d ", lights_status[i]);
    }
    printf("\n");
}

int main()
{
    char choice;
    int light_number;

    // initialize all lights to off by default
    for(int i=0; i<TOTAL_LIGHTS; i++)
    {
        lights_status[i] = 0;
    }

    printf("Welcome to Smart Home Light Control!\n");

    // main loop
    while(1)
    {
        // show options to the user
        printf("Enter 1 to turn on a light\n");
        printf("Enter 2 to turn off a light\n");
        printf("Enter 3 to print current status of all lights\n");
        printf("Enter 4 to exit\n");

        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                printf("Enter the light number you want to turn on: ");
                scanf("%d", &light_number);
                if(light_number < 1 || light_number > TOTAL_LIGHTS)
                {
                    printf("Invalid light number. Enter a number between 1 and %d\n", TOTAL_LIGHTS);
                }
                else
                {
                    turnOnLight(light_number-1);
                }
                break;

            case '2':
                printf("Enter the light number you want to turn off: ");
                scanf("%d", &light_number);
                if(light_number < 1 || light_number > TOTAL_LIGHTS)
                {
                    printf("Invalid light number. Enter a number between 1 and %d\n", TOTAL_LIGHTS);
                }
                else
                {
                    turnOffLight(light_number-1);
                }
                break;

            case '3':
                printLightsStatus();
                break;

            case '4':
                printf("Exiting Smart Home Light Control. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}