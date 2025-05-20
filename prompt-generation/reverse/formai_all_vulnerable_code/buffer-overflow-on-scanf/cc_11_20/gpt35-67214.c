//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int main(void) {
    int lights = 0;
    int security = 0;
    int temperature = 68;
    char command[20];

    printf(COLOR_CYAN "\n~~~ Welcome to the Cyberpunk Smart Home ~~~\n" COLOR_RESET);

    do {
        printf(COLOR_GREEN "\nWhat would you like to do today? (type 'help' for a list of commands)\n" COLOR_RESET);
        scanf("%s", command);

        if (strcmp(command, "help") == 0) {
            printf(COLOR_CYAN "\n--- Commands ---\n");
            printf("smartlights - control the lights in the room\n");
            printf("lockdown - activate the security system\n");
            printf("temperature - adjust the temperature\n");
            printf("exit - leave the program\n" COLOR_RESET);
        }
        else if (strcmp(command, "smartlights") == 0) {
            printf(COLOR_CYAN "\n--- Smart Lights ---\n" COLOR_RESET);
            printf("Lights are currently %s\n", (lights == 0) ? "off" : "on");
            printf("Would you like to turn the lights on or off?\n");
            scanf("%s", command);
            if (strcmp(command, "on") == 0) {
                lights = 1;
                printf("Turning lights on...\n");
            }
            else if (strcmp(command, "off") == 0) {
                lights = 0;
                printf("Turning lights off...\n");
            }
            else {
                printf(COLOR_RED "Invalid command.\n" COLOR_RESET);
            }
        }
        else if (strcmp(command, "lockdown") == 0) {
            printf(COLOR_CYAN "\n--- Security System ---\n" COLOR_RESET);
            printf("Security is currently %s\n", (security == 0) ? "off" : "on");
            printf("Are you sure you want to activate lockdown? (yes or no)\n");
            scanf("%s", command);
            if (strcmp(command, "yes") == 0) {
                security = 1;
                printf("Activating security system...\n");
            }
            else if (strcmp(command, "no") == 0) {
                printf("Leaving security system off...\n");
            }
            else {
                printf(COLOR_RED "Invalid command.\n" COLOR_RESET);
            }
        }
        else if (strcmp(command, "temperature") == 0) {
            printf(COLOR_CYAN "\n--- Temperature ---\n" COLOR_RESET);
            printf("Current temperature is %d degrees.\n", temperature);
            printf("Would you like to increase or decrease the temperature?\n");
            scanf("%s", command);
            if (strcmp(command, "increase") == 0) {
                temperature += 2;
                printf("Increasing temperature to %d degrees...\n", temperature);
            }
            else if (strcmp(command, "decrease") == 0) {
                temperature -= 2;
                printf("Decreasing temperature to %d degrees...\n", temperature);
            }
            else {
                printf(COLOR_RED "Invalid command.\n" COLOR_RESET);
            }
        }
        else if (strcmp(command, "exit") == 0) {
            printf(COLOR_CYAN "\nLeaving smart home...\n" COLOR_RESET);
        }
        else {
            printf(COLOR_RED "Invalid command.\n" COLOR_RESET);
        }

    } while (strcmp(command, "exit") != 0);

    return 0;
}