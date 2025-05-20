//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OFF 0
#define ON 1

int main()
{
    int livingRoomLights = OFF;
    int bedroomLights = OFF;
    int kitchenLights = OFF;
    bool isPartyMode = false;

    printf("-------------------\n");
    printf("| SMART HOME LIGHT |\n");
    printf("-------------------\n\n");

    while(true)
    {
        printf("What would you like to do? Type the number of the option.\n");
        printf("1. Turn on living room lights.\n");
        printf("2. Turn off living room lights.\n");
        printf("3. Turn on bedroom lights.\n");
        printf("4. Turn off bedroom lights.\n");
        printf("5. Turn on kitchen lights.\n");
        printf("6. Turn off kitchen lights.\n");
        printf("7. Turn on party mode.\n");
        printf("8. Turn off party mode.\n");
        printf("9. Quit.\n");

        int option;
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                livingRoomLights = ON;
                printf("Living room lights turned on!\n");
                break;

            case 2:
                livingRoomLights = OFF;
                printf("Living room lights turned off!\n");
                break;

            case 3:
                bedroomLights = ON;
                printf("Bedroom lights turned on!\n");
                break;

            case 4:
                bedroomLights = OFF;
                printf("Bedroom lights turned off!\n");
                break;

            case 5:
                kitchenLights = ON;
                printf("Kitchen lights turned on!\n");
                break;

            case 6:
                kitchenLights = OFF;
                printf("Kitchen lights turned off!\n");
                break;

            case 7:
                isPartyMode = true;
                printf("Party mode activated! Lights will now blink in different colors!\n");
                break;

            case 8:
                isPartyMode = false;
                printf("Party mode deactivated! Lights will now return to their previous state.\n");
                break;

            case 9:
                printf("Quitting...\n");
                exit(0);

            default:
                printf("Invalid option, please try again.\n");
        }

        if(isPartyMode)
        {
            //Flash the lights in random colors
            livingRoomLights = rand() % 2 == 0 ? ON : OFF;
            bedroomLights = rand() % 2 == 0 ? ON : OFF;
            kitchenLights = rand() % 2 == 0 ? ON : OFF;
        }

        printf("CURRENT STATUS:\n");
        printf("Living room lights: %s\n", livingRoomLights == ON ? "ON" : "OFF");
        printf("Bedroom lights: %s\n", bedroomLights == ON ? "ON" : "OFF");
        printf("Kitchen lights: %s\n", kitchenLights == ON ? "ON" : "OFF");
        printf("\n");
    }

    return 0;
}