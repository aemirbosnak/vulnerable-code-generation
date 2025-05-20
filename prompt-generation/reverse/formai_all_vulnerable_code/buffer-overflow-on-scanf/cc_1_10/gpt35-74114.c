//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* Smart Home Light Control Example Program */

/* Defining the states of the light bulb */
#define NO_LIGHT 0
#define DIM_LIGHT 1
#define FULL_LIGHT 2

/* Defining the available commands */
#define TURN_OFF 0
#define TURN_ON_DIM 1
#define TURN_ON_FULL 2

/* Function prototypes */
void turnOff(int *currentState);
void turnOnDim(int *currentState);
void turnOnFull(int *currentState);
void printState(int currentState);

/* Main function */
int main()
{
    int currentState = NO_LIGHT;
    int command;

    /* Infinite loop to receive commands from user */
    while (1)
    {
        printf("Enter command: ");
        scanf("%d", &command);

        /* Switch case statement to execute commands depending on input */
        switch (command)
        {
        case TURN_OFF:
            turnOff(&currentState);
            break;
        case TURN_ON_DIM:
            turnOnDim(&currentState);
            break;
        case TURN_ON_FULL:
            turnOnFull(&currentState);
            break;
        default:
            printf("Invalid command\n");
            break;
        }

        /* Print current state of light bulb */
        printState(currentState);
    }

    return 0;
}

/* Function to turn off the light bulb */
void turnOff(int *currentState)
{
    *currentState = NO_LIGHT;
}

/* Function to turn on the light bulb with dim light */
void turnOnDim(int *currentState)
{
    *currentState = DIM_LIGHT;
}

/* Function to turn on the light bulb with full light */
void turnOnFull(int *currentState)
{
    *currentState = FULL_LIGHT;
}

/* Function to print the current state of the light bulb */
void printState(int currentState)
{
    printf("Current state: ");
    switch (currentState)
    {
    case NO_LIGHT:
        printf("No light\n");
        break;
    case DIM_LIGHT:
        printf("Dim light\n");
        break;
    case FULL_LIGHT:
        printf("Full light\n");
        break;
    default:
        printf("Unknown state\n");
        break;
    }
}