#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

int lights[MAX_LIGHTS] = {0};

void toggleLight(int lightNumber) {
    if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
        lights[lightNumber - 1] = !lights[lightNumber - 1];
        printf("Light %d is now %s\n", lightNumber, lights[lightNumber - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid light number. Please enter a number between 1 and %d.\n", MAX_LIGHTS);
    }
}

void printHelp() {
    printf("Available commands:\n");
    printf("toggle <light_number> - Turn a specific light on or off.\n");
    printf("help - Display this list of commands.\n");
    printf("exit - Exit the program.\n");
}

int main() {
    char command[256];
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "toggle ", 7) == 0) {
            int lightNumber;
            sscanf(command + 7, "%d", &lightNumber);
            toggleLight(lightNumber);
        } else if (strcmp(command, "help") == 0) {
            printHelp();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}
