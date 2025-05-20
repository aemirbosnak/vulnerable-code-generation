//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256
#define MAX_EVENT_COUNT 100

typedef struct {
    time_t timestamp;
    char event[MAX_EVENT_SIZE];
} EventLog;

EventLog logs[MAX_EVENT_COUNT];
int log_count = 0;

void log_event(const char *event_description) {
    if (log_count >= MAX_EVENT_COUNT) {
        printf("Log is full. Cannot log new events.\n");
        return;
    }

    logs[log_count].timestamp = time(NULL);
    strncpy(logs[log_count].event, event_description, MAX_EVENT_SIZE - 1);
    logs[log_count].event[MAX_EVENT_SIZE - 1] = '\0'; // Ensure null termination
    log_count++;
}

void write_log_to_file() {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        printf("Error opening log file for writing.\n");
        return;
    }

    for (int i = 0; i < log_count; i++) {
        char time_buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&logs[i].timestamp);
        strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(file, "[%s] %s\n", time_buffer, logs[i].event);
    }

    fclose(file);
}

void display_logs() {
    for (int i = 0; i < log_count; i++) {
        char time_buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&logs[i].timestamp);
        strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("[%s] %s\n", time_buffer, logs[i].event);
    }
}

void clear_logs() {
    log_count = 0;
    printf("All logs cleared.\n");
}

void menu() {
    int choice;
    char event_description[MAX_EVENT_SIZE];

    do {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log an event\n");
        printf("2. Display all logs\n");
        printf("3. Write logs to file\n");
        printf("4. Clear logs\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event_description, MAX_EVENT_SIZE, stdin);
                event_description[strcspn(event_description, "\n")] = 0; // Remove newline
                log_event(event_description);
                break;
            case 2:
                display_logs();
                break;
            case 3:
                write_log_to_file();
                printf("Logs written to %s\n", LOG_FILE);
                break;
            case 4:
                clear_logs();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Event Logger!\n");
    menu();
    return 0;
}