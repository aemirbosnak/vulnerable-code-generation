//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int lights_on = 0;
    char command[20];

    printf("Welcome to the Smart Home Light Control System!\n");

    while(1)
    {
        printf("Enter a command: ");
        scanf("%s", command);

        if(strcmp(command, "turn on") == 0)
        {
            lights_on = 1;
            printf("Lights are now on!\n");
        }
        else if(strcmp(command, "turn off") == 0)
        {
            lights_on = 0;
            printf("Lights are now off!\n");
        }
        else if(strcmp(command, "status") == 0)
        {
            if(lights_on == 1)
            {
                printf("Lights are currently on!\n");
            }
            else
            {
                printf("Lights are currently off!\n");
            }
        }
        else if(strcmp(command, "party time") == 0)
        {
            printf("Woooo! It's party time!\n");
            for(int i = 0; i < 5; i++)
            {
                printf("Lights are flashing!\n");
                lights_on = !lights_on;
                sleep(1);
            }
            printf("Party's over. Lights are back to their original state.\n");
        }
        else if(strcmp(command, "help") == 0)
        {
            printf("Here are the available commands:\n");
            printf("- turn on: turns the lights on\n");
            printf("- turn off: turns the lights off\n");
            printf("- status: shows the current state of the lights\n");
            printf("- party time: makes the lights flash for a party!\n");
            printf("- help: shows this help message\n");
        }
        else
        {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}