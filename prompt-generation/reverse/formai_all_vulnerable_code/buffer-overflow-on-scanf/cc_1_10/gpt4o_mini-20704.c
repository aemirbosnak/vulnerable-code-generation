//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef enum {
    OFF,
    ON
} State;

typedef struct {
    char name[50];
    State state;
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} SmartHome;

void initialize_home(SmartHome *home) {
    home->device_count = 0;
}

void add_device(SmartHome *home, const char *device_name) {
    if (home->device_count < MAX_DEVICES) {
        strncpy(home->devices[home->device_count].name, device_name, sizeof(home->devices[home->device_count].name) - 1);
        home->devices[home->device_count].state = OFF;
        home->device_count++;
    } else {
        printf("Device limit reached! Unable to add %s\n", device_name);
    }
}

void toggle_device(SmartHome *home, const char *device_name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, device_name) == 0) {
            home->devices[i].state = (home->devices[i].state == OFF) ? ON : OFF;
            printf("%s is now %s\n", home->devices[i].name, home->devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device %s not found!\n", device_name);
}

void set_temperature(float *temperature, float new_temp) {
    *temperature = new_temp;
    printf("Thermostat temperature set to %.1f °C\n", *temperature);
}

void show_status(SmartHome *home, float thermostat_temp) {
    printf("Current status:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf("Device: %s, State: %s\n", home->devices[i].name, home->devices[i].state == ON ? "ON" : "OFF");
    }
    printf("Thermostat: %.1f °C\n", thermostat_temp);
}

void show_menu() {
    printf("\nSmart Home Automation Menu:\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Set Thermostat Temperature\n");
    printf("4. Show Status\n");
    printf("5. Exit\n");
}

int main() {
    SmartHome home;
    float thermostat_temp = 22.0; // Default temperature
    int choice;
    char device_name[50];
    
    initialize_home(&home);

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter device name to add: ");
                scanf("%s", device_name);
                add_device(&home, device_name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", device_name);
                toggle_device(&home, device_name);
                break;
            case 3:
                printf("Enter new temperature: ");
                float new_temp;
                scanf("%f", &new_temp);
                set_temperature(&thermostat_temp, new_temp);
                break;
            case 4:
                show_status(&home, thermostat_temp);
                break;
            case 5:
                printf("Exiting Smart Home Automation...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}