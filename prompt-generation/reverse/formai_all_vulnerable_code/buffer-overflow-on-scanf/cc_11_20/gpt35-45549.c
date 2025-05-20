//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int room1_temp = 24;
    int room2_temp = 22;
    int room3_temp = 23;
    int living_room_lights = 0;
    int bedroom_lights = 1;
    int bathroom_fan = 0;
    int kitchen_oven = 0;
    char command[100];

    printf("Welcome to Smart Home Automation!\n");
    printf("Please enter your command:\n");

    while (strcmp(command, "exit") != 0)
    {
        scanf("%s", command);

        if (strcmp(command, "living_room_lights on") == 0)
        {
            printf("Turning living room lights on...\n");
            living_room_lights = 1;
        }
        else if (strcmp(command, "living_room_lights off") == 0)
        {
            printf("Turning living room lights off...\n");
            living_room_lights = 0;
        }
        else if (strcmp(command, "bedroom_lights on") == 0)
        {
            printf("Turning bedroom lights on...\n");
            bedroom_lights = 1;
        }
        else if (strcmp(command, "bedroom_lights off") == 0)
        {
            printf("Turning bedroom lights off...\n");
            bedroom_lights = 0;
        }
        else if (strcmp(command, "bathroom_fan on") == 0)
        {
            printf("Turning bathroom fan on...\n");
            bathroom_fan = 1;
        }
        else if (strcmp(command, "bathroom_fan off") == 0)
        {
            printf("Turning bathroom fan off...\n");
            bathroom_fan = 0;
        }
        else if (strcmp(command, "kitchen_oven on") == 0)
        {
            printf("Turning kitchen oven on...\n");
            kitchen_oven = 1;
        }
        else if (strcmp(command, "kitchen_oven off") == 0)
        {
            printf("Turning kitchen oven off...\n");
            kitchen_oven = 0;
        }
        else if (strcmp(command, "get_temperature room1") == 0)
        {
            printf("The temperature in room 1 is %d degrees Celsius.\n", room1_temp);
        }
        else if (strcmp(command, "get_temperature room2") == 0)
        {
            printf("The temperature in room 2 is %d degrees Celsius.\n", room2_temp);
        }
        else if (strcmp(command, "get_temperature room3") == 0)
        {
            printf("The temperature in room 3 is %d degrees Celsius.\n", room3_temp);
        }
        else if (strcmp(command, "help") == 0)
        {
            printf("Welcome to Smart Home Automation! Here are some available commands:\n");
            printf("- living_room_lights on\n");
            printf("- living_room_lights off\n");
            printf("- bedroom_lights on\n");
            printf("- bedroom_lights off\n");
            printf("- bathroom_fan on\n");
            printf("- bathroom_fan off\n");
            printf("- kitchen_oven on\n");
            printf("- kitchen_oven off\n");
            printf("- get_temperature room1\n");
            printf("- get_temperature room2\n");
            printf("- get_temperature room3\n");
            printf("- exit\n");
        }
        else if (strcmp(command, "exit") != 0)
        {
            printf("I'm sorry, I don't understand that command. Type 'help' for a list of available commands.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}