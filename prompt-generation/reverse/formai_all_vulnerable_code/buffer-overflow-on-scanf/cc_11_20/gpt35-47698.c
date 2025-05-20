//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaration of variables
    int light1 = 0, light2 = 0, light3 = 0;
    int choice, brightness;

    // Display of menu
    printf("----------- Smart Home Light Control System -----------\n");
    printf("1. Turn on/off light 1\n");
    printf("2. Turn on/off light 2\n");
    printf("3. Turn on/off light 3\n");
    printf("4. Adjust brightness of light 1\n");
    printf("5. Adjust brightness of light 2\n");
    printf("6. Adjust brightness of light 3\n");
    printf("7. Exit\n");

    while (1)
    {
        // Reading user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (light1 == 0)
                {
                    printf("Turning on light 1...\n");
                    light1 = 1;
                }
                else
                {
                    printf("Turning off light 1...\n");
                    light1 = 0;
                }
                break;

            case 2:
                if (light2 == 0)
                {
                    printf("Turning on light 2...\n");
                    light2 = 1;
                }
                else
                {
                    printf("Turning off light 2...\n");
                    light2 = 0;
                }
                break;

            case 3:
                if (light3 == 0)
                {
                    printf("Turning on light 3...\n");
                    light3 = 1;
                }
                else
                {
                    printf("Turning off light 3...\n");
                    light3 = 0;
                }
                break;

            case 4:
                printf("\nEnter brightness level for light 1 (0-100): ");
                scanf("%d", &brightness);
                if (brightness < 0)
                {
                    brightness = 0;
                }
                else if (brightness > 100)
                {
                    brightness = 100;
                }
                printf("Adjusting brightness of light 1 to %d...\n", brightness);
                break;

            case 5:
                printf("\nEnter brightness level for light 2 (0-100): ");
                scanf("%d", &brightness);
                if (brightness < 0)
                {
                    brightness = 0;
                }
                else if (brightness > 100)
                {
                    brightness = 100;
                }
                printf("Adjusting brightness of light 2 to %d...\n", brightness);
                break;

            case 6:
                printf("\nEnter brightness level for light 3 (0-100): ");
                scanf("%d", &brightness);
                if (brightness < 0)
                {
                    brightness = 0;
                }
                else if (brightness > 100)
                {
                    brightness = 100;
                }
                printf("Adjusting brightness of light 3 to %d...\n", brightness);
                break;

            case 7:
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}