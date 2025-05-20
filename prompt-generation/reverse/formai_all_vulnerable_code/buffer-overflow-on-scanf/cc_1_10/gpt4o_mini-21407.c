//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256
#define MAX_TIMESTAMP_LENGTH 25

void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void log_event(const char *event) {
    char timestamp[MAX_TIMESTAMP_LENGTH];
    get_current_time(timestamp, sizeof(timestamp));

    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        exit(1);
    }

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void simulate_event(const char *event) {
    log_event(event);
    printf("Event logged: %s\n", event);
}

void generate_events() {
    const char *events[] = {
        "System Booted",
        "User logged in",
        "User logged out",
        "Memory usage reached 80%",
        "Disk space low",
        "Network connection established",
        "Network connection lost",
        "Service started: HTTPD",
        "Service stopped: HTTPD",
        "Error: Out of memory",
        "Warning: High CPU usage",
        "System shutting down",
        "System restarted",
        "New device connected: /dev/sda",
        "Device removed: /dev/sda",
        "Kernel module loaded: module.ko",
        "Kernel module unloaded: module.ko"
    };

    size_t num_events = sizeof(events) / sizeof(events[0]);

    for (size_t i = 0; i < num_events; i++) {
        sleep(1); // Simulating time between events
        simulate_event(events[i]);
    }
}

void read_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file for reading.\n");
        return;
    }

    printf("\n--- Event Log ---\n");
    char line[MAX_EVENT_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared successfully.\n");
    } else {
        fprintf(stderr, "Could not clear log file.\n");
    }
}

void show_menu() {
    printf("\n--- Event Logger Menu ---\n");
    printf("1. Generate Events\n");
    printf("2. Read Log\n");
    printf("3. Clear Log\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_events();
                break;
            case 2:
                read_log();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting the event logger.\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    }

    return 0;
}