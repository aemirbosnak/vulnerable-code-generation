//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LIGHTS 10

struct Light {
    int id;
    int brightness;
    int status;
};

void initLights(struct Light *lights) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].brightness = 0;
        lights[i].status = 0;
    }
}

void setLightBrightness(struct Light *lights, int id, int brightness) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {
            lights[i].brightness = brightness;
            break;
        }
    }
}

void setLightStatus(struct Light *lights, int id, int status) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {
            lights[i].status = status;
            break;
        }
    }
}

void printLights(struct Light *lights) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].status == 1) {
            printf("Light %d is on with brightness %d\n", lights[i].id, lights[i].brightness);
        } else {
            printf("Light %d is off\n", lights[i].id);
        }
    }
}

int main() {
    struct Light lights[MAX_LIGHTS];
    initLights(lights);

    int choice;
    while (1) {
        printf("Enter your choice:\n1. Turn on/off light\n2. Set light brightness\n3. Print light status\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter light ID: ");
            int id;
            scanf("%d", &id);
            printf("Enter status (0 for off, 1 for on): ");
            int status;
            scanf("%d", &status);
            setLightStatus(lights, id, status);
            break;
        case 2:
            printf("Enter light ID: ");
            int lightId;
            scanf("%d", &lightId);
            printf("Enter brightness (0-100): ");
            int brightness;
            scanf("%d", &brightness);
            setLightBrightness(lights, lightId, brightness);
            break;
        case 3:
            printLights(lights);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}