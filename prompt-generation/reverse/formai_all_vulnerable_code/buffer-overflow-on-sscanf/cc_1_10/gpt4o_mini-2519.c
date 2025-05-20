//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef enum {
    OFF = 0,
    ON = 1
} LightStatus;

typedef struct {
    char name[NAME_LENGTH];
    LightStatus status;
    int brightness; // 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void addLight(const char *name) {
    if (lightCount >= MAX_LIGHTS) {
        printf("Maximum light limit reached.\n");
        return;
    }
    strcpy(lights[lightCount].name, name);
    lights[lightCount].status = OFF;
    lights[lightCount].brightness = 0;
    lightCount++;
    printf("Added light: %s\n", name);
}

void toggleLight(int index) {
    if (index < 0 || index >= lightCount) {
        printf("Invalid light index.\n");
        return;
    }
    lights[index].status = (lights[index].status == ON) ? OFF : ON;
    printf("%s is now %s\n", lights[index].name, lights[index].status == ON ? "ON" : "OFF");
}

void setBrightness(int index, int brightness) {
    if (index < 0 || index >= lightCount) {
        printf("Invalid light index.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Set brightness of %s to %d%%\n", lights[index].name, brightness);
}

void displayLightStatus() {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Light %d - %s: %s, Brightness: %d%%\n", i, lights[i].name, lights[i].status == ON ? "ON" : "OFF", lights[i].brightness);
    }
}

void handleCommand(const char *command) {
    char action[20];
    char name[NAME_LENGTH];
    int index, brightness;

    if (sscanf(command, "add %s", name) == 1) {
        addLight(name);
    } else if (sscanf(command, "toggle %d", &index) == 1) {
        toggleLight(index);
    } else if (sscanf(command, "set %d %d", &index, &brightness) == 2) {
        setBrightness(index, brightness);
    } else if (strcmp(command, "status") == 0) {
        displayLightStatus();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[100];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Available commands: \n");
    printf("1. add <light_name>\n");
    printf("2. toggle <light_index>\n");
    printf("3. set <light_index> <brightness>\n");
    printf("4. status\n");
    printf("5. exit\n");

    while (1) {
        printf("\nEnter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the program...\n");
            break;
        }

        handleCommand(command);
    }

    return 0;
}