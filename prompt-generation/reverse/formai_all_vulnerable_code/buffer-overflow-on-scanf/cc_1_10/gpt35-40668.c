//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main() {
    int lightStatus = 0; // initially off
    int brightnessLevel = 0; // initially lowest brightness level
    char input;

    while(1) {
        printf("Enter command (o for on, f for off, + to increase brightness, - to decrease brightness, q to quit): ");
        scanf(" %c", &input);

        if(input == 'o') {
            lightStatus = 1; // turn on light
            brightnessLevel = 4; // set brightness level to default
            printf("Light turned on with default brightness level.\n");
        }
        else if(input == 'f') {
            lightStatus = 0; // turn off light
            brightnessLevel = 0; // reset brightness level
            printf("Light turned off.\n");
        }
        else if(input == '+') {
            if(brightnessLevel < 5) {
                brightnessLevel++;
            }
            else {
                printf("Cannot increase brightness beyond maximum level.\n");
            }
        }
        else if(input == '-') {
            if(brightnessLevel > 1) { // cannot decrease below minimum
                brightnessLevel--;
            }
            else {
                printf("Cannot decrease brightness below minimum level.\n");
            }
        }
        else if(input == 'q') {
            printf("Exiting program.\n");
            break; // exit loop
        }
        else {
            printf("Invalid command entered.\n");
        }

        if(lightStatus) {
            printf("Light is on with brightness level %d.\n", brightnessLevel);
        }
    }

    return 0;
}