//FormAI DATASET v1.0 Category: Smart home automation ; Style: random
#include <stdio.h>
#include <string.h>

int lights = 0;
int temperature = 0;
int blinds = 0;
int security = 0;

int main()
{
    printf("Welcome to your smart home!\n");
    printf("What would you like to do?\n");
    char command[50];

    while (1)
    {
        scanf("%s", command);

        if (strcmp(command, "lights_on") == 0)
        {
            lights = 1;
            printf("Lights turned on.\n");
        }
        else if (strcmp(command, "lights_off") == 0)
        {
            lights = 0;
            printf("Lights turned off.\n");
        }
        else if (strcmp(command, "increase_temperature") == 0)
        {
            temperature += 1;
            printf("Temperature increased to %d degrees.\n", temperature);
        }
        else if (strcmp(command, "decrease_temperature") == 0)
        {
            temperature -= 1;
            printf("Temperature decreased to %d degrees.\n", temperature);
        }
        else if (strcmp(command, "open_blinds") == 0)
        {
            blinds = 1;
            printf("Blinds opened.\n");
        }
        else if (strcmp(command, "close_blinds") == 0)
        {
            blinds = 0;
            printf("Blinds closed.\n");
        }
        else if (strcmp(command, "activate_security") == 0)
        {
            security = 1;
            printf("Security activated.\n");
        }
        else if (strcmp(command, "deactivate_security") == 0)
        {
            security = 0;
            printf("Security deactivated.\n");
        }
        else if (strcmp(command, "help") == 0)
        {
            printf("The following commands are available:\n");
            printf("- lights_on\n");
            printf("- lights_off\n");
            printf("- increase_temperature\n");
            printf("- decrease_temperature\n");
            printf("- open_blinds\n");
            printf("- close_blinds\n");
            printf("- activate_security\n");
            printf("- deactivate_security\n");
            printf("- help\n");
        }
        else
        {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}