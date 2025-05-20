//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function prototypes
void turnOnLights(bool, bool, bool, bool);
void turnOffLights(bool, bool, bool, bool);
void openWindows(bool, bool, bool, bool);
void closeWindows(bool, bool, bool, bool);
void turnOnAC(bool);
void turnOffAC(bool);

int main(void)
{
    bool living_room_lights_on = false; //Lights in living room
    bool kitchen_lights_on = false; //Lights in kitchen
    bool bedroom_lights_on = false; //Lights in bedroom
    bool bathroom_lights_on = false; //Lights in bathroom
    bool living_room_windows_open = false; //Living room windows
    bool kitchen_windows_open = false; //Kitchen windows
    bool bedroom_windows_open = false; //Bedroom windows
    bool bathroom_windows_open = false; //Bathroom windows
    bool ac_on = false; //AC status
    int choice; //User's choice
    bool exit = false; //Flag for exiting program

    //Welcome message
    printf("\n\t\tWelcome to Smart Home Automation System!\n");

    //Main menu
    do {
        printf("Please select an option:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Open windows\n");
        printf("4. Close windows\n");
        printf("5. Turn on AC\n");
        printf("6. Turn off AC\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        //Switch case for user's choice
        switch (choice) {
            case 1:
                turnOnLights(living_room_lights_on, kitchen_lights_on, bedroom_lights_on, bathroom_lights_on);
                break;
            case 2:
                turnOffLights(living_room_lights_on, kitchen_lights_on, bedroom_lights_on, bathroom_lights_on);
                break;
            case 3:
                openWindows(living_room_windows_open, kitchen_windows_open, bedroom_windows_open, bathroom_windows_open);
                break;
            case 4:
                closeWindows(living_room_windows_open, kitchen_windows_open, bedroom_windows_open, bathroom_windows_open);
                break;
            case 5:
                turnOnAC(ac_on);
                ac_on = true;
                break;
            case 6:
                turnOffAC(ac_on);
                ac_on = false;
                break;
            case 7:
                printf("Thank you for using Smart Home Automation System.\n");
                exit = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (exit == false); //Loop until user decides to exit

    return 0;
}

//Function to turn on lights
void turnOnLights(bool living_room, bool kitchen, bool bedroom, bool bathroom)
{
    printf("Which lights would you like to turn on?\n");
    printf("1. Living room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (living_room == true) {
                printf("Living room lights are already on.\n");
            } else {
                printf("Turning on living room lights.\n");
                living_room = true;
            }
            break;
        case 2:
            if (kitchen == true) {
                printf("Kitchen lights are already on.\n");
            } else {
                printf("Turning on kitchen lights.\n");
                kitchen = true;
            }
            break;
        case 3:
            if (bedroom == true) {
                printf("Bedroom lights are already on.\n");
            } else {
                printf("Turning on bedroom lights.\n");
                bedroom = true;
            }
            break;
        case 4:
            if (bathroom == true) {
                printf("Bathroom lights are already on.\n");
            } else {
                printf("Turning on bathroom lights.\n");
                bathroom = true;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

//Function to turn off lights
void turnOffLights(bool living_room, bool kitchen, bool bedroom, bool bathroom)
{
    printf("Which lights would you like to turn off?\n");
    printf("1. Living room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (living_room == false) {
                printf("Living room lights are already off.\n");
            } else {
                printf("Turning off living room lights.\n");
                living_room = false;
            }
            break;
        case 2:
            if (kitchen == false) {
                printf("Kitchen lights are already off.\n");
            } else {
                printf("Turning off kitchen lights.\n");
                kitchen = false;
            }
            break;
        case 3:
            if (bedroom == false) {
                printf("Bedroom lights are already off.\n");
            } else {
                printf("Turning off bedroom lights.\n");
                bedroom = false;
            }
            break;
        case 4:
            if (bathroom == false) {
                printf("Bathroom lights are already off.\n");
            } else {
                printf("Turning off bathroom lights.\n");
                bathroom = false;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

//Function to open windows
void openWindows(bool living_room, bool kitchen, bool bedroom, bool bathroom)
{
    printf("Which windows would you like to open?\n");
    printf("1. Living room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (living_room == true) {
                printf("Living room windows are already open.\n");
            } else {
                printf("Opening living room windows.\n");
                living_room = true;
            }
            break;
        case 2:
            if (kitchen == true) {
                printf("Kitchen windows are already open.\n");
            } else {
                printf("Opening kitchen windows.\n");
                kitchen = true;
            }
            break;
        case 3:
            if (bedroom == true) {
                printf("Bedroom windows are already open.\n");
            } else {
                printf("Opening bedroom windows.\n");
                bedroom = true;
            }
            break;
        case 4:
            if (bathroom == true) {
                printf("Bathroom windows are already open.\n");
            } else {
                printf("Opening bathroom windows.\n");
                bathroom = true;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

//Function to close windows
void closeWindows(bool living_room, bool kitchen, bool bedroom, bool bathroom)
{
    printf("Which windows would you like to close?\n");
    printf("1. Living room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (living_room == false) {
                printf("Living room windows are already closed.\n");
            } else {
                printf("Closing living room windows.\n");
                living_room = false;
            }
            break;
        case 2:
            if (kitchen == false) {
                printf("Kitchen windows are already closed.\n");
            } else {
                printf("Closing kitchen windows.\n");
                kitchen = false;
            }
            break;
        case 3:
            if (bedroom == false) {
                printf("Bedroom windows are already closed.\n");
            } else {
                printf("Closing bedroom windows.\n");
                bedroom = false;
            }
            break;
        case 4:
            if (bathroom == false) {
                printf("Bathroom windows are already closed.\n");
            } else {
                printf("Closing bathroom windows.\n");
                bathroom = false;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

//Function to turn on AC
void turnOnAC(bool ac_on)
{
    if (ac_on == true) {
        printf("AC is already on.\n");
    } else {
        printf("Turning on AC.\n");
        ac_on = true;
    }
}

//Function to turn off AC
void turnOffAC(bool ac_on)
{
    if (ac_on == false) {
        printf("AC is already off.\n");
    } else {
        printf("Turning off AC.\n");
        ac_on = false;
    }
}