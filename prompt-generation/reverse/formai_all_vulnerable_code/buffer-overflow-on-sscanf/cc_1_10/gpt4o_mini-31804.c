//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum {OFF, ON} State;

typedef struct {
    char name[NAME_LENGTH];
    State state;
    int brightness; // For lights only
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} SmartHome;

void init_smart_home(SmartHome *home) {
    home->device_count = 0;
}

void add_device(SmartHome *home, const char *name) {
    if (home->device_count < MAX_DEVICES) {
        strncpy(home->devices[home->device_count].name, name, NAME_LENGTH);
        home->devices[home->device_count].state = OFF;
        home->devices[home->device_count].brightness = 0;
        home->device_count++;
        printf("Device '%s' added.\n", name);
    } else {
        printf("Device limit reached! Cannot add '%s'.\n", name);
    }
}

void toggle_device(SmartHome *home, int index) {
    if (index < 0 || index >= home->device_count) {
        printf("Invalid device index.\n");
        return;
    }

    Device *device = &home->devices[index];
    device->state = (device->state == OFF) ? ON : OFF;
    printf("Device '%s' is now %s.\n", device->name, device->state == ON ? "ON" : "OFF");
}

void set_brightness(SmartHome *home, int index, int brightness) {
    if (index < 0 || index >= home->device_count) {
        printf("Invalid device index.\n");
        return;
    }

    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }

    Device *device = &home->devices[index];
    device->brightness = brightness;
    printf("Set brightness of '%s' to %d%%.\n", device->name, brightness);
}

void list_devices(SmartHome *home) {
    if (home->device_count == 0) {
        printf("No devices found in the smart home.\n");
        return;
    }

    printf("Devices in Smart Home:\n");
    for (int i = 0; i < home->device_count; ++i) {
        Device *device = &home->devices[i];
        printf("%d: %s - %s (Brightness: %d%%)\n", 
            i, 
            device->name, 
            device->state == ON ? "ON" : "OFF", 
            device->brightness);
    }
}

void read_command(SmartHome *home) {
    char command[100], name[NAME_LENGTH];
    int index, brightness;

    printf("\nEnter command (ADD, TOGGLE, SET, LIST, EXIT): ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove newline

    if (strncmp(command, "ADD", 3) == 0) {
        sscanf(command + 4, "%s", name);
        add_device(home, name);
    } else if (strncmp(command, "TOGGLE", 6) == 0) {
        sscanf(command + 7, "%d", &index);
        toggle_device(home, index);
    } else if (strncmp(command, "SET", 3) == 0) {
        sscanf(command + 4, "%d %d", &index, &brightness);
        set_brightness(home, index, brightness);
    } else if (strncmp(command, "LIST", 4) == 0) {
        list_devices(home);
    } else if (strncmp(command, "EXIT", 4) == 0) {
        printf("Exiting Smart Home automation system. Goodbye!\n");
        exit(0);
    } else {
        printf("Unknown command.\n");
    }
}

int main() {
    SmartHome home;
    init_smart_home(&home);

    printf("Welcome to Retro Smart Home Automation!\n");
    printf("You can manage your devices with commands.\n");

    while (1) {
        read_command(&home);
    }

    return 0;
}