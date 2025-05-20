//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

int main() {
    int numLights;
    int lightStatus[MAX_LIGHTS];
    int lightIndex;
    int choice;

    printf("Welcome to the Smart Home Light Control System\n");
    printf("How many lights do you have? (Max %d)\n", MAX_LIGHTS);
    scanf("%d", &numLights);

    for (int i=0; i<numLights; i++) {
        lightStatus[i] = LIGHT_OFF;
    }

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn a light on\n");
        printf("2. Turn a light off\n");
        printf("3. Toggle a light\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Which light would you like to turn on? (0-%d)\n", numLights-1);
                scanf("%d", &lightIndex);
                lightStatus[lightIndex] = LIGHT_ON;
                printf("Light %d turned on\n", lightIndex+1);
                break;

            case 2:
                printf("Which light would you like to turn off? (0-%d)\n", numLights-1);
                scanf("%d", &lightIndex);
                lightStatus[lightIndex] = LIGHT_OFF;
                printf("Light %d turned off\n", lightIndex+1);
                break;

            case 3:
                printf("Which light would you like to toggle? (0-%d)\n", numLights-1);
                scanf("%d", &lightIndex);
                if (lightStatus[lightIndex] == LIGHT_ON) {
                    lightStatus[lightIndex] = LIGHT_OFF;
                    printf("Light %d turned off\n", lightIndex+1);
                } else {
                    lightStatus[lightIndex] = LIGHT_ON;
                    printf("Light %d turned on\n", lightIndex+1);
                }
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}