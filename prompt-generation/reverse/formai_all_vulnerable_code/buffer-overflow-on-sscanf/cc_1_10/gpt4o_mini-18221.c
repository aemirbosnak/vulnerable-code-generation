//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[20];
    float brightness; // from 0.0 to 1.0
    int status; // 0 for OFF, 1 for ON
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light%d", i + 1);
        lights[i].brightness = 0.0;
        lights[i].status = 0; // OFF
    }
    light_count = MAX_LIGHTS;
}

void printLightStatus() {
    printf("\n--- Light Status ---\n");
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d, Name: %s, Brightness: %.2f, Status: %s\n",
               lights[i].id, lights[i].name, lights[i].brightness,
               lights[i].status == 1 ? "ON" : "OFF");
    }
    printf("---------------------\n");
}

void turnOnLight(int id) {
    if (id < 1 || id > light_count) {
        printf("Error: Light ID %d does not exist.\n", id);
        return;
    }
    lights[id - 1].status = 1; // Set status to ON
    printf("%s is turned ON.\n", lights[id - 1].name);
}

void turnOffLight(int id) {
    if (id < 1 || id > light_count) {
        printf("Error: Light ID %d does not exist.\n", id);
        return;
    }
    lights[id - 1].status = 0; // Set status to OFF
    printf("%s is turned OFF.\n", lights[id - 1].name);
}

void setBrightness(int id, float brightness) {
    if (id < 1 || id > light_count) {
        printf("Error: Light ID %d does not exist.\n", id);
        return;
    }
    if (brightness < 0.0 || brightness > 1.0) {
        printf("Error: Brightness must be between 0.0 and 1.0.\n");
        return;
    }
    lights[id - 1].brightness = brightness;
    printf("Brightness of %s set to %.2f.\n", lights[id - 1].name, brightness);
}

void fadeLights(float startBrightness, float endBrightness, int duration) {
    for (int i = 0; i < light_count; i++) {
        if (lights[i].status == 1) {
            float step = (endBrightness - startBrightness) / (duration * 100); // Per millisecond
            for (int j = 0; j < duration * 100; j++) {
                lights[i].brightness += step;
                if (lights[i].brightness < 0.0) lights[i].brightness = 0.0;
                if (lights[i].brightness > 1.0) lights[i].brightness = 1.0;
                printf("Fading %s: Brightness = %.2f\n", lights[i].name, lights[i].brightness);
                usleep(1000); // Sleep for 1ms
            }
        }
    }
}

void adjustLights(float factor) {
    for (int i = 0; i < light_count; i++) {
        if (lights[i].status == 1) {
            lights[i].brightness *= factor;
            if (lights[i].brightness > 1.0) lights[i].brightness = 1.0;
            printf("Adjusted %s brightness: %.2f\n", lights[i].name, lights[i].brightness);
        }
    }
}

void executeCommand(char* command) {
    char action[20];
    int id;
    float brightness;

    if (sscanf(command, "turn on %d", &id) == 1) {
        turnOnLight(id);
    } else if (sscanf(command, "turn off %d", &id) == 1) {
        turnOffLight(id);
    } else if (sscanf(command, "set brightness %d %f", &id, &brightness) == 2) {
        setBrightness(id, brightness);
    } else if (sscanf(command, "fade %f %f %d", &brightness, &brightness, &id) == 3) {
        fadeLights(brightness, brightness, id);
    } else if (sscanf(command, "adjust %f", &brightness) == 1) {
        adjustLights(brightness);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    initializeLights();
    printLightStatus();

    char command[100];
    while (1) {
        printf("\nEnter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        if (strcmp(command, "exit") == 0) break;
        executeCommand(command);
        printLightStatus();
    }

    return 0;
}