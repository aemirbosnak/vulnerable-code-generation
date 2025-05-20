//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the light is on or off
bool checkLightStatus(bool isLightOn)
{
    if (isLightOn)
    {
        printf("The light is currently on. \n");
    } else {
        printf("The light is currently off. \n");
    }

    return isLightOn;
}

// Function to turn on or off the light
bool toggleLight(bool isLightOn)
{
    if (isLightOn)
    {
        printf("Turning off the light... \n");
        isLightOn = false;
    } else {
        printf("Turning on the light... \n");
        isLightOn = true;
    }

    return isLightOn;
}

// Function to check the temperature in the house
float checkTemperature()
{
    float temperature = 25.4;
    printf("The temperature in the house is %.2f degrees Celsius. \n", temperature);
    return temperature;
}

// Function to control the thermostat
float controlThermostat(float temperature)
{
    printf("Please enter the desired temperature: ");
    scanf("%f", &temperature);
    
    printf("Setting the temperature to %.2f degrees Celsius. \n", temperature);
    return temperature;
}

// Main function
int main()
{
    bool isLightOn = false;
    float temperature = 0.0;

    printf("Welcome to Smart Home Automation! \n");

    while (true)
    {
        printf("Please choose an option: \n");
        printf("1) Check the light status \n");
        printf("2) Toggle the light \n");
        printf("3) Check the temperature \n");
        printf("4) Control the thermostat \n");
        printf("5) Exit \n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkLightStatus(isLightOn);
                break;

            case 2:
                isLightOn = toggleLight(isLightOn);
                break;

            case 3:
                checkTemperature();
                break;

            case 4:
                temperature = controlThermostat(temperature);
                break;

            case 5:
                printf("Goodbye! \n");
                return 0;

            default:
                printf("Invalid choice. Please try again. \n");
                break;
        }
    }
}