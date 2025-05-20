//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    bool isOn;
    int brightness; // Range from 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void addLight(const char *name) {
    if (lightCount < MAX_LIGHTS) {
        strncpy(lights[lightCount].name, name, NAME_LENGTH);
        lights[lightCount].isOn = false;
        lights[lightCount].brightness = 0;
        lightCount++;
        printf("Light '%s' added successfully.\n", name);
    } else {
        printf("Error: Maximum number of lights reached.\n");
    }
}

void toggleLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].isOn = !lights[index].isOn;
        printf("Light '%s' is now %s.\n", lights[index].name, lights[index].isOn ? "ON" : "OFF");
    } else {
        printf("Error: Invalid light index.\n");
    }
}

void changeBrightness(int index, int level) {
    if (index >= 0 && index < lightCount) {
        if (level < 0 || level > 100) {
            printf("Error: Brightness level must be between 0 and 100.\n");
        } else {
            lights[index].brightness = level;
            printf("Brightness of light '%s' set to %d.\n", lights[index].name, level);
        }
    } else {
        printf("Error: Invalid light index.\n");
    }
}

void displayStatus() {
    printf("\nSmart Light Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Light %d: %s | Status: %s | Brightness: %d\n", 
               i, lights[i].name, lights[i].isOn ? "ON" : "OFF", lights[i].brightness);
    }
    printf("\n");
}

int findLight(const char *name) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char command[100];
    char name[NAME_LENGTH];
    int index, brightness;

    printf("Welcome to Smart Home Light Control System\n");
    printf("Commands:\n");
    printf("1. add <name> - Add a new light\n");
    printf("2. toggle <name> - Toggle light on/off\n");
    printf("3. brightness <name> <level> - Change brightness of light\n");
    printf("4. status - Show status of all lights\n");
    printf("5. exit - Exit the program\n");

    while (true) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", name);
            addLight(name);
        } else if (strncmp(command, "toggle ", 7) == 0) {
            sscanf(command + 7, "%s", name);
            index = findLight(name);
            toggleLight(index);
        } else if (strncmp(command, "brightness ", 11) == 0) {
            sscanf(command + 11, "%s %d", name, &brightness);
            index = findLight(name);
            changeBrightness(index, brightness);
        } else if (strcmp(command, "status") == 0) {
            displayStatus();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Error: Unknown command. Please try again.\n");
        }
    }

    return 0;
}