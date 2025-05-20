//FormAI DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>

int main()
{
    /* Initialize variables */
    int livingRoomLights = 0;
    int bedroomLights = 0;
    int kitchenLights = 0;
    
    printf("Welcome to your Smart Home Light Control System!\n\n");
    
    /* Loop through menu until user decides to quit */
    int selection = -1;
    while (selection != 0)
    {
        printf("Please select an option:\n");
        printf("1. Turn on/off living room lights\n");
        printf("2. Turn on/off bedroom lights\n");
        printf("3. Turn on/off kitchen lights\n");
        printf("0. Quit\n\n");
        
        /* Get user input */
        printf("Selection: ");
        scanf("%d", &selection);
        
        /* Perform action based on user input */
        switch (selection)
        {
            case 1:
                if (livingRoomLights == 0)
                {
                    printf("Turning on living room lights...\n");
                    livingRoomLights = 1;
                }
                else
                {
                    printf("Turning off living room lights...\n");
                    livingRoomLights = 0;
                }
                break;
            case 2:
                if (bedroomLights == 0)
                {
                    printf("Turning on bedroom lights...\n");
                    bedroomLights = 1;
                }
                else
                {
                    printf("Turning off bedroom lights...\n");
                    bedroomLights = 0;
                }
                break;
            case 3:
                if (kitchenLights == 0)
                {
                    printf("Turning on kitchen lights...\n");
                    kitchenLights = 1;
                }
                else
                {
                    printf("Turning off kitchen lights...\n");
                    kitchenLights = 0;
                }
                break;
            case 0:
                /* User wants to quit, do nothing */
                break;
            default:
                printf("Invalid selection. Please try again.\n\n");
                break;
        }
    }
    
    printf("\nThank you for using your Smart Home Light Control System!");
    return 0;
}