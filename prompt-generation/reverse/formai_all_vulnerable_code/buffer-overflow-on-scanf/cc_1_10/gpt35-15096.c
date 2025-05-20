//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    // assume we have 5 lights connected to our smart home system
    int numLights = 5;
    // keep track of the status of each light (0 = off, 1 = on)
    int lightStatus[5] = {0, 0, 0, 0, 0};
    int i, lightNum, command;

    printf("Welcome to the Smart Home Light Control System.\n");
    // loop indefinitely
    while (1) {
        printf("\nEnter the number of the light you wish to control (1-%d), or 0 to exit: ", numLights);
        scanf("%d", &lightNum);

        if (lightNum <= 0) {
            printf("\nExiting Smart Home Light Control System...");
            break;
        }
        else if (lightNum > numLights) {
            printf("\nInvalid light number. Please enter a number between 1 and %d.", numLights);
            continue;
        }
        else {
            printf("\nAvailable commands:\n");
            printf("0 - Turn off light %d\n", lightNum);
            printf("1 - Turn on light %d\n", lightNum);
            printf("2 - Toggle light %d\n", lightNum);
            printf("\nEnter your command (0-2): ");
            scanf("%d", &command);

            switch (command) {
                case 0:
                    lightStatus[lightNum - 1] = 0;
                    printf("\nLight %d turned off.", lightNum);
                    break;
                case 1:
                    lightStatus[lightNum - 1] = 1;
                    printf("\nLight %d turned on.", lightNum);
                    break;
                case 2:
                    lightStatus[lightNum - 1] = !lightStatus[lightNum - 1];
                    if (lightStatus[lightNum - 1]) {
                        printf("\nLight %d turned on.", lightNum);
                    }
                    else {
                        printf("\nLight %d turned off.", lightNum);
                    }
                    break;
                default:
                    printf("\nInvalid command. Please enter a number between 0 and 2.");
                    break;
            }
        }
    }
    return 0;
}