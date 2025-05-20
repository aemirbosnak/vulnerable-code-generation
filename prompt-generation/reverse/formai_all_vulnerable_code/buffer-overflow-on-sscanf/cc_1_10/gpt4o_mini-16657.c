//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LIGHTS 5
#define COMMAND_LENGTH 100

typedef struct {
    char name[20];
    bool isOn;
} SmartLight;

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light%d", i + 1);
        lights[i].isOn = false;
    }
}

void turnOnLight(SmartLight *light) {
    if (!light->isOn) {
        light->isOn = true;
        printf("%s is now ON.\n", light->name);
    } else {
        printf("%s is already ON.\n", light->name);
    }
}

void turnOffLight(SmartLight *light) {
    if (light->isOn) {
        light->isOn = false;
        printf("%s is now OFF.\n", light->name);
    } else {
        printf("%s is already OFF.\n", light->name);
    }
}

void statusReport(SmartLight lights[], int count) {
    printf("===== Light Status Report =====\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].isOn ? "ON" : "OFF");
    }
    printf("==============================\n");
}

void processCommand(SmartLight lights[], int count, char *command) {
    char action[10], lightName[20];
    sscanf(command, "%s %s", action, lightName);

    if (strcmp(action, "ON") == 0) {
        for (int i = 0; i < count; i++) {
            if (strcmp(lights[i].name, lightName) == 0) {
                turnOnLight(&lights[i]);
                return;
            }
        }
        printf("No light named %s found.\n", lightName);
    } else if (strcmp(action, "OFF") == 0) {
        for (int i = 0; i < count; i++) {
            if (strcmp(lights[i].name, lightName) == 0) {
                turnOffLight(&lights[i]);
                return;
            }
        }
        printf("No light named %s found.\n", lightName);
    } else if (strcmp(action, "STATUS") == 0) {
        statusReport(lights, count);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void displayMenu() {
    printf("=== Smart Home Light Control ===\n");
    printf("Available commands:\n");
    printf("1. ON <LightName> - Turn on a light\n");
    printf("2. OFF <LightName> - Turn off a light\n");
    printf("3. STATUS - Show status of all lights\n");
    printf("4. EXIT - Exit the program\n");
    printf("Enter command: ");
}

int main() {
    SmartLight lights[MAX_LIGHTS];
    char command[COMMAND_LENGTH];

    initializeLights(lights, MAX_LIGHTS);
    
    while (true) {
        displayMenu();
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting Smart Home Light Control...\n");
            break;
        }
        
        processCommand(lights, MAX_LIGHTS, command);
        sleep(1);  // Small delay for better readability
    }
    
    return 0;
}