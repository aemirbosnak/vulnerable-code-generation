//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool lights_on = false;
    int power_level = 50;
    int security_level = 10;

    printf("Welcome to the Smart Home Light Control System\n");

    if (power_level < 10) {
        printf("Emergency power mode activated. All lights are off.\n");
    }
    else {
        printf("Power level at %d%%.\n", power_level);
        if (security_level > 0) {
            printf("Security system active. Lights will turn on upon motion detection.\n");
        }
        else {
            printf("Security system inactive. Lights can be controlled manually.\n");
        }
        printf("Enter 'on' to turn on the lights, 'off' to turn them off, or 'exit' to quit.\n");
        char command[10];
        while (true) {
            scanf("%s", command);
            if (strcmp(command, "on") == 0) {
                lights_on = true;
                printf("Lights turned on.\n");
            }
            else if (strcmp(command, "off") == 0) {
                lights_on = false;
                printf("Lights turned off.\n");
            }
            else if (strcmp(command, "exit") == 0) {
                printf("Exiting the program.\n");
                break;
            }
            else {
                printf("Invalid command. Please enter 'on', 'off', or 'exit'.\n");
            }

            if (security_level > 0 && lights_on == false) {
                printf("Security system activated. Lights will turn on upon motion detection.\n");
            }
            else {
                printf("Security system deactivated. Lights can be controlled manually.\n");
            }
        }
    }

    return 0;
}