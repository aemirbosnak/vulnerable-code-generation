//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define CMD_LEN 50

typedef struct {
    char name[20];
    int status; // 0: off, 1: on
} Device;

Device lights[MAX_DEVICES];
Device thermostat;

void initialize_devices() {
    for (int i = 0; i < MAX_DEVICES; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light%d", i + 1);
        lights[i].status = 0; // All lights are initially off
    }
    snprintf(thermostat.name, sizeof(thermostat.name), "Thermostat");
    thermostat.status = 22; // Default temperature set to 22 degrees
}

void toggle_light(int index) {
    if (index < 0 || index >= MAX_DEVICES) {
        printf("Invalid Light Number!\n");
        return;
    }
    lights[index].status = !lights[index].status;
    printf("%s is now %s.\n", lights[index].name, lights[index].status ? "ON" : "OFF");
}

void set_thermostat(int temp) {
    if (temp < 15 || temp > 30) {
        printf("Please set the thermostat to a value between 15 and 30 degrees.\n");
        return;
    }
    thermostat.status = temp;
    printf("Thermostat is set to %d degrees.\n", thermostat.status);
}

void display_status() {
    printf("Current Device Status:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].status ? "ON" : "OFF");
    }
    printf("%s: %d degrees\n", thermostat.name, thermostat.status);
}

int main() {
    char command[CMD_LEN];
    int light_number, temperature;

    initialize_devices();

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("Available commands:\n");
        printf("1. toggle <light_number>\n");
        printf("2. set_temp <temperature>\n");
        printf("3. status\n");
        printf("4. exit\n");
        printf("Enter command: ");
        fgets(command, CMD_LEN, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strncmp(command, "toggle", 6) == 0) {
            if (sscanf(command + 7, "%d", &light_number) == 1) {
                toggle_light(light_number - 1); // Convert to zero-based index
            } else {
                printf("Invalid command format. Use: toggle <light_number>\n");
            }
        } else if (strncmp(command, "set_temp", 8) == 0) {
            if (sscanf(command + 9, "%d", &temperature) == 1) {
                set_thermostat(temperature);
            } else {
                printf("Invalid command format. Use: set_temp <temperature>\n");
            }
        } else if (strncmp(command, "status", 6) == 0) {
            display_status();
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting Smart Home Automation System.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}