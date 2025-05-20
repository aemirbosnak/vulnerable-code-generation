//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lightStatus = 1;
    int turnOffTime = 0;
    int turnOnTime = 0;

    while (1)
    {
        time_t t = time(NULL);
        struct tm *currentTime = localtime(&t);

        int currentMinute = currentTime->tm_min;
        int currentHour = currentTime->tm_hour;
        
        if (lightStatus == 1)
        {
            if (turnOffTime != 0 && turnOffTime <= currentMinute)
            {
                printf("Turning off lights...\n");
                lightStatus = 0;
                turnOffTime = 0;
            }
        }
        else
        {
            if (turnOnTime != 0 && turnOnTime <= currentMinute)
            {
                printf("Turning on lights...\n");
                lightStatus = 1;
                turnOnTime = 0;
            }
        }
        
        // Prompt user for input
        printf("\nChoose an option:\n1. Turn on lights\n2. Turn off lights\n3. Schedule turn on time\n4. Schedule turn off time\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Turning on lights...\n");
                lightStatus = 1;
                break;
            case 2:
                printf("Turning off lights...\n");
                lightStatus = 0;
                break;
            case 3:
                printf("Enter the hour (0-23) for the lights to turn on: ");
                int hourOn;
                scanf("%d", &hourOn);
                printf("Enter the minute (0-59) for the lights to turn on: ");
                int minuteOn;
                scanf("%d", &minuteOn);
                
                turnOnTime = calculateTime(hourOn, minuteOn);
                printf("Lights will turn on at %02d:%02d\n", hourOn, minuteOn);
                break;
            case 4:
                printf("Enter the hour (0-23) for the lights to turn off: ");
                int hourOff;
                scanf("%d", &hourOff);
                printf("Enter the minute (0-59) for the lights to turn off: ");
                int minuteOff;
                scanf("%d", &minuteOff);
                
                turnOffTime = calculateTime(hourOff, minuteOff);
                printf("Lights will turn off at %02d:%02d\n", hourOff, minuteOff);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

int calculateTime(int hour, int minute)
{
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    int currentHour = currentTime->tm_hour;
    int currentMinute = currentTime->tm_min;
    
    int timeDiff;
    
    if (hour < currentHour || (hour == currentHour && minute < currentMinute))
    {
        // Date has rolled over to next day
        timeDiff = (hour + 24 - currentHour) * 60 + (minute - currentMinute);
    }
    else
    {
        timeDiff = (hour - currentHour) * 60 + (minute - currentMinute);
    }
    
    return currentMinute + timeDiff;
}