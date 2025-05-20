//FormAI DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>

// function to turn the lights on/off
void lightControl(int lightNum, int onOff) {
    if(onOff == 1) {
        printf("Turning on light %d\n", lightNum);
    } else if(onOff == 0) {
        printf("Turning off light %d\n", lightNum);
    }
}

int main() {
    // initialize light variables
    int light1 = 0;
    int light2 = 0;
    int light3 = 0;

    // loop to control lights
    while(1) {
        // ask user for input
        printf("Enter the number of the light you want to control (1-3): ");
        int lightNum;
        scanf("%d", &lightNum);

        // check if input is valid
        if(lightNum < 1 || lightNum > 3) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
        } else {
            // ask user if they want to turn light on or off
            printf("Do you want to turn the light on or off? Enter 1 for on and 0 for off: ");
            int onOff;
            scanf("%d", &onOff);

            // call light control function with input
            if(lightNum == 1) {
                lightControl(lightNum, onOff);
                light1 = onOff;
            } else if(lightNum == 2) {
                lightControl(lightNum, onOff);
                light2 = onOff;
            } else if(lightNum == 3) {
                lightControl(lightNum, onOff);
                light3 = onOff;
            }
        }

        // print current status of lights
        printf("Current lights status:\n");
        printf("Light 1: %d\n", light1);
        printf("Light 2: %d\n", light2);
        printf("Light 3: %d\n", light3);
    }

    return 0;
}