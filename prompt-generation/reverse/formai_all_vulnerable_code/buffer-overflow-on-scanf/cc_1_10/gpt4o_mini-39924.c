//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[50];
    int is_on;
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

// Function declarations
void add_device();
void toggle_device();
void list_devices();
void turn_on_all();
void turn_off_all();
void control_device(int device_index);

int main() {
    int choice;

    while (1) {
        printf("Smart Home Automation Control\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device Power\n");
        printf("3. List Devices\n");
        printf("4. Turn On All Devices\n");
        printf("5. Turn Off All Devices\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline character from the input buffer

        switch (choice) {
            case 1:
                add_device();
                break;
            case 2:
                toggle_device();
                break;
            case 3:
                list_devices();
                break;
            case 4:
                turn_on_all();
                break;
            case 5:
                turn_off_all();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_device() {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }

    printf("Enter device name: ");
    fgets(devices[device_count].name, 50, stdin);
    devices[device_count].name[strcspn(devices[device_count].name, "\n")] = 0; // Remove trailing newline
    devices[device_count].is_on = 0; // Initialize device as off
    device_count++;

    printf("Device '%s' added successfully!\n", devices[device_count - 1].name);
}

void toggle_device() {
    int index;
    printf("Enter device index to toggle (0 to %d): ", device_count - 1);
    scanf("%d", &index);
    getchar(); // clear newline character from the input buffer

    if (index < 0 || index >= device_count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    control_device(index);
}

void list_devices() {
    printf("List of Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d. %s - %s\n", i, devices[i].name, devices[i].is_on ? "ON" : "OFF");
    }
}

void turn_on_all() {
    for (int i = 0; i < device_count; i++) {
        devices[i].is_on = 1;
    }
    printf("All devices turned ON.\n");
}

void turn_off_all() {
    for (int i = 0; i < device_count; i++) {
        devices[i].is_on = 0;
    }
    printf("All devices turned OFF.\n");
}

void control_device(int device_index) {
    devices[device_index].is_on = !devices[device_index].is_on;
    printf("%s is now %s.\n", devices[device_index].name, devices[device_index].is_on ? "ON" : "OFF");
}