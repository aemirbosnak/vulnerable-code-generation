//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_LEN 30

typedef enum { OFF, ON } Status;

typedef struct {
    char name[NAME_LEN];
    Status status;
    int brightness; // 0-100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void addLight(const char *name) {
    if (lightCount < MAX_LIGHTS) {
        strncpy(lights[lightCount].name, name, NAME_LEN);
        lights[lightCount].status = OFF;
        lights[lightCount].brightness = 0;
        lightCount++;
        printf("Added light: %s\n", name);
    } else {
        printf("Light limit reached! Cannot add more lights.\n");
    }
}

void toggleLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].status = (lights[index].status == ON) ? OFF : ON;
        printf("%s is now %s\n", lights[index].name, (lights[index].status == ON) ? "ON" : "OFF");
    } else {
        printf("Invalid light index!\n");
    }
}

void setBrightness(int index, int brightness) {
    if (index >= 0 && index < lightCount) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d\n", lights[index].name, brightness);
        } else {
            printf("Brightness must be between 0 and 100!\n");
        }
    } else {
        printf("Invalid light index!\n");
    }
}

void showLights() {
    printf("Current Smart Lights:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%d: %s - %s, Brightness: %d%%\n", 
            i, 
            lights[i].name, 
            (lights[i].status == ON) ? "ON" : "OFF", 
            lights[i].brightness);
    }
}

void saveLights(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < lightCount; i++) {
        fprintf(file, "%s,%d,%d\n", lights[i].name, lights[i].status, lights[i].brightness);
    }
    fclose(file);
    printf("Lights state saved to %s\n", filename);
}

void loadLights(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    lightCount = 0; // Resetting light count
    while (fscanf(file, "%[^,],%d,%d\n", lights[lightCount].name, 
           (int*)&lights[lightCount].status, &lights[lightCount].brightness) == 3) {
        lightCount++;
        if (lightCount >= MAX_LIGHTS) break; // Prevent overflow
    }
    fclose(file);
    printf("Lights state loaded from %s\n", filename);
}

int main() {
    int choice, index, brightness;
    char name[NAME_LEN], filename[100];

    while (1) {
        printf("\n=== Smart Home Light Control ===\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Show Lights\n");
        printf("5. Save Lights\n");
        printf("6. Load Lights\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                addLight(name);
                break;
            case 2:
                printf("Enter light index to toggle: ");
                scanf("%d", &index);
                toggleLight(index);
                break;
            case 3:
                printf("Enter light index to set brightness: ");
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                setBrightness(index, brightness);
                break;
            case 4:
                showLights();
                break;
            case 5:
                printf("Enter filename to save lights: ");
                scanf("%s", filename);
                saveLights(filename);
                break;
            case 6:
                printf("Enter filename to load lights: ");
                scanf("%s", filename);
                loadLights(filename);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}