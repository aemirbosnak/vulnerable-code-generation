//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int status;
} Light;

void turnOnLight(Light *light) {
    printf("Turning on light %s...\n", light->name);
    light->status = TRUE;
}

void turnOffLight(Light *light) {
    printf("Turning off light %s...\n", light->name);
    light->status = FALSE;
}

void toggleLight(Light *light) {
    if (light->status == TRUE) {
        turnOffLight(light);
    } else {
        turnOnLight(light);
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    int numLights, i;

    printf("Enter the number of lights: ");
    scanf("%d", &numLights);

    for (i = 0; i < numLights; i++) {
        printf("Enter the name of light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].status = FALSE;
    }

    while (TRUE) {
        printf("\nSelect an option:\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Toggle a light\n");
        printf("4. Exit\n");
        scanf("%d", &i);

        switch (i) {
        case 1:
            printf("Enter the name of the light to turn on: ");
            scanf("%s", lights[0].name);
            turnOnLight(&lights[0]);
            break;

        case 2:
            printf("Enter the name of the light to turn off: ");
            scanf("%s", lights[0].name);
            turnOffLight(&lights[0]);
            break;

        case 3:
            printf("Enter the name of the light to toggle: ");
            scanf("%s", lights[0].name);
            toggleLight(&lights[0]);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}