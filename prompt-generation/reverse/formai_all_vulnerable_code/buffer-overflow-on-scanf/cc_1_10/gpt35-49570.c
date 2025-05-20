//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    int light_state = 0;
    char user_input[10];

    // Print welcome message
    printf("Welcome to your smart home light control system!\n");

    // Loop to receive user input
    while(1)
    {
        printf("Type \"on\" or \"off\" to control the light: ");
        scanf("%s", user_input);

        // Perform action based on user input
        if(strcmp(user_input, "on") == 0)
        {
            // Turn light on if not already on
            if(light_state == 0)
            {
                printf("Turning light on!\n");
                light_state = 1;
            }
            else
            {
                printf("Light is already on!\n");
            }
        }
        else if(strcmp(user_input, "off") == 0)
        {
            // Turn light off if not already off
            if(light_state == 1)
            {
                printf("Turning light off!\n");
                light_state = 0;
            }
            else
            {
                printf("Light is already off!\n");
            }
        }
        else
        {
            printf("Invalid input, please try again!\n");
        }
    }
 
    return 0;
}