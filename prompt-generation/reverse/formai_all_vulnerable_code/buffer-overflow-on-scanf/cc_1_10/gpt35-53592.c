//FormAI DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool doorLocked = true;
    bool lightsOn = false;
    bool thermostatOn = true;

    printf("Welcome to your smart home!\n\n");

    printf("Do you want to unlock the door (Y/N)? ");
    char answer = getchar();
    getchar(); // consume newline

    if (answer == 'Y' || answer == 'y')
    {
        doorLocked = false;
    }

    printf("Do you want to turn on the lights (Y/N)? ");
    answer = getchar();
    getchar(); // consume newline

    if (answer == 'Y' || answer == 'y')
    {
        lightsOn = true;
    }

    printf("Do you want to adjust the thermostat (Y/N)? ");
    answer = getchar();
    getchar(); // consume newline

    if (answer == 'Y' || answer == 'y')
    {
        thermostatOn = true;
		printf("What temperature do you want to set (in F)? ");
		int temperature;
		scanf("%d", &temperature);
		printf("Thermostat is set to %d F.\n", temperature);
    }

    printf("\nYour smart home is now set up as follows:\n\n");

    printf("Door is %slocked.\n", doorLocked ? "" : "un");
    printf("Lights are %s.\n", lightsOn ? "on" : "off");
    printf("Thermostat is %s.\n", thermostatOn ? "on" : "off");

    return 0;
}