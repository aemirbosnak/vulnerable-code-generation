//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>

int main(){
    int temperature = 25;
    int light = 0;
    int coffee = 0;

    printf("Welcome to your smart home!\n");

    while (1) {
        printf("\n");
        printf("Current Temperature: %d degrees\n", temperature);
        printf("Lights are currently %s\n", (light == 1 ? "ON" : "OFF"));
        printf("Coffee is currently %s\n", (coffee == 1 ? "BREWING" : "NOT BREWING"));

        printf("\nWhat would you like to do?\n");
        printf("1. Increase temperature\n");
        printf("2. Decrease temperature\n");
        printf("3. Turn lights on/off\n");
        printf("4. Brew coffee\n");
        printf("5. Stop/pause brewing coffee\n");

        int choice;
        printf("Enter the number of your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature += 1;
                break;
            case 2:
                temperature -= 1;
                break;
            case 3:
                light = (light == 0 ? 1 : 0);
                break;
            case 4:
                if (coffee == 0) {
                    printf("Starting coffee brewing!\n");
                    coffee = 1;
                } else {
                    printf("Coffee already brewing!\n");
                }
                break;
            case 5:
                if (coffee == 1) {
                    printf("Pausing coffee brewing!\n");
                    coffee = 0;
                } else {
                    printf("No coffee brewing to pause!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}