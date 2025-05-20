//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 10

typedef struct {
    char name[50];
    int status; // 0 = OFF, 1 = ON
    int brightness; // 0 to 100
    int temperature; // in Celcius
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

// Functions to manage smart devices
void add_device(const char *name) {
    if (device_count >= MAX_DEVICES) {
        printf("Reached maximum device limit!\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].status = 0; // Initially OFF
    devices[device_count].brightness = 0; // Initially low brightness
    devices[device_count].temperature = 20; // Default temp
    device_count++;
    printf("Device '%s' added successfully.\n", name);
}

void toggle_device(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

void set_brightness(const char *name, int brightness) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            if (brightness < 0 || brightness > 100) {
                printf("Brightness should be between 0 and 100\n");
                return;
            }
            devices[i].brightness = brightness;
            printf("Brightness for '%s' set to %d%%.\n", name, brightness);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

void set_temperature(const char *name, int temperature) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].temperature = temperature;
            printf("Temperature for '%s' set to %d°C.\n", name, temperature);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

void show_status() {
    printf("Current Status of Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device Name: %s, Status: %s, Brightness: %d%%, Temperature: %d°C\n",
               devices[i].name,
               devices[i].status ? "ON" : "OFF",
               devices[i].brightness,
               devices[i].temperature);
    }
}

int main() {
    int choice;
    char name[50];
    int brightness, temperature;

    // Welcome message
    printf("Welcome to Smart Home Automation System\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Set Brightness\n");
        printf("4. Set Temperature\n");
        printf("5. Show Device Status\n");
        printf("6. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name to add: ");
                scanf("%s", name);
                add_device(name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", name);
                toggle_device(name);
                break;
            case 3:
                printf("Enter device name to set brightness: ");
                scanf("%s", name);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(name, brightness);
                break;
            case 4:
                printf("Enter device name to set temperature: ");
                scanf("%s", name);
                printf("Enter temperature (in Celsius): ");
                scanf("%d", &temperature);
                set_temperature(name, temperature);
                break;
            case 5:
                show_status();
                break;
            case 6:
                printf("Exiting the Smart Home Automation System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}