//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 10 // Maximum number of lights in the smart home

// Function to turn on/off a specific light
void toggleLight(bool *lights, int lightNumber)
{
    if(lights[lightNumber])
    {
        printf("Turning off Light %d\n", lightNumber + 1);
        lights[lightNumber] = false;
    }
    else
    {
        printf("Turning on Light %d\n", lightNumber + 1);
        lights[lightNumber] = true;
    }
}

// Function to turn on/off all lights
void toggleAllLights(bool *lights, int numLights)
{
    bool allOn = true;

    for(int i = 0; i < numLights; i++)
    {
        if(lights[i] == false)
        {
            allOn = false;
        }
    }

    if(allOn)
    {
        printf("Turning off all lights\n");
        for(int i = 0; i < numLights; i++)
        {
            lights[i] = false;
        }
    }
    else
    {
        printf("Turning on all lights\n");
        for(int i = 0; i < numLights; i++)
        {
            lights[i] = true;
        }
    }
}

int main()
{
    bool lights[MAX_LIGHTS] = {false}; // Initialize all lights to be off

    int numLights;

    printf("How many lights do you have in your smart home? ");
    scanf("%d", &numLights);

    if(numLights > MAX_LIGHTS)
    {
        printf("Error: Maximum number of lights allowed is %d\n", MAX_LIGHTS);
        return 1;
    }

    // Menu for light control
    int choice;

    do {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Toggle a specific light\n");
        printf("2. Toggle all lights\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                {
                    int lightNumber;
                    printf("Which light do you want to toggle? ");
                    scanf("%d", &lightNumber);
                    if(lightNumber > numLights || lightNumber < 1)
                    {
                        printf("Invalid light number\n");
                    }
                    else
                    {
                        toggleLight(lights, lightNumber - 1);
                    }
                    break;
                }
            case 2:
                {
                    toggleAllLights(lights, numLights);
                    break;
                }
            case 3:
                {
                    printf("Goodbye!\n");
                    break;
                }
            default:
                {
                    printf("Invalid choice\n");
                    break;
                }
        }
    } while(choice != 3);

    return 0;
}