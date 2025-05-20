//FormAI DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int lightStatus = 0;
    int temperature = 25;
    int humidity = 50;

    printf("Welcome to your smart home!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Turn on/off the lights\n");
        printf("2. Adjust temperature\n");
        printf("3. Adjust humidity\n");
        printf("4. Exit program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (lightStatus == 0) {
                    printf("Turning on lights\n");
                    lightStatus = 1;
                } else {
                    printf("Turning off lights\n");
                    lightStatus = 0;
                }
                break;
            case 2:
                printf("Enter new temperature: ");
                scanf("%d", &temperature);
                printf("New temperature set to: %d\n", temperature);
                break;
            case 3:
                printf("Enter new humidity: ");
                scanf("%d", &humidity);
                printf("New humidity set to: %d\n", humidity);
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}