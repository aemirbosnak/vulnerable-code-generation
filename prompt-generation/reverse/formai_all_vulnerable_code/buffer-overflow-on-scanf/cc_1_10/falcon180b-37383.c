//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: modular
#include<stdio.h>

//Function to turn on the light
void TurnOnLight()
{
    printf("Light is turned on\n");
}

//Function to turn off the light
void TurnOffLight()
{
    printf("Light is turned off\n");
}

//Function to toggle the light
void ToggleLight()
{
    int lightStatus;
    printf("Enter the current status of light (1 for on, 0 for off): ");
    scanf("%d", &lightStatus);
    if(lightStatus == 1)
    {
        TurnOffLight();
    }
    else
    {
        TurnOnLight();
    }
}

//Main function to control the light
int main()
{
    int choice;
    while(1)
    {
        printf("Enter your choice:\n1. Turn on the light\n2. Turn off the light\n3. Toggle the light\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                TurnOnLight();
                break;
            case 2:
                TurnOffLight();
                break;
            case 3:
                ToggleLight();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}