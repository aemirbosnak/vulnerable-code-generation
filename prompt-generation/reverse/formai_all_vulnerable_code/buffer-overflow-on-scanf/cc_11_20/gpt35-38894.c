//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

//Defining the initial state of the lights
bool livingRoomLight = false;
bool bedroomLight = false;
bool bathroomLight = false;
bool kitchenLight = false;

int main() {
    //Printing Welcome Message
    printf("Welcome to Smart Home, your personal assistant for lights control!\n\n");

    //Displaying the available options
    printf("Select an option:\n");
    printf("1. Living Room Light\n");
    printf("2. Bedroom Light\n");
    printf("3. Bathroom Light\n");
    printf("4. Kitchen Light\n\n");

    //Getting the user's choice
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    //Checking the selected option and turning the corresponding light on/off
    switch (choice) {
        case 1:
            if(livingRoomLight) {
                livingRoomLight = false;
                printf("Living Room Light turned off.\n");
            }
            else {
                livingRoomLight = true;
                printf("Living Room Light turned on.\n");
            }
            break;

        case 2:
            if(bedroomLight) {
                bedroomLight = false;
                printf("Bedroom Light turned off.\n");
            }
            else {
                bedroomLight = true;
                printf("Bedroom Light turned on.\n");
            }
            break;

        case 3:
            if(bathroomLight) {
                bathroomLight = false;
                printf("Bathroom Light turned off.\n");
            }
            else {
                bathroomLight = true;
                printf("Bathroom Light turned on.\n");
            }
            break;

        case 4:
            if(kitchenLight) {
                kitchenLight = false;
                printf("Kitchen Light turned off.\n");
            }
            else {
                kitchenLight = true;
                printf("Kitchen Light turned on.\n");
            }
            break;

        default:
            printf("Invalid choice. Please select again.\n");
            break;
    }

    //Printing the final state of the lights
    printf("\nCurrent Light status:\n");
    printf("Living Room Light: %s\n", livingRoomLight ? "ON" : "OFF");
    printf("Bedroom Light: %s\n", bedroomLight ? "ON" : "OFF");
    printf("Bathroom Light: %s\n", bathroomLight ? "ON" : "OFF");
    printf("Kitchen Light: %s\n", kitchenLight ? "ON" : "OFF");

    return 0;
}