//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256

typedef struct {
    char timestamp[20];
    char event[MAX_EVENT_SIZE];
} LogEntry;

void get_current_time(char* buffer) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tm_info);
}

void log_event(const char* event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Error opening log file.\n");
        return;
    }

    LogEntry entry;
    get_current_time(entry.timestamp);
    strncpy(entry.event, event, MAX_EVENT_SIZE - 1);
    entry.event[MAX_EVENT_SIZE - 1] = '\0'; // Ensure null-termination

    fprintf(file, "[%s] %s\n", entry.timestamp, entry.event);
    fclose(file);
}

void display_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error opening log file.\n");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared successfully.\n");
    } else {
        fprintf(stderr, "Error clearing log file.\n");
    }
}

void print_menu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log Event\n");
    printf("2. Display Logs\n");
    printf("3. Clear Log\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char event[MAX_EVENT_SIZE];

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline after choice

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event, MAX_EVENT_SIZE, stdin);
                event[strcspn(event, "\n")] = 0; // Remove trailing newline
                log_event(event);
                printf("Event logged successfully.\n");
                break;
            case 2:
                printf("Displaying logs:\n");
                display_log();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting the event logger.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}