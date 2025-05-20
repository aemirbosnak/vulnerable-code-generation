//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20
#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    bool isOn;
} Light;

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    bool (*func)(void);
} Command;

Light lights[MAX_LIGHTS];
Command commands[MAX_COMMANDS];
int numLights;
int numCommands;

void turnOnLight(void) {
    for (int i = 0; i < numLights; i++) {
        if (!lights[i].isOn) {
            lights[i].isOn = true;
            printf("Turning on light %s\n", lights[i].name);
        }
    }
}

void turnOffLight(void) {
    for (int i = 0; i < numLights; i++) {
        if (lights[i].isOn) {
            lights[i].isOn = false;
            printf("Turning off light %s\n", lights[i].name);
        }
    }
}

void setLight(char* name, bool isOn) {
    for (int i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].isOn = isOn;
            printf("Setting light %s to %s\n", name, isOn? "on" : "off");
        }
    }
}

bool executeCommand(char* command) {
    for (int i = 0; i < numCommands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            (*commands[i].func)();
            return true;
        }
    }
    return false;
}

int main() {
    numLights = 0;
    numCommands = 0;

    char name[20];
    while (true) {
        printf("Enter a light name (or 'done' to finish): ");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        strcpy(lights[numLights].name, name);
        lights[numLights].isOn = false;
        numLights++;
    }

    while (true) {
        printf("Enter a command (or 'done' to finish): ");
        scanf("%s", commands[numCommands].command);
        if (strcmp(commands[numCommands].command, "done") == 0) {
            break;
        }
        commands[numCommands].func = turnOnLight;
        numCommands++;
    }

    while (true) {
        printf("Enter a command (or 'done' to finish): ");
        scanf("%s", commands[numCommands].command);
        if (strcmp(commands[numCommands].command, "done") == 0) {
            break;
        }
        commands[numCommands].func = turnOffLight;
        numCommands++;
    }

    while (true) {
        printf("Enter a command (or 'done' to finish): ");
        scanf("%s", commands[numCommands].command);
        if (strcmp(commands[numCommands].command, "done") == 0) {
            break;
        }
        commands[numCommands].func = setLight;
        numCommands++;
    }

    while (true) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter a command: ");
        scanf("%s", input);
        if (executeCommand(input)) {
            continue;
        }
        printf("Invalid command\n");
    }

    return 0;
}