//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    int is_on;
    int brightness; // 0 to 100 for lights
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, DEVICE_NAME_LENGTH);
        devices[device_count].is_on = 0;
        devices[device_count].brightness = 0;
        device_count++;
        printf("Device %s added successfully.\n", name);
    } else {
        printf("Device limit reached. Can't add more devices.\n");
    }
}

void toggle_device(int index) {
    if (index < 0 || index >= device_count) {
        printf("Invalid device index.\n");
        return;
    }

    devices[index].is_on = !devices[index].is_on;
    printf("Device %s is now %s.\n", devices[index].name, devices[index].is_on ? "ON" : "OFF");
}

void set_brightness(int index, int brightness) {
    if (index < 0 || index >= device_count) {
        printf("Invalid device index.\n");
        return;
    }

    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }

    devices[index].brightness = brightness;
    printf("Brightness of device %s set to %d%%.\n", devices[index].name, brightness);
}

void list_devices() {
    if (device_count == 0) {
        printf("No devices found.\n");
        return;
    }

    printf("Smart Home Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d: %s - %s, Brightness: %d%%\n", i, devices[i].name, devices[i].is_on ? "ON" : "OFF", devices[i].brightness);
    }
}

void show_menu() {
    printf("\nSmart Home Automation System\n");
    printf("1. List devices\n");
    printf("2. Add device\n");
    printf("3. Toggle device\n");
    printf("4. Set device brightness\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, index, brightness;
    char device_name[DEVICE_NAME_LENGTH];

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_devices();
                break;
            case 2:
                printf("Enter device name: ");
                scanf("%s", device_name);
                add_device(device_name);
                break;
            case 3:
                printf("Enter device index to toggle (0-%d): ", device_count - 1);
                scanf("%d", &index);
                toggle_device(index);
                break;
            case 4:
                printf("Enter device index to set brightness (0-%d): ", device_count - 1);
                scanf("%d", &index);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index, brightness);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}