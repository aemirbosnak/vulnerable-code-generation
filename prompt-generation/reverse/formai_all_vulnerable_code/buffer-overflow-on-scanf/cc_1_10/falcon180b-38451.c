//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIGHTS 1
#define FAN 2
#define AC 3
#define TV 4
#define CURTAINS 5

#define ON 1
#define OFF 0

int main() {
    int choice;
    int device;
    int state;

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Please choose a device:\n");
    printf("1. Lights\n");
    printf("2. Fan\n");
    printf("3. AC\n");
    printf("4. TV\n");
    printf("5. Curtains\n");
    scanf("%d", &device);

    switch(device) {
        case LIGHTS:
            printf("Please choose a state:\n");
            printf("1. On\n");
            printf("2. Off\n");
            scanf("%d", &state);

            if(state == ON) {
                system("echo 'Turning lights on...'");
            } else if(state == OFF) {
                system("echo 'Turning lights off...'");
            } else {
                printf("Invalid state\n");
            }

            break;
        case FAN:
            // Add code for fan here
            break;
        case AC:
            // Add code for AC here
            break;
        case TV:
            // Add code for TV here
            break;
        case CURTAINS:
            // Add code for curtains here
            break;
        default:
            printf("Invalid device\n");
            break;
    }

    printf("Thank you for using the Smart Home Automation System!\n");

    return 0;
}