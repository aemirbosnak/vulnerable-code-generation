//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void turnOn(int *);
void turnOff(int *);
void dim(int *, int);

int main()
{
    int lightIntensity = 0;
    bool isOn = false;

    while(true)
    {
        printf("Enter 1 to turn on the light, 2 to turn off the light, or 3 to dim the light: ");
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                turnOn(&lightIntensity);
                isOn = true;
                break;
            case 2:
                turnOff(&lightIntensity);
                isOn = false;
                break;
            case 3:
                if(isOn)
                {
                    printf("Enter intensity level (1-10): ");
                    int intensity;
                    scanf("%d", &intensity);
                    dim(&lightIntensity, intensity);
                }
                else
                {
                    printf("The light is currently off. Please turn it on before dimming.\n");
                }
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Print current light status
        if(isOn)
        {
            printf("The light is currently on at intensity level %d.\n", lightIntensity);
        }
        else
        {
            printf("The light is currently off.\n");
        }
    }
    return 0;
}

void turnOn(int *intensity)
{
    *intensity = 10;
}

void turnOff(int *intensity)
{
    *intensity = 0;
}

void dim(int *intensity, int level)
{
    *intensity = level;
}