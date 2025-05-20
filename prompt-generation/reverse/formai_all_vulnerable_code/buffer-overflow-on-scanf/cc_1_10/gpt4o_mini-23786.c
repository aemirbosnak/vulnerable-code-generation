//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 50

typedef enum {
    OFF = 0,
    ON = 1
} State;

typedef struct {
    char name[NAME_LENGTH];
    State state;
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} SmartHome;

void initialize_home(SmartHome *home) {
    home->device_count = 0;
}

void add_device(SmartHome *home, const char *name) {
    if (home->device_count < MAX_DEVICES) {
        strncpy(home->devices[home->device_count].name, name, NAME_LENGTH);
        home->devices[home->device_count].state = OFF;
        home->device_count++;
    }
}

void toggle_device(SmartHome *home, const char *name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = !home->devices[i].state;
            printf("Toggle %s to %s\n", name, home->devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

void show_devices(const SmartHome *home) {
    printf("Smart Home Devices:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf(" - %s: %s\n", home->devices[i].name, home->devices[i].state == ON ? "ON" : "OFF");
    }
}

void schedule_device(SmartHome *home) {
    time_t t;
    struct tm *tm_info;
    char buffer[26];

    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("Scheduling a device control at the current time: %s\n", buffer);
    sleep(5); // Simulating a delay before the next action happens.
    
    for (int i = 0; i < home->device_count; i++) {
        // For the sake of example, toggle every device after 5 seconds.
        toggle_device(home, home->devices[i].name);
    }
}

void run_smart_home(SmartHome *home) {
    char command[NAME_LENGTH];
    
    while (1) {
        printf("Enter command (add/toggle/show/schedule/exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            char device_name[NAME_LENGTH];
            printf("Enter device name: ");
            scanf("%s", device_name);
            add_device(home, device_name);
        } else if (strcmp(command, "toggle") == 0) {
            char device_name[NAME_LENGTH];
            printf("Enter device name to toggle: ");
            scanf("%s", device_name);
            toggle_device(home, device_name);
        } else if (strcmp(command, "show") == 0) {
            show_devices(home);
        } else if (strcmp(command, "schedule") == 0) {
            schedule_device(home);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
}

int main() {
    SmartHome home;
    initialize_home(&home);
    
    run_smart_home(&home);
    
    return 0;
}