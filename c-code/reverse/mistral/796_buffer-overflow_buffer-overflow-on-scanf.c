#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void controlVehicle(char *input) {
    int forward, left, right;

    sscanf(input, "%d %d %d", &forward, &left, &right);

    if (forward > 100 || left > 100 || right > 100) {
        printf("Error: Joystick values out of range.\n");
        return;
    }

    // Control vehicle logic
    // (You can implement your own vehicle control logic here)

    printf("Forward: %d, Left: %d, Right: %d\n", forward, left, right);
}

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("Enter joystick input (forward, left, right): ");
        fgets(input, MAX_INPUT, stdin);
        controlVehicle(input);
    }

    return 0;
}
