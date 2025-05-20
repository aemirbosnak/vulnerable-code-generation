//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LIGHTS 10 //Number of lights in the house

int main()
{
    int lights_status[NUM_LIGHTS] = {0}; //Array to hold the status of each light (0 = off, 1 = on)
    char user_input[10]; //Variable to hold user input
    int light_num; //Variable to hold the light number
    int i; //Counter variable for loops

    srand(time(NULL)); //Seed the random number generator

    printf("Welcome to the Smart Home Light Control System!\n");

    while(1)
    {
        printf("\n");

        for(i = 0; i < NUM_LIGHTS; i++)
        {
            printf("Light %d is %s\n", i+1, (lights_status[i]) ? "on" : "off");
        }

        printf("\nEnter a command (type 'help' for a list of commands): ");
        fgets(user_input, 10, stdin); //Get user input

        if(user_input[0] == 'h' && user_input[1] == 'e' && user_input[2] == 'l' && user_input[3] == 'p')
        {
            printf("\nCommands:\n");
            printf("on [light number]: turn a light on\n");
            printf("off [light number]: turn a light off\n");
            printf("random: turn a random light on\n");
            printf("status: show the status of all lights\n");
            printf("exit: exit the program\n");
        }
        else if(user_input[0] == 'o' && user_input[1] == 'n')
        {
            sscanf(user_input, "on %d", &light_num); //Extract light number from user input

            if(light_num > 0 && light_num <= NUM_LIGHTS)
            {
                lights_status[light_num-1] = 1; //Turn the selected light on
                printf("Light %d turned on.\n", light_num);
            }
            else
            {
                printf("Invalid light number.\n");
            }
        }
        else if(user_input[0] == 'o' && user_input[1] == 'f' && user_input[2] == 'f')
        {
            sscanf(user_input, "off %d", &light_num); //Extract light number from user input

            if(light_num > 0 && light_num <= NUM_LIGHTS)
            {
                lights_status[light_num-1] = 0; //Turn the selected light off
                printf("Light %d turned off.\n", light_num);
            }
            else
            {
                printf("Invalid light number.\n");
            }
        }
        else if(user_input[0] == 'r' && user_input[1] == 'a' && user_input[2] == 'n' && user_input[3] == 'd' && user_input[4] == 'o' && user_input[5] == 'm')
        {
            light_num = rand() % NUM_LIGHTS + 1; //Select a random light
            lights_status[light_num-1] = 1; //Turn the selected light on
            printf("Light %d turned on.\n", light_num);
        }
        else if(user_input[0] == 's' && user_input[1] == 't' && user_input[2] == 'a' && user_input[3] == 't' && user_input[4] == 'u' && user_input[5] == 's')
        {
            for(i = 0; i < NUM_LIGHTS; i++)
            {
                printf("Light %d is %s\n", i+1, (lights_status[i]) ? "on" : "off");
            }
        }
        else if(user_input[0] == 'e' && user_input[1] == 'x' && user_input[2] == 'i' && user_input[3] == 't')
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Unknown command.\n");
        }
    }

    return 0;
}