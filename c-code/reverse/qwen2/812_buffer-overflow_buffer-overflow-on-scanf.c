#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void turnOnLight() {
    printf("Light turned on.\n");
}

void turnOffLight() {
    printf("Light turned off.\n");
}

void adjustTemperature(int temp) {
    printf("Temperature adjusted to %d degrees.\n", temp);
}

int main() {
    int choice;
    char buffer[2];

    while (1) {
        printf("Smart Home Automation System\n");
        printf("1. Turn On Light\n");
        printf("2. Turn Off Light\n");
        printf("3. Adjust Temperature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", buffer);

        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                turnOnLight();
                break;
            case 2:
                turnOffLight();
                break;
            case 3:
                int temp;
                printf("Enter temperature: ");
                scanf("%d", &temp);
                adjustTemperature(temp);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
