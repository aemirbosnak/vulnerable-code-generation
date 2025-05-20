//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>

int main() {
    // Welcome Message
    printf("Welcome to the Smart Home Automation Program!\n\n");

    // Room Selection
    printf("Which room would you like to control?\n");
    printf("A) Living Room\n");
    printf("B) Bedroom\n");
    printf("C) Kitchen\n");
    char roomSelection;
    scanf("%c", &roomSelection);

    // Living Room Controls
    if (roomSelection == 'A') {
        printf("\nYou have selected the Living Room.\n");
        printf("What would you like to do?\n");
        printf("A) Turn on/off the Lights\n");
        printf("B) Adjust the Temperature\n");
        char livingRoomSelection;
        scanf(" %c", &livingRoomSelection);

        // Light Controls
        if (livingRoomSelection == 'A') {
            printf("\nYou have chosen to control the Living Room lights.\n");
            printf("Do you want to turn them on or off?\n");
            printf("A) On\n");
            printf("B) Off\n");
            char lightSelection;
            scanf(" %c", &lightSelection);

            if (lightSelection == 'A') {
                printf("The Living Room lights are turning on.\n");
            } else if (lightSelection == 'B') {
                printf("The Living Room lights are turning off.\n");
            } else {
                printf("Invalid option. Please try again.\n");
            }

        // Temperature Controls
        } else if (livingRoomSelection == 'B') {
            printf("\nYou have chosen to control the Living Room temperature.\n");
            printf("What temperature would you like to set it to?\n");
            int temperature;
            scanf("%d", &temperature);
            printf("The Living Room temperature is now set to %d degrees.\n", temperature);

        } else {
            printf("Invalid option. Please try again.\n");
        }

    // Bedroom Controls
    } else if (roomSelection == 'B') {
        printf("\nYou have selected the Bedroom.\n");
        printf("What would you like to do?\n");
        printf("A) Turn on/off the Lights\n");
        printf("B) Adjust the Temperature\n");
        char bedroomSelection;
        scanf(" %c", &bedroomSelection);

        // Light Controls
        if (bedroomSelection == 'A') {
            printf("\nYou have chosen to control the Bedroom lights.\n");
            printf("Do you want to turn them on or off?\n");
            printf("A) On\n");
            printf("B) Off\n");
            char lightSelection;
            scanf(" %c", &lightSelection);

            if (lightSelection == 'A') {
                printf("The Bedroom lights are turning on.\n");
            } else if (lightSelection == 'B') {
                printf("The Bedroom lights are turning off.\n");
            } else {
                printf("Invalid option. Please try again.\n");
            }

        // Temperature Controls
        } else if (bedroomSelection == 'B') {
            printf("\nYou have chosen to control the Bedroom temperature.\n");
            printf("What temperature would you like to set it to?\n");
            int temperature;
            scanf("%d", &temperature);
            printf("The Bedroom temperature is now set to %d degrees.\n", temperature);

        } else {
            printf("Invalid option. Please try again.\n");
        }

    // Kitchen Controls
    } else if (roomSelection == 'C') {
        printf("\nYou have selected the Kitchen.\n");
        printf("What would you like to do?\n");
        printf("A) Turn on/off the Lights\n");
        printf("B) Adjust the Temperature\n");
        char kitchenSelection;
        scanf(" %c", &kitchenSelection);

        // Light Controls
        if (kitchenSelection == 'A') {
            printf("\nYou have chosen to control the Kitchen lights.\n");
            printf("Do you want to turn them on or off?\n");
            printf("A) On\n");
            printf("B) Off\n");
            char lightSelection;
            scanf(" %c", &lightSelection);

            if (lightSelection == 'A') {
                printf("The Kitchen lights are turning on.\n");
            } else if (lightSelection == 'B') {
                printf("The Kitchen lights are turning off.\n");
            } else {
                printf("Invalid option. Please try again.\n");
            }

        // Temperature Controls
        } else if (kitchenSelection == 'B') {
            printf("\nYou have chosen to control the Kitchen temperature.\n");
            printf("What temperature would you like to set it to?\n");
            int temperature;
            scanf("%d", &temperature);
            printf("The Kitchen temperature is now set to %d degrees.\n", temperature);

        } else {
            printf("Invalid option. Please try again.\n");
        }

    } else {
        printf("Invalid option. Please try again.\n");
    }

    return 0;
}