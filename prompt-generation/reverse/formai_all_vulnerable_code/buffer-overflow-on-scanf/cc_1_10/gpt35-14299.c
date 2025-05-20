//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature = 25;
    int humidity = 50;
    int light = 0;
    int security = 0;

    printf("Welcome to Smart Home Automation\n");

    while (1) {
        printf("\n\n\n");
        printf("Choose one of the following options:\n");
        printf("1. Change temperature\n");
        printf("2. Change humidity\n");
        printf("3. Turn on/off light\n");
        printf("4. Arm/disarm security system\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter new temperature: ");
            scanf("%d", &temperature);
            printf("Temperature changed to %d\n", temperature);
        }
        else if (choice == 2) {
            printf("Enter new humidity: ");
            scanf("%d", &humidity);
            printf("Humidity changed to %d\n", humidity);
        }
        else if (choice == 3) {
            if (light == 0) {
                printf("Turning on light\n");
                light = 1;
            }
            else {
                printf("Turning off light\n");
                light = 0;
            }
        }
        else if (choice == 4) {
            if (security == 0) {
                printf("Arming security system\n");
                security = 1;
            }
            else {
                printf("Disarming security system\n");
                security = 0;
            }
        }
        else if (choice == 5) {
            printf("Exiting program\n");
            break;
        }
        else {
            printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}