//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Light structure
typedef struct {
    char name[64];
    bool isOn;
} Light;

// Smart home light control program
int main() {
    Light lights[MAX_LIGHTS];

    // Initialize lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].isOn = false;
        strcpy(lights[i].name, "Light ");
        int num = i + 1;
        char numStr[3];
        sprintf(numStr, "%d", num);
        strcat(lights[i].name, numStr);
    }

    // Menu loop
    while (true) {
        printf("\nSmart Home Light Control\n");
        printf("1. Turn on/off a light\n");
        printf("2. Rename a light\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Turn on/off a light
            printf("Enter light number: ");
            int lightNum;
            scanf("%d", &lightNum);

            if (lightNum < 1 || lightNum > MAX_LIGHTS) {
                printf("Invalid light number\n");
            } else {
                printf("Enter 1 to turn on or 0 to turn off: ");
                int action;
                scanf("%d", &action);

                lights[lightNum - 1].isOn = (action == 1);
                printf("Light %s %s\n", lights[lightNum - 1].name, (lights[lightNum - 1].isOn)? "turned on" : "turned off");
            }
            break;

        case 2:
            // Rename a light
            printf("Enter light number: ");
            int lightNum2;
            scanf("%d", &lightNum2);

            if (lightNum2 < 1 || lightNum2 > MAX_LIGHTS) {
                printf("Invalid light number\n");
            } else {
                printf("Enter new name: ");
                scanf("%s", lights[lightNum2 - 1].name);
            }
            break;

        case 3:
            // Exit
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}