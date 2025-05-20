#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void controlVehicle(char *input) {
    int forward, left, right;

    sscanf(input, "%d%*c%d%*c%d", &forward, &left, &right);

    if (forward > 100 || left > 100 || right > 100) {
        printf("Input values must be less than or equal to 100.\n");
        return;
    }

    // Vulnerable code with buffer overflow
    char buffer[5];
    strcpy(buffer, input + strlen(input) - 4);

    // Cyclomatic complexity calculation:
    // 1. if condition
    // 2. function call (sscanf)
    // 3. variable declaration (forward, left, right)
    // 4. if condition (checking input values)
    // 5. variable declaration (buffer)
    // 6. function call (strcpy)

    // Simulate vehicle movement
    printf("Forward: %d, Left: %d, Right: %d, Buffer: %s\n", forward, left, right, buffer);
}

int main() {
    char input[MAX_INPUT];

    printf("Enter joystick input (3 numbers separated by spaces): ");
    fgets(input, MAX_INPUT, stdin);

    controlVehicle(input);

    return 0;
}
