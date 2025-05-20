//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 50
#define CONFIG_FILE "config.txt"

typedef enum {
    LIGHT,
    THERMOSTAT,
    SECURITY_CAMERA,
    UNKNOWN
} DeviceType;

typedef struct {
    char name[NAME_LENGTH];
    DeviceType type;
    int status; // 0 = off, 1 = on
    int config_value; // For thermostats, this could be temperature setpoint
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void load_config() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        return;
    }
    
    while (fscanf(file, "%49s %d %d", devices[device_count].name, (int *)&devices[device_count].type, &devices[device_count].config_value) != EOF) {
        devices[device_count].status = 0; // Initialize all status to off
        device_count++;
        if (device_count >= MAX_DEVICES) {
            break; // Prevent overflow
        }
    }

    fclose(file);
}

void save_config() {
    FILE *file = fopen(CONFIG_FILE, "w");
    if (!file) {
        perror("Could not open config file for writing");
        return;
    }

    for (int i = 0; i < device_count; i++) {
        fprintf(file, "%s %d %d\n", devices[i].name, devices[i].type, devices[i].config_value);
    }

    fclose(file);
}

void toggle_device(int device_index) {
    devices[device_index].status = !devices[device_index].status;
    printf("%s is now %s\n", devices[device_index].name, devices[device_index].status ? "ON" : "OFF");
}

void configure_device(int device_index, int value) {
    devices[device_index].config_value = value;
    printf("Configured %s to value %d\n", devices[device_index].name, devices[device_index].config_value);
}

void list_devices() {
    printf("Smart Home Devices:\n");
    for (int i = 0; i < device_count; i++) {
        char *type_string;

        switch (devices[i].type) {
            case LIGHT: type_string = "Light"; break;
            case THERMOSTAT: type_string = "Thermostat"; break;
            case SECURITY_CAMERA: type_string = "Security Camera"; break;
            default: type_string = "Unknown"; break;
        }

        printf("%d: %s (%s) - Status: %s, Config Value: %d\n", 
               i, devices[i].name, type_string, 
               devices[i].status ? "ON" : "OFF", 
               devices[i].config_value);
    }
}

void execute_command() {
    char command[50];
    int device_index, value;

    while (1) {
        printf("Enter command (list/toggle/config/exit): ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            list_devices();
        } else if (strcmp(command, "toggle") == 0) {
            printf("Enter device index to toggle: ");
            scanf("%d", &device_index);
            if (device_index >= 0 && device_index < device_count) {
                toggle_device(device_index);
            } else {
                printf("Invalid device index.\n");
            }
        } else if (strcmp(command, "config") == 0) {
            printf("Enter device index to configure: ");
            scanf("%d", &device_index);
            if (device_index >= 0 && device_index < device_count) {
                printf("Enter new configuration value: ");
                scanf("%d", &value);
                configure_device(device_index, value);
            } else {
                printf("Invalid device index.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            save_config();
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
}

int main() {
    load_config();
    execute_command();
    return 0;
}