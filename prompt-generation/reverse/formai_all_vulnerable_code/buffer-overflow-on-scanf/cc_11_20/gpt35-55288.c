//FormAI DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

// Define macros for appliances
#define LIGHTS 1
#define TV 2
#define AC 3

// Define variables for appliance states
bool lights_on = false;
bool tv_on = false;
bool ac_on = false;

int main() {
    printf("Welcome to the Smart Home Automation System!\n");

    // Loop until the user enters 'q' to quit
    char input;
    while(true) {
        printf("\nEnter the number of the appliance you would like to control (1: Lights, 2: TV, 3: AC) or q to quit: ");
        scanf(" %c", &input);

        // Turn off all appliances and exit program when input is 'q'
        if(input == 'q') {
            printf("\nTurning off all appliances...\n");
            if(lights_on) {
                printf("Lights turned off.\n");
                lights_on = false;
            }
            if(tv_on) {
                printf("TV turned off.\n");
                tv_on = false;
            }
            if(ac_on) {
                printf("AC turned off.\n");
                ac_on = false;
            }
            printf("Goodbye!\n");
            return 0;
        }

        // Turn on/off lights
        if(input == '1') {
            if(lights_on) {
                printf("Lights turned off.\n");
                lights_on = false;
            }
            else {
                printf("Lights turned on.\n");
                lights_on = true;
            }
        }

        // Turn on/off TV
        if(input == '2') {
            if(tv_on) {
                printf("TV turned off.\n");
                tv_on = false;
            }
            else {
                printf("TV turned on.\n");
                tv_on = true;
            }
        }

        // Turn on/off AC
        if(input == '3') {
            if(ac_on) {
                printf("AC turned off.\n");
                ac_on = false;
            }
            else {
                printf("AC turned on.\n");
                ac_on = true;
            }
        }
    }
}