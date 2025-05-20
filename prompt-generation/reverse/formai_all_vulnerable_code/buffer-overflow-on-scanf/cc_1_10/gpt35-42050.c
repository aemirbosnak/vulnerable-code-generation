//FormAI DATASET v1.0 Category: Smart home automation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool lightOn = false;
    bool fanOn = false;
    bool heaterOn = false;

    printf("Welcome to Smart Home Automation\n");

    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Turn light ON/OFF\n");
        printf("2. Turn fan ON/OFF\n");
        printf("3. Turn heater ON/OFF\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (lightOn) {
                    printf("Turning the light OFF\n");
                } else {
                    printf("Turning the light ON\n");
                }
                lightOn = !lightOn;
                break;

            case 2:
                if (fanOn) {
                    printf("Turning the fan OFF\n");
                } else {
                    printf("Turning the fan ON\n");
                }
                fanOn = !fanOn;
                break;

            case 3:
                if (heaterOn) {
                    printf("Turning the heater OFF\n");
                } else {
                    printf("Turning the heater ON\n");
                }
                heaterOn = !heaterOn;
                break;

            case 4:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }
}