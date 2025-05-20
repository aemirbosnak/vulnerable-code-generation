//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define EVENT_MAX_LENGTH 256
#define TIMESTAMP_LENGTH 30

void log_event(const char *event);
void get_current_time(char *timestamp);
void display_menu();
void clear_log();

int main() {
    int choice;
    char event[EVENT_MAX_LENGTH];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consumes the newline character

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event, EVENT_MAX_LENGTH, stdin);
                event[strcspn(event, "\n")] = 0; // remove newline
                log_event(event);
                break;
            case 2:
                printf("Clearing log...\n");
                clear_log();
                printf("Log cleared successfully!\n");
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return;
    }

    char timestamp[TIMESTAMP_LENGTH];
    get_current_time(timestamp);

    fprintf(file, "%s: %s\n", timestamp, event);
    fclose(file);
}

void get_current_time(char *timestamp) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, TIMESTAMP_LENGTH, "%Y-%m-%d %H:%M:%S", tm_info);
}

void display_menu() {
    printf("\n*** Event Logger Menu ***\n");
    printf("1. Log a new event\n");
    printf("2. Clear log\n");
    printf("3. Exit\n");
}

void clear_log() {
    FILE *file = fopen(LOG_FILE, "w");
    if (!file) {
        perror("Could not clear log file");
        return;
    }
    fclose(file);
}