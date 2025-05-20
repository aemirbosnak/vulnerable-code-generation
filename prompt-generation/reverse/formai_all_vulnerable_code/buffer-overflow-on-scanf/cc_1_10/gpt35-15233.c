//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>
#include <stdbool.h>

// Define constants for devices
#define LIGHT 0
#define FAN 1
#define COFFEE_MACHINE 2
#define AC 3
#define TV 4

// Define constants for commands
#define TURN_ON 1
#define TURN_OFF 0

// Function for controlling devices
void controlDevice(int device, int command) {
    switch(device) {
        case LIGHT:
            if(command == TURN_ON) {
                printf("Turning on the lights...\n");
            }
            else {
                printf("Turning off the lights...\n");
            }
            break;
        case FAN:
            if(command == TURN_ON) {
                printf("Turning on the fan...\n");
            }
            else {
                printf("Turning off the fan...\n");
            }
            break;
        case COFFEE_MACHINE:
            if(command == TURN_ON) {
                printf("Making coffee...\n");
            }
            else {
                printf("Stopping coffee machine...\n");
            }
            break;
        case AC:
            if(command == TURN_ON) {
                printf("Turning on the AC...\n");
            }
            else {
                printf("Turning off the AC...\n");
            }
            break;
        case TV:
            if(command == TURN_ON) {
                printf("Turning on the TV...\n");
            }
            else {
                printf("Turning off the TV...\n");
            }
            break;
        default:
            printf("Invalid device\n");
    }
}

int main() {
    int input = 0;
    bool running = true;

    printf("Welcome to your smart home automation system!\n");

    while(running) {
        printf("What device would you like to control?\n");
        printf("0 - Light\n1 - Fan\n2 - Coffee machine\n3 - AC\n4 - TV\n");
        scanf("%d", &input);

        if(input < 0 || input > 4) {
            printf("Invalid device selected, please try again.\n");
        }
        else {
            int command = -1;
            printf("Would you like to turn %d on (1) or off (0)?\n", input);
            scanf("%d", &command);

            if(command != TURN_ON && command != TURN_OFF) {
                printf("Invalid command selected, please try again.\n");
            }
            else {
                controlDevice(input, command);
            }
        }

        printf("Would you like to control another device? (y/n)\n");
        char answer;
        scanf(" %c", &answer);
        if(answer == 'n' || answer == 'N') {
            running = false;
        }
    }

    printf("Thank you for using your smart home automation system!\n");

    return 0;
}