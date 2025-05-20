//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_SIZE 20

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[NAME_SIZE];
    DeviceState state;
} SmartDevice;

typedef struct {
    SmartDevice devices[MAX_DEVICES];
    int device_count;
} SmartHome;

void initialize_home(SmartHome *home) {
    home->device_count = 0;
    printf("Welcome to your Smart Home Control Center!\n");
}

void add_device(SmartHome *home, const char *device_name) {
    if (home->device_count < MAX_DEVICES) {
        strcpy(home->devices[home->device_count].name, device_name);
        home->devices[home->device_count].state = OFF;
        home->device_count++;
        printf("Device '%s' added!\n", device_name);
    } else {
        printf("Device limit reached!\n");
    }
}

void toggle_device(SmartHome *home, const char *device_name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, device_name) == 0) {
            home->devices[i].state = !home->devices[i].state;
            printf("Device '%s' is now %s.\n", device_name,
                    home->devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", device_name);
}

void list_devices(SmartHome *home) {
    printf("\nSmart Home Device List:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf(" - %s: %s\n", home->devices[i].name,
               home->devices[i].state == ON ? "ON" : "OFF");
    }
}

void control_loop(SmartHome *home) {
    char command[NAME_SIZE];
    while (1) {
        printf("\nEnter command (add [device_name], toggle [device_name], list, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            char device_name[NAME_SIZE];
            scanf("%s", device_name);
            add_device(home, device_name);
        } else if (strcmp(command, "toggle") == 0) {
            char device_name[NAME_SIZE];
            scanf("%s", device_name);
            toggle_device(home, device_name);
        } else if (strcmp(command, "list") == 0) {
            list_devices(home);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Control Center. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    SmartHome myHome;
    initialize_home(&myHome);
    
    control_loop(&myHome);
    
    return 0;
}