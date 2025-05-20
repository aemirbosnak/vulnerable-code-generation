//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef enum {
    OFF,
    ON
} LightState;

typedef struct {
    char name[NAME_LENGTH];
    LightState state;
    int brightness; // from 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void initLight(SmartLight *light, const char *name) {
    strncpy(light->name, name, NAME_LENGTH);
    light->state = OFF;
    light->brightness = 0;
}

void addLight(const char *name) {
    if (lightCount < MAX_LIGHTS) {
        initLight(&lights[lightCount], name);
        lightCount++;
        printf("Light '%s' added!\n", name);
    } else {
        printf("Cannot add more lights. Maximum limit reached!\n");
    }
}

void toggleLight(const char *name) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = (lights[i].state == OFF) ? ON : OFF;
            printf("Light '%s' is now %s.\n", lights[i].name, lights[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("No light found with the name '%s'.\n", name);
}

void setBrightness(const char *name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness level must be between 0 and 100.\n");
        return;
    }

    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = brightness;
            printf("Brightness for light '%s' set to %d%%.\n", lights[i].name, brightness);
            return;
        }
    }
    printf("No light found with the name '%s'.\n", name);
}

void displayLights() {
    printf("\nCurrent smart lights status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Light Name: %s, State: %s, Brightness: %d%%\n", lights[i].name, lights[i].state == ON ? "ON" : "OFF", lights[i].brightness);
    }
    printf("\n");
}

void commandInterpreter() {
    char command[100];
    char lightName[NAME_LENGTH];
    int brightness;

    printf("Smart Home Light Control - Type 'exit' to quit\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (sscanf(command, "add %s", lightName) == 1) {
            addLight(lightName);
        } else if (sscanf(command, "toggle %s", lightName) == 1) {
            toggleLight(lightName);
        } else if (sscanf(command, "set %s %d", lightName, &brightness) == 2) {
            setBrightness(lightName, brightness);
        } else if (strcmp(command, "status") == 0) {
            displayLights();
        } else {
            printf("Unknown command. Supported commands:\n");
            printf(" - add <light_name>\n");
            printf(" - toggle <light_name>\n");
            printf(" - set <light_name> <brightness>\n");
            printf(" - status\n");
        }
    }
}

int main() {
    commandInterpreter();
    return 0;
}