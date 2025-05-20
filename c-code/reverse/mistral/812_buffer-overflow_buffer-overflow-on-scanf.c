#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void lightControl(char *command) {
    if (strcmp(command, "on") == 0) {
        printf("Light is turned on.\n");
    } else if (strcmp(command, "off") == 0) {
        printf("Light is turned off.\n");
    } else {
        printf("Invalid command.\n");
    }
}

void temperatureControl(char *command) {
    if (strcmp(command, "up") == 0) {
        printf("Temperature is increased.\n");
    } else if (strcmp(command, "down") == 0) {
        printf("Temperature is decreased.\n");
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    char command[10];
    int choice;

    printf("Welcome to Smart Home Automation System\n");
    printf("1. Light Control\n");
    printf("2. Temperature Control\n");
    printf("Choose an option: ");
    scanf("%s", command);

    switch (atoi(command)) {
        case 1:
            printf("Enter command (on/off): ");
            scanf("%s", command);
            lightControl(command);
            break;
        case 2:
            printf("Enter command (up/down): ");
            scanf("%s", command);
            temperatureControl(command);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}
