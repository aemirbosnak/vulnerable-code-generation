//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int intensity; // 0 (off) to 100 (full brightness)
    int state; // 0 (off), 1 (on)
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void addLight(const char *name) {
    if (lightCount < MAX_LIGHTS) {
        strncpy(lights[lightCount].name, name, NAME_LENGTH);
        lights[lightCount].intensity = 0;
        lights[lightCount].state = 0; // Initially off
        lightCount++;
        printf("Added light: %s\n", name);
    } else {
        printf("Cannot add more lights. Maximum limit reached!\n");
    }
}

void setIntensity(const char *name, int intensity) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (intensity >= 0 && intensity <= 100) {
                lights[i].intensity = intensity;
                printf("Set intensity of %s to %d%%\n", name, intensity);
            } else {
                printf("Intensity must be between 0 and 100.\n");
            }
            return;
        }
    }
    printf("Light %s not found!\n", name);
}

void switchLight(const char *name, int state) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = state;
            const char* stateString = state ? "on" : "off";
            printf("Switched %s %s\n", name, stateString);
            return;
        }
    }
    printf("Light %s not found!\n", name);
}

void listLights() {
    printf("Current lights:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Name: %s, State: %s, Intensity: %d%%\n", 
               lights[i].name, 
               lights[i].state ? "on" : "off", 
               lights[i].intensity);
    }
}

void controlLights() {
    char command[50];
    char name[NAME_LENGTH];
    int intensity, state;

    while (1) {
        printf("\nEnter command (add, switch, set, list, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter light name: ");
            scanf("%s", name);
            addLight(name);
        } else if (strcmp(command, "switch") == 0) {
            printf("Enter light name: ");
            scanf("%s", name);
            printf("Enter state (1 for on, 0 for off): ");
            scanf("%d", &state);
            switchLight(name, state);
        } else if (strcmp(command, "set") == 0) {
            printf("Enter light name: ");
            scanf("%s", name);
            printf("Enter intensity (0-100): ");
            scanf("%d", &intensity);
            setIntensity(name, intensity);
        } else if (strcmp(command, "list") == 0) {
            listLights();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    controlLights();
    return 0;
}