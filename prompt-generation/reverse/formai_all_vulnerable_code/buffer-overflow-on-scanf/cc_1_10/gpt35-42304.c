//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
// Program to control a smart home light
#include <stdio.h>

int main() {
    int light_status = 0; // 0 = OFF, 1 = ON
    int brightness = 0;

    printf("Welcome to the Smart Home Light Control System!\n");

    while(1) {
        // Menu Options
        printf("Please choose an option:\n");
        printf("1. Turn Light ON\n");
        printf("2. Turn Light OFF\n");
        printf("3. Change Brightness\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        // Handling User Input
        switch(choice) {
            case 1:
                light_status = 1;
                printf("Light Turned ON\n");
                break;

            case 2:
                light_status = 0;
                printf("Light Turned OFF\n");
                break;

            case 3:
                printf("Enter Brightness (0 to 100): ");
                scanf("%d", &brightness);

                if(brightness < 0 || brightness > 100) {
                    printf("Invalid Brightness level!\n");
                }
                else {
                    printf("Brightness level set to %d\n", brightness);
                }
                break;

            case 4:
                printf("Thank you for using Smart Home Light Control System!\n");
                return 0; // Exiting Program

            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }

        // Updating Light Status and Brightness
        printf("Current Light Status: ");
        if(light_status == 1) {
            printf("ON\n");
        }
        else {
            printf("OFF\n");
        }
        printf("Current Brightness: %d\n\n", brightness);
    }

    return 0;
}