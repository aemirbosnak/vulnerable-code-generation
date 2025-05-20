//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining constants
#define LIVING_ROOM 1
#define BEDROOM 2
#define KITCHEN 3
#define BATHROOM 4

// Defining variables
bool livingRoomLight = false;
bool bedRoomLight = false;
bool kitchenLight = false;
bool bathroomLight = false;
bool acLivingRoom = false;
bool acBedroom = false;

// Function to turn ON living room light
void turnOnLivingRoomLight(){
    livingRoomLight = true;
    printf("Living room light turned ON.\n");
}

// Function to turn OFF living room light
void turnOffLivingRoomLight(){
    livingRoomLight = false;
    printf("Living room light turned OFF.\n");
}

// Function to turn ON bedroom light
void turnOnBedroomLight(){
    bedRoomLight = true;
    printf("Bedroom light turned ON.\n");
}

// Function to turn OFF bedroom light
void turnOffBedroomLight(){
    bedRoomLight = false;
    printf("Bedroom light turned OFF.\n");
}

// Function to turn ON kitchen light
void turnOnKitchenLight(){
    kitchenLight = true;
    printf("Kitchen light turned ON.\n");
}

// Function to turn OFF kitchen light
void turnOffKitchenLight(){
    kitchenLight = false;
    printf("Kitchen light turned OFF.\n");
}

// Function to turn ON bathroom light
void turnOnBathroomLight(){
    bathroomLight = true;
    printf("Bathroom light turned ON.\n");
}

// Function to turn OFF bathroom light
void turnOffBathroomLight(){
    bathroomLight = false;
    printf("Bathroom light turned OFF.\n");
}

// Function to turn ON living room AC
void turnOnLivingRoomAC(){
    acLivingRoom = true;
    printf("Living room AC turned ON.\n");
}

// Function to turn OFF living room AC
void turnOffLivingRoomAC(){
    acLivingRoom = false;
    printf("Living room AC turned OFF.\n");
}

// Function to turn ON bedroom AC
void turnOnBedroomAC(){
    acBedroom = true;
    printf("Bedroom AC turned ON.\n");
}

// Function to turn OFF bedroom AC
void turnOffBedroomAC(){
    acBedroom = false;
    printf("Bedroom AC turned OFF.\n");
}

// Function to check the status of home automation devices
void checkStatus(){
    printf("\n-----CURRENT STATUS-----\n");
    printf("Living Room Light: %s\n", livingRoomLight ? "ON" : "OFF");
    printf("Bedroom Light: %s\n", bedRoomLight ? "ON" : "OFF");
    printf("Kitchen Light: %s\n", kitchenLight ? "ON" : "OFF");
    printf("Bathroom Light: %s\n", bathroomLight ? "ON" : "OFF");
    printf("Living Room AC: %s\n", acLivingRoom ? "ON" : "OFF");
    printf("Bedroom AC: %s\n", acBedroom ? "ON" : "OFF");
    printf("------------------------\n");
}

// Main function
int main()
{
    int option, room;
    bool exitFlag = false;

    printf("\n-------------------\n");
    printf("SMART HOME AUTOMATION\n");
    printf("-------------------\n");

    while(!exitFlag){
        printf("\nEnter your option:\n");
        printf("1 - Turn ON a device\n");
        printf("2 - Turn OFF a device\n");
        printf("3 - Check device status\n");
        printf("4 - Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter the room number:\n");
                printf("1 - Living Room\n");
                printf("2 - Bedroom\n");
                printf("3 - Kitchen\n");
                printf("4 - Bathroom\n");

                scanf("%d", &room);

                switch(room){
                    case LIVING_ROOM:
                        printf("\nEnter the device to turn ON:\n");
                        printf("1 - Living Room Light\n");
                        printf("2 - Living Room AC\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOnLivingRoomLight(); break;
                            case 2: turnOnLivingRoomAC(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case BEDROOM:
                        printf("\nEnter the device to turn ON:\n");
                        printf("1 - Bedroom Light\n");
                        printf("2 - Bedroom AC\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOnBedroomLight(); break;
                            case 2: turnOnBedroomAC(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case KITCHEN:
                        printf("\nEnter the device to turn ON:\n");
                        printf("1 - Kitchen Light\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOnKitchenLight(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case BATHROOM:
                        printf("\nEnter the device to turn ON:\n");
                        printf("1 - Bathroom Light\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOnBathroomLight(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    default:
                        printf("Invalid room number.\n");
                        break;
                }

                break;

            case 2:
                printf("\nEnter the room number:\n");
                printf("1 - Living Room\n");
                printf("2 - Bedroom\n");
                printf("3 - Kitchen\n");
                printf("4 - Bathroom\n");

                scanf("%d", &room);

                switch(room){
                    case LIVING_ROOM:
                        printf("\nEnter the device to turn OFF:\n");
                        printf("1 - Living Room Light\n");
                        printf("2 - Living Room AC\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOffLivingRoomLight(); break;
                            case 2: turnOffLivingRoomAC(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case BEDROOM:
                        printf("\nEnter the device to turn OFF:\n");
                        printf("1 - Bedroom Light\n");
                        printf("2 - Bedroom AC\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOffBedroomLight(); break;
                            case 2: turnOffBedroomAC(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case KITCHEN:
                        printf("\nEnter the device to turn OFF:\n");
                        printf("1 - Kitchen Light\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOffKitchenLight(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    case BATHROOM:
                        printf("\nEnter the device to turn OFF:\n");
                        printf("1 - Bathroom Light\n");

                        scanf("%d", &option);

                        switch(option){
                            case 1: turnOffBathroomLight(); break;
                            default: printf("Invalid option.\n"); break;
                        }

                        break;

                    default:
                        printf("Invalid room number.\n");
                        break;
                }

                break;

            case 3:
                checkStatus();
                break;

            case 4:
                exitFlag = true;
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    printf("\nThank you for using the Smart Home Automation system.\n");

    return 0;
}