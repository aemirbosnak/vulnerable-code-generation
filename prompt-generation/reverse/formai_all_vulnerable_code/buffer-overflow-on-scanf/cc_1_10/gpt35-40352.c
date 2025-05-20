//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int temperature = 25;
    int humidity = 60;
    int light_intensity = 100;
    int motion = 0;
    int door_status = 0;
    char choice[10];

    printf("Welcome to your Smart Home!\n");

    while(1)
    {
        printf("\n*** Main Menu ***\n");
        printf("1. Check Temperature\n");
        printf("2. Check Humidity\n");
        printf("3. Check Light Intensity\n");
        printf("4. Check Motion Sensor\n");
        printf("5. Check Door Status\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%s", choice);

        if(strcmp(choice, "1") == 0)
        {
            printf("\nTemperature: %d\n", temperature);
        }
        else if(strcmp(choice, "2") == 0)
        {
            printf("\nHumidity: %d\n", humidity);
        }
        else if(strcmp(choice, "3") == 0)
        {
            printf("\nLight Intensity: %d\n", light_intensity);
        }
        else if(strcmp(choice, "4") == 0)
        {
            if(motion == 1)
            {
                printf("\nMotion Detected!\n");
            }
            else
            {
                printf("\nNo Motion Detected.\n");
            }
        }
        else if(strcmp(choice, "5") == 0)
        {
            if(door_status == 1)
            {
                printf("\nDoor is Open!\n");
            }
            else
            {
                printf("\nDoor is Closed.\n");
            }
        }
        else if(strcmp(choice, "6") == 0)
        {
            printf("\nExiting Program...\n");
            exit(0);
        }
        else
        {
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}