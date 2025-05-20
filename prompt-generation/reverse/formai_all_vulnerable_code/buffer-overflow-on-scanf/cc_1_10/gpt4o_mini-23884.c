//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 5

typedef struct {
    char name[30];
    int isOn;
    int brightness; // from 0 to 100
} Light;

void initializeLights(Light lights[]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].isOn = 0;
        lights[i].brightness = 0;
    }
}

void printLights(Light lights[]) {
    printf("\n--- Smart Home Light Control ---\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s, Brightness: %d%%\n", 
            lights[i].name, 
            lights[i].isOn ? "On" : "Off", 
            lights[i].brightness);
    }
    printf("--------------------------------\n");
}

void toggleLight(Light *light) {
    light->isOn = !light->isOn;
}

void setBrightness(Light *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
    } else {
        light->brightness = brightness;
    }
}

void showMenu() {
    printf("\nAvailable actions:\n");
    printf("1. Toggle Light\n");
    printf("2. Set Brightness\n");
    printf("3. View Lights\n");
    printf("4. Exit\n");
}

int main() {
    Light lights[MAX_LIGHTS];
    initializeLights(lights);
    
    int choice, lightIndex, brightness;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select light number (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= MAX_LIGHTS) {
                    toggleLight(&lights[lightIndex - 1]);
                    printf("%s toggled %s.\n", 
                        lights[lightIndex - 1].name, 
                        lights[lightIndex - 1].isOn ? "On" : "Off");
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 2:
                printf("Select light number (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= MAX_LIGHTS) {
                    printf("Enter brightness (0-100): ");
                    scanf("%d", &brightness);
                    setBrightness(&lights[lightIndex - 1], brightness);
                    printf("Brightness for %s set to %d%%.\n", 
                        lights[lightIndex - 1].name, 
                        lights[lightIndex - 1].brightness);
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 3:
                printLights(lights);
                break;

            case 4:
                printf("Exiting Smart Home Light Control. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        sleep(2); // Relaxing pause before next action
    }

    return 0;
}