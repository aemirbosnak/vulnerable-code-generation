//FormAI DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdbool.h>
// Define constants for each room's light behavior 
#define LIVING_ROOM 0
#define BEDROOM 1
#define OFFICE 2
#define KITCHEN 3

// Define constants for each light's behavior
#define ON 1
#define OFF 0

// Define a function to turn on/off specific light
void turnLightOnOff(int room, int light, bool status, bool isVoiceCommand) {
    if(status == ON) {
        if(isVoiceCommand) {
            printf("Turning on light %d in room %d.\n", light, room);
        } else {
            printf("Light %d in room %d turned on via app.\n", light, room);
        }
    } else {
        if(isVoiceCommand) {
            printf("Turning off light %d in room %d.\n", light, room);
        } else {
            printf("Light %d in room %d turned off via app.\n", light, room);
        }
    }
}

int main(void) {
    int input;
    bool isVoiceCommand = false;
    printf("***SMART HOME CONTROL SYSTEM***\n");
    printf("Which room's light you want to turn on or off? (0-Living room, 1-Bedroom, 2-Office, 3-Kitchen) : ");
    scanf("%d", &input);

    switch(input) {
        case LIVING_ROOM:
            printf("Which light you want to turn on or off in Living room? (0, 1, 2) : ");
            scanf("%d", &input);
            if(input >= 0 && input <=2) {
                printf("Enter 1 to turn on or 0 to turn off the light: ");
                scanf("%d", &input);
                if(input == ON || input == OFF) {
                    turnLightOnOff(LIVING_ROOM, input, input, isVoiceCommand);
                } else {
                    printf("Invalid input. Please select valid input from 0 and 1.\n");
                }
            } else {
                printf("Invalid input. Please select valid input from 0 to 2.\n");
            }
            break;

        case BEDROOM:
            printf("Which light you want to turn on or off in Bedroom? (0, 1) : ");
            scanf("%d", &input);
            if(input >= 0 && input <=1) {
                printf("Enter 1 to turn on or 0 to turn off the light: ");
                scanf("%d", &input);
                if(input == ON || input == OFF) {
                    turnLightOnOff(BEDROOM, input, input, isVoiceCommand);
                } else {
                    printf("Invalid input. Please select valid input from 0 and 1.\n");
                }
            } else {
                printf("Invalid input. Please select valid input from 0 to 1.\n");
            }
            break;

        case OFFICE:
            printf("Which light you want to turn on or off in Office? (0, 1) : ");
            scanf("%d", &input);
            if(input >= 0 && input <=1) {
                printf("Enter 1 to turn on or 0 to turn off the light: ");
                scanf("%d", &input);
                if(input == ON || input == OFF) {
                    turnLightOnOff(OFFICE, input, input, isVoiceCommand);
                } else {
                    printf("Invalid input. Please select valid input from 0 and 1.\n");
                }
            } else {
                printf("Invalid input. Please select valid input from 0 to 1.\n");
            }
            break;

        case KITCHEN:
            printf("Which light you want to turn on or off in Kitchen? (0, 1) : ");
            scanf("%d", &input);
            if(input >= 0 && input <=1) {
                printf("Enter 1 to turn on or 0 to turn off the light: ");
                scanf("%d", &input);
                if(input == ON || input == OFF) {
                    turnLightOnOff(KITCHEN, input, input, isVoiceCommand);
                } else {
                    printf("Invalid input. Please select valid input from 0 and 1.\n");
                }
            } else {
                printf("Invalid input. Please select valid input from 0 to 1.\n");
            }
            break;

        default:
            printf("Invalid input. Please select valid input from 0 to 3.\n");
            break;
    }
    
    return 0;
}