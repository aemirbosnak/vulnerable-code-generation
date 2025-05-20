//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep function
#include <signal.h>

#define LIGHT_COUNT 5

typedef struct {
    int id;
    char name[30];
    int state; // 0: OFF, 1: ON
} Light;

Light lights[LIGHT_COUNT];

void initializeLights() {
    for (int i = 0; i < LIGHT_COUNT; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", lights[i].id);
        lights[i].state = 0; // Start all lights OFF
    }
}

void displayStatus() {
    printf("Smart Home Light Control System\n");
    printf("Current Light Status:\n");
    for (int i = 0; i < LIGHT_COUNT; i++) {
        printf("%s is %s\n", lights[i].name, lights[i].state ? "ON" : "OFF");
    }
    printf("\n");
}

void toggleLight(int id) {
    if (id < 1 || id > LIGHT_COUNT) {
        printf("Invalid Light ID: %d\n", id);
        return;
    }
    lights[id - 1].state = !lights[id - 1].state;
    printf("Toggled %s: now it is %s\n", lights[id - 1].name, lights[id - 1].state ? "ON" : "OFF");
}

void turnOnLight(int id) {
    if (id < 1 || id > LIGHT_COUNT) {
        printf("Invalid Light ID: %d\n", id);
        return;
    }
    lights[id - 1].state = 1;
    printf("%s turned ON\n", lights[id - 1].name);
}

void turnOffLight(int id) {
    if (id < 1 || id > LIGHT_COUNT) {
        printf("Invalid Light ID: %d\n", id);
        return;
    }
    lights[id - 1].state = 0;
    printf("%s turned OFF\n", lights[id - 1].name);
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nExiting Smart Home Light Control System...\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler); // Handle Ctrl+C for graceful exit
    initializeLights();

    char command[100];
    int lightId;

    printf("Welcome to Smart Home Light Control! Type 'help' for commands.\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "status") == 0) {
            displayStatus();
        } else if (sscanf(command, "toggle %d", &lightId) == 1) {
            toggleLight(lightId);
        } else if (sscanf(command, "on %d", &lightId) == 1) {
            turnOnLight(lightId);
        } else if (sscanf(command, "off %d", &lightId) == 1) {
            turnOffLight(lightId);
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("status         - Display status of all lights\n");
            printf("toggle <id>   - Toggle the state of the specified light\n");
            printf("on <id>       - Turn on the specified light\n");
            printf("off <id>      - Turn off the specified light\n");
            printf("help          - Show this help message\n");
            printf("exit          - Exit the program\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control System...\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}