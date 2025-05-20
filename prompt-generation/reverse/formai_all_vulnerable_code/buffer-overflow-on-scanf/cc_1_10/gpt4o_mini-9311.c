//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef enum {
    OFF = 0,
    ON = 1
} State;

typedef struct {
    char name[MAX_NAME_LENGTH];
    State state;
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} SmartHome;

// Function prototypes
void initialize_home(SmartHome *home);
void add_device(SmartHome *home, char *name);
void remove_device(SmartHome *home, char *name);
void switch_device(SmartHome *home, char *name, State state);
void list_devices(SmartHome *home);
Device *find_device(SmartHome *home, char *name);

int main() {
    SmartHome home;
    initialize_home(&home);

    int choice;
    char device_name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Remove Device\n");
        printf("3. Switch Device\n");
        printf("4. List Devices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(device_name, MAX_NAME_LENGTH, stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                add_device(&home, device_name);
                break;
                
            case 2:
                printf("Enter device name: ");
                fgets(device_name, MAX_NAME_LENGTH, stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                remove_device(&home, device_name);
                break;

            case 3:
                printf("Enter device name: ");
                fgets(device_name, MAX_NAME_LENGTH, stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                printf("Enter state (0 for OFF, 1 for ON): ");
                int state;
                scanf("%d", &state);
                switch_device(&home, device_name, (State)state);
                break;

            case 4:
                list_devices(&home);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void initialize_home(SmartHome *home) {
    home->device_count = 0;
}

void add_device(SmartHome *home, char *name) {
    if (home->device_count >= MAX_DEVICES) {
        printf("Cannot add more devices. Limit reached.\n");
        return;
    }
    strcpy(home->devices[home->device_count].name, name);
    home->devices[home->device_count].state = OFF;
    home->device_count++;
    printf("Device '%s' added successfully.\n", name);
}

void remove_device(SmartHome *home, char *name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            for (int j = i; j < home->device_count - 1; j++) {
                home->devices[j] = home->devices[j + 1];
            }
            home->device_count--;
            printf("Device '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void switch_device(SmartHome *home, char *name, State state) {
    Device *device = find_device(home, name);
    if (device != NULL) {
        device->state = state;
        printf("Device '%s' switched %s.\n", name, state == ON ? "ON" : "OFF");
    } else {
        printf("Device '%s' not found.\n", name);
    }
}

Device *find_device(SmartHome *home, char *name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            return &home->devices[i];
        }
    }
    return NULL;
}

void list_devices(SmartHome *home) {
    if (home->device_count == 0) {
        printf("No devices found.\n");
        return;
    }
    printf("List of devices:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf(" - %s: %s\n", home->devices[i].name, home->devices[i].state == ON ? "ON" : "OFF");
    }
}