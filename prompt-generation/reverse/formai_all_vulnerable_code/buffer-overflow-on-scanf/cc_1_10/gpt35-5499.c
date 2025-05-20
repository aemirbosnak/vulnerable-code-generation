//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
// Smart Home Light Control Example
// Written in the style of Donald Knuth
// By [Your Name Here], [Current Date]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Global Variables
int light_status = LIGHT_OFF;

// Function Prototypes
void turn_light_on(void);
void turn_light_off(void);

// Main Function
int main(void)
{
    printf("Welcome to the Smart Home Light Control Example Program\n");
    printf("-----------------------------------------------\n");

    int option;

    while (true)
    {
        printf("Options:\n");
        printf("1. Turn Light On\n");
        printf("2. Turn Light Off\n");
        printf("3. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                turn_light_on();
                break;
            case 2:
                turn_light_off();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}

// Function to turn the light on
void turn_light_on(void)
{
    if (light_status == LIGHT_ON)
    {
        printf("The light is already on!\n");
    }
    else
    {
        light_status = LIGHT_ON;
        printf("The light is now on.\n");
    }
}

// Function to turn the light off
void turn_light_off(void)
{
    if (light_status == LIGHT_OFF)
    {
        printf("The light is already off!\n");
    }
    else
    {
        light_status = LIGHT_OFF;
        printf("The light is now off.\n");
    }
}