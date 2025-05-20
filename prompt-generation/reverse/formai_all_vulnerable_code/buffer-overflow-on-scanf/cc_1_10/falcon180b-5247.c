//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

struct Light {
    char name[50];
    bool isOn;
    int brightness;
};

void initLights(struct Light* lights) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        sprintf(&lights[i].name[5], "%d", i + 1);
        lights[i].isOn = false;
        lights[i].brightness = 0;
    }
}

void printLights(struct Light* lights) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s, %d\n", lights[i].name, lights[i].isOn? "On" : "Off", lights[i].brightness);
    }
}

int main() {
    struct Light lights[MAX_LIGHTS];
    initLights(lights);

    int choice;
    do {
        printf("\nSmart Home Light Control\n");
        printf("1. Turn on/off light\n");
        printf("2. Set brightness\n");
        printf("3. Print light status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light number: ");
                int lightNumber;
                scanf("%d", &lightNumber);
                if (lightNumber >= 0 && lightNumber < MAX_LIGHTS) {
                    struct Light* light = &lights[lightNumber];
                    if (light->isOn) {
                        light->isOn = false;
                    } else {
                        light->isOn = true;
                    }
                }
                break;
            case 2:
                printf("Enter light number: ");
                int lightNumber2;
                scanf("%d", &lightNumber2);
                if (lightNumber2 >= 0 && lightNumber2 < MAX_LIGHTS) {
                    struct Light* light = &lights[lightNumber2];
                    printf("Enter brightness (0-100): ");
                    int brightness;
                    scanf("%d", &brightness);
                    if (brightness >= 0 && brightness <= 100) {
                        light->brightness = brightness;
                    }
                }
                break;
            case 3:
                printLights(lights);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}