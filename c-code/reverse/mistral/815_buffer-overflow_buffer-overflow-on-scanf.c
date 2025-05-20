#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 10

void toggleDevice(int device) {
    switch (device) {
        case 1:
            printf("Light toggled.\n");
            break;
        case 2:
            printf("Fan toggled.\n");
            break;
        case 3:
            printf("AC toggled.\n");
            break;
        default:
            printf("Invalid device number.\n");
    }
}

int main() {
    int device;
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Smart Home System!\n");
    printf("1. Light\n2. Fan\n3. AC\n");
    printf("Enter the number of the device you want to toggle: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    device = atoi(input);

    toggleDevice(device);

    return 0;
}
