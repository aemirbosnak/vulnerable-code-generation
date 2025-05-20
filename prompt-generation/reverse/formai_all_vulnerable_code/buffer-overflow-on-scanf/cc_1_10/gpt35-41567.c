//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void turnOnLights();
void turnOffLights();
void setBrightness(int brightness);

int main() {
    int choice, brightness = 0;

    // welcome message
    printf("Welcome to Smart Home Light Control\n");

    // loop until user chooses to exit
    while(1) {
        // display options to user
        printf("Choose an option:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Set brightness level\n");
        printf("4. Exit\n");

        // user input
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                turnOnLights();
                break;
            case 2:
                turnOffLights();
                break;
            case 3:
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setBrightness(brightness);
                break;
            case 4:
                printf("Thank you for using Smart Home Light Control\n");
                exit(0); // exit program
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

// function to turn on lights
void turnOnLights() {
    printf("Lights turned on\n");
}

// function to turn off lights
void turnOffLights() {
    printf("Lights turned off\n");
}

// function to set brightness level
void setBrightness(int brightness) {
    printf("Brightness level set to %d\n", brightness);
}