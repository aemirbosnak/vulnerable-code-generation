#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void toggleDevice(char* device, int* state) {
    if (*state) {
        printf("%s is off.\n", device);
        *state = 0;
    } else {
        printf("%s is on.\n", device);
        *state = 1;
    }
}

int main() {
    int light = 0, fan = 0, ac = 0;

    char input[10];
    while (1) {
        printf("Enter command (light, fan, ac, exit): ");
        scanf("%s", input);

        if (strcmp(input, "light") == 0) {
            toggleDevice("Light", &light);
        } else if (strcmp(input, "fan") == 0) {
            toggleDevice("Fan", &fan);
        } else if (strcmp(input, "ac") == 0) {
            toggleDevice("AC", &ac);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
