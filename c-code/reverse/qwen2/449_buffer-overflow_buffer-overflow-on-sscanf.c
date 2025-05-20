#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10

int main() {
    int lights[MAX_LIGHTS] = {0};
    char command[256];
    int lightNumber, state;

    while (1) {
        printf("Enter command: ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        
        if (sscanf(command, "light %d %d", &lightNumber, &state) != 2) {
            printf("Invalid command. Please use 'light <number> <state>' where <number> is 1-10 and <state> is 0 or 1.\n");
            continue;
        }

        if (lightNumber < 1 || lightNumber > MAX_LIGHTS) {
            printf("Light number must be between 1 and %d.\n", MAX_LIGHTS);
            continue;
        }

        if (state != 0 && state != 1) {
            printf("State must be 0 (off) or 1 (on).\n");
            continue;
        }

        lights[lightNumber - 1] = state;
        printf("Light %d is now %s\n", lightNumber, state ? "on" : "off");
    }

    return 0;
}
