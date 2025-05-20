//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 50

typedef struct {
    char name[30];
    int status; // 0 for OFF, 1 for ON
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(char *name) {
    if (device_count >= MAX_DEVICES) {
        printf("Cannot add more devices, maximum limit reached.\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].status = 0; // Device is OFF by default
    device_count++;
    printf("Device '%s' added successfully!\n", name);
}

void list_devices() {
    printf("\nCurrent Devices in Smart Home:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d. %s - %s\n", i + 1, devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void toggle_device(int index) {
    if (index < 0 || index >= device_count) {
        printf("Invalid device index!\n");
        return;
    }
    devices[index].status = !devices[index].status; // Toggle status
    printf("Device '%s' is now %s.\n", devices[index].name, devices[index].status ? "ON" : "OFF");
}

void get_device_status(int index) {
    if (index < 0 || index >= device_count) {
        printf("Invalid device index!\n");
        return;
    }
    printf("Device '%s' is currently %s.\n", devices[index].name, devices[index].status ? "ON" : "OFF");
}

void schedule_device(int index, int hour, int minute, int duration) {
    if (index < 0 || index >= device_count) {
        printf("Invalid device index!\n");
        return;
    }

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid time for scheduling!\n");
        return;
    }

    printf("Scheduling device '%s' to turn ON at %02d:%02d for %d minutes...\n", 
            devices[index].name, hour, minute, duration);

    // Simulate scheduling
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    rawtime = mktime(timeinfo);
    
    sleep(duration * 60); // Simulate wait
    printf("Scheduled time reached. Device '%s' is now ON for %d minutes.\n", devices[index].name, duration);
    devices[index].status = 1; // Set device status to ON
}

void command_interpreter() {
    char command[50];
    while (1) {
        printf("\nEnter command (ADD, LIST, TOGGLE, GET, SCHEDULE, EXIT): ");
        scanf(" %49[^\n]", command);
        
        if (strcmp(command, "EXIT") == 0) {
            break;
        } else if (strcmp(command, "ADD") == 0) {
            char device_name[30];
            printf("Enter device name: ");
            scanf(" %29[^\n]", device_name);
            add_device(device_name);
        } else if (strcmp(command, "LIST") == 0) {
            list_devices();
        } else if (strcmp(command, "TOGGLE") == 0) {
            int index;
            printf("Enter device index to toggle (1 to %d): ", device_count);
            scanf("%d", &index);
            toggle_device(index - 1);
        } else if (strcmp(command, "GET") == 0) {
            int index;
            printf("Enter device index to get status (1 to %d): ", device_count);
            scanf("%d", &index);
            get_device_status(index - 1);
        } else if (strcmp(command, "SCHEDULE") == 0) {
            int index, hour, minute, duration;
            printf("Enter device index to schedule (1 to %d): ", device_count);
            scanf("%d", &index);
            printf("Enter hour (0-23): ");
            scanf("%d", &hour);
            printf("Enter minute (0-59): ");
            scanf("%d", &minute);
            printf("Enter duration in minutes: ");
            scanf("%d", &duration);
            schedule_device(index - 1, hour, minute, duration);
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    command_interpreter();
    printf("Exiting system. Goodbye!\n");
    return 0;
}