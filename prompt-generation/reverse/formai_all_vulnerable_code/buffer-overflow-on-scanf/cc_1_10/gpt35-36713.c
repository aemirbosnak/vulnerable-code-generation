//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10 // maximum number of lights in the house
#define MAX_NAME_LENGTH 20 // maximum length of the light name

typedef struct {
    char name[MAX_NAME_LENGTH];
    bool status;
} Light;

Light lights[MAX_LIGHTS];
int numLights = 0;

void addLight(char name[]) {
    if (numLights >= MAX_LIGHTS) {
        printf("Cannot add more lights\n");
        return;
    }

    Light newLight;
    strcpy(newLight.name, name);
    newLight.status = false;

    lights[numLights++] = newLight;
}

void toggleLight(char name[]) {
    for (int i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status = !lights[i].status;
            printf("%s light is now %s\n", lights[i].name, lights[i].status ? "on" : "off");
            return;
        }
    }

    printf("Could not find light with that name\n");
}

void printHelp() {
    printf("Commands:\n");
    printf("add <name> : add a new light\n");
    printf("toggle <name> : toggle the status of a light\n");
    printf("status : print the current status of all lights\n");
    printf("help : print this help message\n");
    printf("quit : exit the program\n");
}

void printStatus() {
    for (int i = 0; i < numLights; i++) {
        printf("%s : %s\n", lights[i].name, lights[i].status ? "on" : "off");
    }
}

int main() {
    char command[20];
    char name[MAX_NAME_LENGTH];

    printf("Welcome to the smart home light control program\n");

    while (true) {
        printf("Enter command (type 'help' for a list of commands): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name of new light: ");
            scanf("%s", name);
            addLight(name);
        } else if (strcmp(command, "toggle") == 0) {
            printf("Enter name of light to toggle: ");
            scanf("%s", name);
            toggleLight(name);
        } else if (strcmp(command, "status") == 0) {
            printStatus();
        } else if (strcmp(command, "help") == 0) {
            printHelp();
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Unknown command '%s'. Type 'help' for a list of commands\n", command);
        }
    }

    return 0;
}