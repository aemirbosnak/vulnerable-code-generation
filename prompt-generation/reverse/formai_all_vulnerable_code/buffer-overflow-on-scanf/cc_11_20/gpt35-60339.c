//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, minute;   // for current time
    int lightOn = 0;    // flag to represent light status
    char action;        // to take user input
    
    // Initial message
    printf("Welcome to Smart Home Light Control System!\n");
    printf("The current time is [00:00]\n");
    printf("The lights are off.\n\n");
    
    // Loop to take user input
    while(1)
    {
        // Prompt user for action
        printf("Do you want to turn the lights on or off? [Y/N]: ");
        scanf("%c", &action);
        
        // if user wants to turn light on
        if(action == 'Y' || action == 'y')
        {
            // check if light is already on or off
            if(lightOn == 1)
                printf("The lights are already on.\n");
            else
            {
                printf("Turning the lights on.\n");
                lightOn = 1;
            }
        }
        
        // if user wants to turn light off
        else if(action == 'N' || action == 'n')
        {
            // check if light is already on or off
            if(lightOn == 0)
                printf("The lights are already off.\n");
            else
            {
                printf("Turning the lights off.\n");
                lightOn = 0;
            }
        }
        
        // if user enters wrong input
        else
            printf("Invalid input. Please try again.\n");
        
        // Clear input buffer
        while ((getchar()) != '\n');
        
        // update current time
        minute += 15;
        if(minute >= 60)
        {
            hour += 1;
            minute -= 60;
        }
        
        // Check for midnight
        if(hour == 24)
            hour = 0;
        
        // Display current time and light status
        printf("\nThe current time is [%02d:%02d]\n", hour, minute);
        if(lightOn == 0)
            printf("The lights are off.\n\n");
        else
            printf("The lights are on.\n\n");
    }
    
    return 0;
}