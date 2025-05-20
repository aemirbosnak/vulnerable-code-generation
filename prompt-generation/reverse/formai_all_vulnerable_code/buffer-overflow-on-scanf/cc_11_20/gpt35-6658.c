//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>

int main() {

    int batteryLevel, speed, altitude;
    char command;
    printf("Enter the battery level (0-100): ");
    scanf("%d", &batteryLevel);
    if (batteryLevel < 20) {
        printf("Low battery level!");
        return 0;
    }
    printf("Enter the desired speed (0-50 mph): ");
    scanf("%d", &speed);
    if (speed > 50) {
        printf("Maximum speed exceeded!");
        return 0;
    }
    printf("Enter the desired altitude (0-500 ft): ");
    scanf("%d", &altitude);
    if (altitude > 500) {
        printf("Maximum altitude exceeded!");
        return 0;
    }
    printf("Enter a command (F - Forward, B - Backward, L - Left, R - Right, U - Up, D - Down, Q - Quit): ");
    scanf(" %c", &command);

    while (command != 'Q') {
        switch (command) {
            case 'F':
                printf("Moving forward at %d mph\n", speed);
                break;
            case 'B':
                printf("Moving backward at %d mph\n", speed);
                break;
            case 'L':
                printf("Turning left\n");
                break;
            case 'R':
                printf("Turning right\n");
                break;
            case 'U':
                printf("Ascending to %d ft\n", altitude);
                break;
            case 'D':
                printf("Descending to %d ft\n", altitude);
                break;
            default:
                printf("Invalid command\n");
                break;
        }
        printf("Enter a command (F - Forward, B - Backward, L - Left, R - Right, U - Up, D - Down, Q - Quit): ");
        scanf(" %c", &command);
    }

    return 0;
}