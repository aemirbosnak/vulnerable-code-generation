//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep()
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int status; // 0 for OFF, 1 for ON
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char *name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, NAME_LENGTH);
        devices[device_count].status = 0; // Initially OFF
        device_count++;
        printf("Device '%s' added.\n", name);
    } else {
        printf("Maximum device limit reached.\n");
    }
}

void toggle_device(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void status_report() {
    printf("\nSmart Home Device Status Report:\n");
    for (int i = 0; i < device_count; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void schedule_device(const char *name, int seconds) {
    printf("Scheduling device '%s' to turn ON in %d seconds...\n", name, seconds);
    sleep(seconds);
    toggle_device(name);
}

void execute_command(const char *command) {
    char cmd[NAME_LENGTH];
    sscanf(command, "%s", cmd);

    if (strcmp(cmd, "ADD") == 0) {
        char name[NAME_LENGTH];
        sscanf(command + 4, "%s", name);
        add_device(name);
    } else if (strcmp(cmd, "TOGGLE") == 0) {
        char name[NAME_LENGTH];
        sscanf(command + 7, "%s", name);
        toggle_device(name);
    } else if (strcmp(cmd, "STATUS") == 0) {
        status_report();
    } else if (strcmp(cmd, "SCHEDULE") == 0) {
        char name[NAME_LENGTH];
        int seconds;
        sscanf(command + 9, "%s %d", name, &seconds);
        schedule_device(name, seconds);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char command[100];

    while (1) {
        printf("Enter command (ADD, TOGGLE, STATUS, SCHEDULE, EXIT): ");
        fgets(command, sizeof(command), stdin);
        trim_newline(command);

        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting Smart Home Automation.\n");
            break;
        }

        execute_command(command);
    }

    return 0;
}