#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100
#define NUM_LIGHTS 10

void controlLight(int lightNum, int state);

int main() {
    char input[MAX_INPUT];
    int lightNum, state;

    while (1) {
        printf("Enter command (LxOn/LxOff/Q): ");
        fgets(input, MAX_INPUT, stdin);

        sscanf(input, "L%d%c%c", &lightNum, &state);

        if (lightNum < 1 || lightNum > NUM_LIGHTS) {
            printf("Invalid light number.\n");
            continue;
        }

        if (state != 'O' && state != 'o' && state != 'F' && state != 'f') {
            printf("Invalid state (On/Off).\n");
            continue;
        }

        if (input[strlen(input) - 1] != '\n') {
            printf("Invalid input format.\n");
            continue;
        }

        controlLight(lightNum, state - '0');
    }

    return 0;
}

void controlLight(int lightNum, int state) {
    static int lights[NUM_LIGHTS] = {0};

    if (state) {
        if (lights[lightNum - 1]) {
            printf("Light %d is already on.\n", lightNum);
        } else {
            lights[lightNum - 1] = 1;
            printf("Light %d is turned on.\n", lightNum);
        }
    } else {
        if (!lights[lightNum - 1]) {
            printf("Light %d is already off.\n", lightNum);
        } else {
            lights[lightNum - 1] = 0;
            printf("Light %d is turned off.\n", lightNum);
        }
    }
}
