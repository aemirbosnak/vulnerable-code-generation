#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_LIGHTS 10

int main() {
    int lights[MAX_LIGHTS] = {0};
    char command[10];
    int lightNumber;

    while (1) {
        printf("Enter command: ");
        scanf("%s %d", command, &lightNumber);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (lightNumber < 1 || lightNumber > MAX_LIGHTS) {
            printf("Invalid light number. Please enter a number between 1 and %d.\n", MAX_LIGHTS);
            continue;
        }

        if (strcmp(command, "on") == 0) {
            lights[lightNumber - 1] = 1;
        } else if (strcmp(command, "off") == 0) {
            lights[lightNumber - 1] = 0;
        } else {
            printf("Unknown command. Use 'on' or 'off'.\n");
            continue;
        }

        printf("Status of all lights:\n");
        for (int i = 0; i < MAX_LIGHTS; i++) {
            printf("Light %d: %s\n", i + 1, lights[i] ? "On" : "Off");
        }
    }

    return 0;
}
