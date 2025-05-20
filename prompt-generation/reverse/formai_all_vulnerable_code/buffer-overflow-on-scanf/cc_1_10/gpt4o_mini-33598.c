//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 100
#define DEVICE_NAME_LENGTH 50

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    int power_state; // 0 for OFF, 1 for ON
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void printDevices() {
    printf("Current devices in the system:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device %d: %s, Power State: %s\n", 
            i + 1, 
            devices[i].name, 
            devices[i].power_state ? "ON" : "OFF");
    }
}

void addDevice(const char* name) {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].power_state = 0; // Initially OFF
    device_count++;
    printf("Added Device: %s\n", name);
}

void toggleDevice(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].power_state = !devices[i].power_state;
            printf("%s is now %s\n", name, devices[i].power_state ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void scheduleDevice(const char* name, int hours, int minutes) {
    time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    timeinfo->tm_hour = hours;
    timeinfo->tm_min = minutes;
    timeinfo->tm_sec = 0;
    
    time_t scheduled_time = mktime(timeinfo);
    
    if (scheduled_time < rawtime) {
        printf("Scheduled time must be in the future.\n");
        return;
    }
    
    printf("Scheduling %s to turn ON at %02d:%02d\n", name, hours, minutes);
    
    // Sleeping until the scheduled time
    sleep(difftime(scheduled_time, rawtime));
    toggleDevice(name);
}

int main() {
    char command[100];
    char device_name[DEVICE_NAME_LENGTH];
    int hours, minutes;
    
    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printf("\nCommand (add, toggle, schedule, list, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            printf("Enter device name: ");
            scanf("%s", device_name);
            addDevice(device_name);
        } 
        else if (strcmp(command, "toggle") == 0) {
            printf("Enter device name to toggle: ");
            scanf("%s", device_name);
            toggleDevice(device_name);
        } 
        else if (strcmp(command, "schedule") == 0) {
            printf("Enter device name to schedule: ");
            scanf("%s", device_name);

            printf("Enter time (HH MM): ");
            scanf("%d %d", &hours, &minutes);

            scheduleDevice(device_name, hours, minutes);
        } 
        else if (strcmp(command, "list") == 0) {
            printDevices();
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation System...\n");
            break;
        } 
        else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}