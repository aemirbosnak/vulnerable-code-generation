//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
//The Adventure of the Smart Home Automation
//Written by Chatbot 
//Date: September 21, 2021

#include <stdio.h>

int main() {

    //Declare and initialize variables for the current room
    char currentRoom[20] = "Living Room";
    int lightStatus = 0;
    int temp = 70;

    //Print an introduction to the program
    printf("Welcome to the adventure of the Smart Home Automation!\n\n");
    printf("You are currently in the %s.\n", currentRoom);

    //Start the interactive portion of the program
    printf("What would you like to do?\n");
    printf("1. Turn on/off the lights\n");
    printf("2. Adjust the temperature\n");
    printf("3. Move to a different room\n");

    int choice;
    scanf("%d", &choice);

    //Handle the user's choice
    switch (choice) {

        case 1: //Turn on/off the lights
            if (lightStatus == 0) {
                printf("You turn on the lights.\n");
                lightStatus = 1;
            }
            else {
                printf("You turn off the lights.\n");
                lightStatus = 0;
            }
            break;

        case 2: //Adjust the temperature
            printf("What temperature would you like to set?\n");
            scanf("%d", &temp);
            printf("You set the temperature to %d degrees.\n", temp);
            break;

        case 3: //Move to a different room
            printf("Where would you like to go?\n");
            printf("1. Kitchen\n");
            printf("2. Bedroom\n");
            printf("3. Bathroom\n");

            int roomChoice;
            scanf("%d", &roomChoice);

            //Change the current room based on the user's choice
            switch (roomChoice) {

                case 1:
                    printf("You move to the Kitchen.\n");
                    strcpy(currentRoom, "Kitchen");
                    break;

                case 2:
                    printf("You move to the Bedroom.\n");
                    strcpy(currentRoom, "Bedroom");
                    break;

                case 3:
                    printf("You move to the Bathroom.\n");
                    strcpy(currentRoom, "Bathroom");
                    break;

                default:
                    printf("Invalid choice.\n");
                    break;

            }

            break;

        default:
            printf("Invalid choice.\n");
            break;

    }

    //Print the current status of the room
    printf("\nCurrent Room: %s\n", currentRoom);
    if (lightStatus == 0) {
        printf("Lights are off.\n");
    }
    else {
        printf("Lights are on.\n");
    }
    printf("The temperature is set to %d degrees.\n", temp);

    return 0;
}