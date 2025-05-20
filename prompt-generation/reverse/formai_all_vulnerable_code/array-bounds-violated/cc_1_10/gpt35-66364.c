//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

struct Light {
    char name[20];
    int brightness;
    int color[3];
    int state; // 0-off, 1-on
};

typedef struct Light Light;

int main()
{
    Light lights[MAX_LIGHTS];
    int num_lights = 3;
    int selection, action;

    // Initialize lights
    strcpy(lights[0].name, "Living Room Light");
    lights[0].brightness = 75;
    lights[0].color[0] = 255;
    lights[0].color[1] = 0;
    lights[0].color[2] = 0;
    lights[0].state = 1;

    strcpy(lights[1].name, "Bedroom Light");
    lights[1].brightness = 50;
    lights[1].color[0] = 0;
    lights[1].color[1] = 255;
    lights[1].color[2] = 0;
    lights[1].state = 0;

    strcpy(lights[2].name, "Kitchen Light");
    lights[2].brightness = 100;
    lights[2].color[0] = 0;
    lights[2].color[1] = 0;
    lights[2].color[2] = 255;
    lights[2].state = 1;

    printf("Welcome to the Cyberpunk Smart Home Light Control System.\n");
    printf("You have %d lights connected to the system.\n", num_lights);

    // Main program loop
    while (1) {
        printf("\nSelect a light to control:\n");
        for (int i=0; i<num_lights; i++) {
            printf("%d) %s\n", i+1, lights[i].name);
        }
        printf("%d) Quit\n", num_lights+1);
        printf("\nEnter your selection: ");
        scanf("%d", &selection);

        if (selection == num_lights+1) {
            printf("Goodbye!\n");
            break;
        }

        printf("\nSelected light: %s\n", lights[selection-1].name);

        printf("What action would you like to perform?\n");
        printf("1) Turn on/off\n");
        printf("2) Adjust brightness\n");
        printf("3) Change color\n");
        printf("4) Go back\n");
        printf("\nEnter your selection: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                if (lights[selection-1].state) {
                    // Turn off light
                    lights[selection-1].state = 0;
                    printf("%s turned off.\n", lights[selection-1].name);
                } else {
                   // Turn on light
                   lights[selection-1].state = 1;
                   printf("%s turned on.\n", lights[selection-1].name);
                }
                break;

            case 2:
                printf("Enter brightness level (0-100): ");
                scanf("%d", &lights[selection-1].brightness);
                printf("%s brightness set to %d.\n", lights[selection-1].name, lights[selection-1].brightness);
                break;

            case 3:
                printf("Enter red component value (0-255): ");
                scanf("%d", &lights[selection-1].color[0]);
                printf("Enter green component value (0-255): ");
                scanf("%d", &lights[selection-1].color[1]);
                printf("Enter blue component value (0-255): ");
                scanf("%d", &lights[selection-1].color[2]);
                printf("%s color set to RGB(%d,%d,%d).\n", lights[selection-1].name, lights[selection-1].color[0], lights[selection-1].color[1], lights[selection-1].color[2]);
                break;

            case 4:
                break;

            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}