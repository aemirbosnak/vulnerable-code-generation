//FormAI DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isHome = true; // flag for whether someone is present in the home or not
    bool haveLightsOn = false; // flag for whether lights are on or not
    bool haveACOn = false; // flag for whether AC is on or not

    // initial state of the home
    printf("Welcome to your Smart Home Automation system!\n");
    printf("All lights and AC are turned off. Let's get started!\n\n");

    while (true) { // infinite loop until user decides to exit
        // prompt user for input
        printf("What would you like to do? (1. Turn on lights, 2. Turn off lights, 3. Turn on AC, 4. Turn off AC, 5. Exit)\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isHome) { // cannot turn on lights if nobody is present
                    printf("Sorry, nobody is home right now.\n");
                } else if (haveLightsOn) { // lights are already on
                    printf("Sorry, lights are already turned on.\n");
                } else { // turn on lights
                    printf("Turning on the lights.\n");
                    haveLightsOn = true;
                }
                break;
            case 2:
                if (haveLightsOn) { // turn off lights
                    printf("Turning off the lights.\n");
                    haveLightsOn = false;
                } else { // lights are already off
                    printf("Sorry, lights are already turned off.\n");
                }
                break;
            case 3:
                if (!isHome) { // cannot turn on AC if nobody is present
                    printf("Sorry, nobody is home right now.\n");
                } else if (haveACOn) { // AC is already on
                    printf("Sorry, AC is already turned on.\n");
                } else { // turn on AC
                    printf("Turning on the AC.\n");
                    haveACOn = true;
                }
                break;
            case 4:
                if (haveACOn) { // turn off AC
                    printf("Turning off the AC.\n");
                    haveACOn = false;
                } else { // AC is already off
                    printf("Sorry, AC is already turned off.\n");
                }
                break;
            case 5:
                printf("Exiting Smart Home Automation system...\n");
                return 0;
            default:
                printf("Invalid option entered. Please try again.\n");
        }
    }
    return 0;
}