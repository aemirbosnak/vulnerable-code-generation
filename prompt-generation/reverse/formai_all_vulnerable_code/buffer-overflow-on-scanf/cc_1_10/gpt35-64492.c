//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_TEMP 0 // minimum temperature
#define MAX_TEMP 100 // maximum temperature

// function to get the temperature input from user
int getTemperatureInput()
{
    int temp;
    // loop until valid temperature input is given by the user
    while (true) 
    {
        printf("Please enter temperature (0-100): ");
        scanf("%d", &temp);
        if (temp >= MIN_TEMP && temp <= MAX_TEMP) 
        {
            return temp;
        }
        printf("Invalid temperature entered. Try again.\n");
    }
}

int main()
{
    int temperature = 0;
    bool alarm_triggered = false;
    int alarm_count = 0;
    
    // loop to continuously monitor temperature input
    while (true)
    {
        temperature = getTemperatureInput();
        
        // check if temperature is within safe range
        if (temperature < 40 || temperature > 60)
        {
            alarm_triggered = true;
            alarm_count++;
            printf("Temperature Out of Range! Alarm Triggered! Count: %d\n", alarm_count);
        }
        else if (alarm_triggered)
        {
            alarm_triggered = false;
            printf("Temperature Back to Normal! Alarm Reset!\n");
        }
    }
    
    return 0;
}