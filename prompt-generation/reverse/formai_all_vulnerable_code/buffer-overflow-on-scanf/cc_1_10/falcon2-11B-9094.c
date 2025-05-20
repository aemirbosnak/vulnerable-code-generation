//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    int result;

    // Prompt user for command
    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);

    // Remove trailing newline
    command[strcspn(command, "\n")] = '\0';

    // Execute command
    switch (strcasecmp(command, "ON")) {
        case 0:
            printf("Turning lights on...\n");
            break;
        case 1:
            printf("Turning lights off...\n");
            break;
        case 2:
            printf("Setting temperature to 25 degrees Celsius...\n");
            break;
        case 3:
            printf("Opening window...\n");
            break;
        default:
            printf("Invalid command\n");
            break;
    }

    // Get user input
    printf("Enter a number between 1 and 5: ");
    scanf("%d", &result);

    // Display result
    switch (result) {
        case 1:
            printf("Lights are on.\n");
            break;
        case 2:
            printf("Lights are off.\n");
            break;
        case 3:
            printf("Temperature is set to 25 degrees Celsius.\n");
            break;
        case 4:
            printf("Window is open.\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return 0;
}