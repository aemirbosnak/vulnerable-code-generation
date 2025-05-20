//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

// Function to turn the light on
void turnOn()
{
    printf("Light turned on\n");
}

// Function to turn the light off
void turnOff()
{
    printf("Light turned off\n");
}

int main()
{
    bool light_state = false; // Initialize light to be off
    int choice; // User input for action to perform on light

    // Loop to simulate continuous running of the program
    while (true)
    {
        printf("\nEnter your choice:\n");
        printf("1. Turn the light on\n");
        printf("2. Turn the light off\n");
        printf("3. Exit\n");

        // Take user input for choice of action on light
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (light_state == false)
                {
                    turnOn();
                    light_state = true;
                }
                else
                {
                    printf("Light is already turned on\n");
                }
                break;
            case 2:
                if (light_state == true)
                {
                    turnOff();
                    light_state = false;
                }
                else
                {
                    printf("Light is already turned off\n");
                }
                break;
            case 3:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }
    return 0;
}