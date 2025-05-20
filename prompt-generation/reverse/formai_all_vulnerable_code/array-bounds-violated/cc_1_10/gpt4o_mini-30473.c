//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int brightness; // 0 to 100
    int status; // 0: OFF, 1: ON
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void initializeLights() {
    strcpy(lights[0].name, "Living Room");
    lights[0].brightness = 0;
    lights[0].status = 0;

    strcpy(lights[1].name, "Kitchen");
    lights[1].brightness = 0;
    lights[1].status = 0;

    light_count = 2; // Initialize with 2 lights for simplicity
}

void showLights() {
    printf("\nAvailable Smart Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%d. %s - Status: %s, Brightness: %d%%\n", 
                i + 1, 
                lights[i].name, 
                lights[i].status ? "ON" : "OFF", 
                lights[i].brightness);
    }
}

void turnOnLight(int index) {
    if (index < light_count) {
        lights[index].status = 1;
        printf("%s is now ON with brightness %d%%.\n", lights[index].name, lights[index].brightness);
    } else {
        printf("Invalid light selection.\n");
    }
}

void turnOffLight(int index) {
    if (index < light_count) {
        lights[index].status = 0;
        printf("%s is now OFF.\n", lights[index].name);
    } else {
        printf("Invalid light selection.\n");
    }
}

void setBrightness(int index, int brightness) {
    if (index < light_count) {
        if (brightness < 0 || brightness > 100) {
            printf("Brightness must be between 0 and 100.\n");
            return;
        }
        lights[index].brightness = brightness;
        printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
    } else {
        printf("Invalid light selection.\n");
    }
}

void displayMenu() {
    printf("\n--- Smart Home Light Control ---\n");
    printf("1. Show Lights\n");
    printf("2. Turn ON Light\n");
    printf("3. Turn OFF Light\n");
    printf("4. Set Brightness\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    int choice, light_index, brightness;

    initializeLights();

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showLights();
                break;
            case 2:
                showLights();
                printf("Select light to turn ON (1 - %d): ", light_count);
                scanf("%d", &light_index);
                turnOnLight(light_index - 1);
                break;
            case 3:
                showLights();
                printf("Select light to turn OFF (1 - %d): ", light_count);
                scanf("%d", &light_index);
                turnOffLight(light_index - 1);
                break;
            case 4:
                showLights();
                printf("Select light to set brightness (1 - %d): ", light_count);
                scanf("%d", &light_index);
                printf("Enter brightness (0 - 100): ");
                scanf("%d", &brightness);
                setBrightness(light_index - 1, brightness);
                break;
            case 5:
                printf("Exiting Smart Home Light Control. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}