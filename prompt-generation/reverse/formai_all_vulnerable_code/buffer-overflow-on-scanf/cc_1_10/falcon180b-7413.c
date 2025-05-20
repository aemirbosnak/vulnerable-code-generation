//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    bool isOn;
    int brightness;
} Light;

void initializeLights(Light lights[MAX_LIGHTS]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        lights[i].isOn = false;
        lights[i].brightness = 0;
    }
}

void printLights(Light lights[MAX_LIGHTS]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s %s %d\n", lights[i].name, lights[i].isOn? "On" : "Off", lights[i].brightness);
    }
}

void turnOnLight(Light lights[MAX_LIGHTS], int index) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].isOn = true;
    } else {
        printf("Invalid light index.\n");
    }
}

void turnOffLight(Light lights[MAX_LIGHTS], int index) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].isOn = false;
    } else {
        printf("Invalid light index.\n");
    }
}

void setBrightness(Light lights[MAX_LIGHTS], int index, int brightness) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].brightness = brightness;
    } else {
        printf("Invalid light index.\n");
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    initializeLights(lights);

    int choice;
    while (true) {
        printf("1. Turn on light\n2. Turn off light\n3. Set brightness\n4. Print lights\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter light index: ");
            int lightIndex;
            scanf("%d", &lightIndex);
            turnOnLight(lights, lightIndex);
            break;
        case 2:
            printf("Enter light index: ");
            int lightIndex2;
            scanf("%d", &lightIndex2);
            turnOffLight(lights, lightIndex2);
            break;
        case 3:
            printf("Enter light index: ");
            int lightIndex3;
            scanf("%d", &lightIndex3);
            printf("Enter brightness: ");
            int brightness;
            scanf("%d", &brightness);
            setBrightness(lights, lightIndex3, brightness);
            break;
        case 4:
            printLights(lights);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}