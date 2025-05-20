//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void init();
void displayMenu();
bool handleUserInput(char);

// Smart Home Devices
bool livingRoomLight = false;
bool fan = false;
bool tv = false;
bool frontDoor = false;
bool garageDoor = false;

int main() {
    init();

    while (true) {
        displayMenu();

        char userInput;
        scanf(" %c", &userInput);

        if (!handleUserInput(userInput)) {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}

void init() {
    printf("Welcome to the Smart Home Automation System\n\n");
}

void displayMenu() {
    printf("Please select an option below:\n");
    printf("[1] Turn %s the Living Room Light\n", livingRoomLight ? "Off" : "On");
    printf("[2] Turn %s the Fan\n", fan ? "Off" : "On");
    printf("[3] Turn %s the TV\n", tv ? "Off" : "On");
    printf("[4] Lock %s the Front Door\n", frontDoor ? "the" : "Un");
    printf("[5] %s the Garage Door\n", garageDoor ? "Close" : "Open");
    printf("[6] Exit\n\n");
}

bool handleUserInput(char userInput) {
    switch (userInput) {
        case '1':
            livingRoomLight = !livingRoomLight;
            printf("The Living Room Light is now turned %s\n\n", livingRoomLight ? "On" : "Off");
            return true;
        case '2':
            fan = !fan;
            printf("The Fan is now turned %s\n\n", fan ? "On" : "Off");
            return true;
        case '3':
            tv = !tv;
            printf("The TV is now turned %s\n\n", tv ? "On" : "Off");
            return true;
        case '4':
            frontDoor = !frontDoor;
            printf("The Front Door is now %s\n\n", frontDoor ? "locked" : "unlocked");
            return true;
        case '5':
            garageDoor = !garageDoor;
            printf("The Garage Door is now %s\n\n", garageDoor ? "closed" : "open");
            return true;
        case '6':
            printf("Thank you for using the Smart Home Automation System.\n");
            exit(EXIT_SUCCESS);
    }

    return false;
}