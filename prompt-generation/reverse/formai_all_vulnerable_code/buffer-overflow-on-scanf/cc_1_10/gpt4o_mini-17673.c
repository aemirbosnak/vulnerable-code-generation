//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define PASSCODE "1234" // Simple passcode for demo purposes

typedef struct {
    char name[30];
    int status; // 0 - off, 1 - on
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;
char passcode_input[5];

void add_device(const char* device_name) {
    if (device_count >= MAX_DEVICES) {
        printf("Warning: Device limit reached.\n");
    } else {
        strcpy(devices[device_count].name, device_name);
        devices[device_count].status = 0; // Initially off
        device_count++;
        printf("Device '%s' has been added.\n", device_name);
    }
}

void toggle_device(const char* device_name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            devices[i].status = !devices[i].status; // Toggle status
            const char* status_str = devices[i].status ? "on" : "off";
            printf("Device '%s' turned %s.\n", device_name, status_str);
            return;
        }
    }
    printf("Warning: Device '%s' not found.\n", device_name);
}

void list_devices() {
    printf("Listing devices:\n");
    for (int i = 0; i < device_count; i++) {
        const char* status_str = devices[i].status ? "on" : "off";
        printf("- %s: %s\n", devices[i].name, status_str);
    }
}

int verify_access() {
    printf("Enter passcode to access the system: ");
    fgets(passcode_input, sizeof(passcode_input), stdin);
    
    // Remove newline character at the end of passcode_input
    passcode_input[strcspn(passcode_input, "\n")] = 0;

    if (strcmp(passcode_input, PASSCODE) == 0) {
        return 1; // Access granted
    } else {
        printf("Warning: Unauthorized access attempt detected!\n");
        return 0; // Access denied
    }
}

void prompt_user() {
    printf("\nWelcome to the paranoid smart home automation system!\n");
    while (1) {
        if (!verify_access()) {
            continue; // Repeat access verification
        }

        printf("Choose an action:\n");
        printf("1. Add device\n2. Toggle device\n3. List devices\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: {
                char device_name[30];
                printf("Enter device name: ");
                fgets(device_name, sizeof(device_name), stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                add_device(device_name);
                break;
            }
            case 2: {
                char device_name[30];
                printf("Enter device name to toggle: ");
                fgets(device_name, sizeof(device_name), stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                toggle_device(device_name);
                break;
            }
            case 3:
                list_devices();
                break;
            case 4:
                printf("Exiting paranoid smart home system. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Short delay for paranoia
    }
}

int main() {
    printf("Initializing paranoid smart home automation...\n");
    prompt_user();
    return 0;
}