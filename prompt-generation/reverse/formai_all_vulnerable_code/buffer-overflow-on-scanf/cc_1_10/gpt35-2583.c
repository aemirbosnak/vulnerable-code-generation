//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declare variables for each light switch
bool livingRoomLights = false;
bool kitchenLights = false;
bool bedroomLights = false;
bool bathroomLights = false;
bool outdoorLights = false;

//prototype function for light control
void light_control(int switchNum, bool *lightsPtr);

int main()
{
    //declare variables
    int switchNum;
    char choice;

    //display welcome message and options
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Which light would you like to turn on or off?\n");
    printf("1. Living Room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("5. Outdoor\n");

    //ask for user input for light switch number and desired action
    do
    {
        printf("\nEnter the switch number (1-5): ");
        scanf("%d", &switchNum);

        printf("Enter 'on' or 'off': ");
        scanf(" %c", &choice);

        //determine desired action and call light_control function
        switch (choice)
        {
        case 'on':
            light_control(switchNum, &livingRoomLights);
            break;
        case 'off':
            light_control(switchNum, &kitchenLights);
            break;
        default:
            printf("Invalid input.\n");
        }

        //ask user if they would like to continue using the system
        printf("\nWould you like to control another light? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using the Smart Home Light Control System!\n");

    return 0;
}

void light_control(int switchNum, bool *lightsPtr)
{
    //check if light is currently on or off and toggle accordingly
    if (*lightsPtr == false)
    {
        *lightsPtr = true;
        printf("Switch %d is now on.\n", switchNum);
    }
    else
    {
        *lightsPtr = false;
        printf("Switch %d is now off.\n", switchNum);
    }
}