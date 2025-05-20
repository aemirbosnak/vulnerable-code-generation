//FormAI DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// A struct for a light with its id and status
struct Light {
    int id;
    bool status;
};

void initLights(struct Light* lights, int numLights) {
    for(int i = 0; i < numLights; i++) {
        lights[i].id = i + 1;
        lights[i].status = false;
    }
}

void printLights(struct Light* lights, int numLights) {
    printf("Light\tStatus\n");
    printf("===================\n");
    for(int i = 0; i < numLights; i++) {
        printf("%d\t%s\n", lights[i].id, lights[i].status ? "On" : "Off");
    }
    printf("===================\n");
}

void toggleLight(struct Light* light) {
    light->status = !light->status;
}

void turnOnLight(struct Light* light) {
    light->status = true;
}

void turnOffLight(struct Light* light) {
    light->status = false;
}

int main() {
    struct Light lights[MAX_LIGHTS];
    initLights(lights, MAX_LIGHTS);

    int choice;
    int lightId;
    struct Light* light;

    do {
        printf("1. Show all lights\n");
        printf("2. Turn on a light\n");
        printf("3. Turn off a light\n");
        printf("4. Toggle a light\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printLights(lights, MAX_LIGHTS);
                break;
            case 2:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                if(lightId < 1 || lightId > MAX_LIGHTS) {
                    printf("Invalid light id\n");
                }
                else {
                    light = &lights[lightId - 1];
                    turnOnLight(light);
                    printf("Turned on light %d\n", light->id);
                }
                break;
            case 3:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                if(lightId < 1 || lightId > MAX_LIGHTS) {
                    printf("Invalid light id\n");
                }
                else {
                    light = &lights[lightId - 1];
                    turnOffLight(light);
                    printf("Turned off light %d\n", light->id);
                }
                break;
            case 4:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                if(lightId < 1 || lightId > MAX_LIGHTS) {
                    printf("Invalid light id\n");
                }
                else {
                    light = &lights[lightId - 1];
                    toggleLight(light);
                    printf("Toggled light %d\n", light->id);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}