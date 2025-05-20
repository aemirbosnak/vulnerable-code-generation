//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Define maximum length for log messages
#define MAX_LOG_LENGTH 256
// Define path for log file
#define LOG_FILE "event_log.txt"

// Function prototypes
void log_event(const char *event_message);
void get_current_time(char *buffer, size_t buffer_size);
void display_logs();
void clear_logs();

int main() {
    int choice;

    while (1) {
        printf("\nSystem Event Logger Menu:\n");
        printf("1. Log an event\n");
        printf("2. Display logs\n");
        printf("3. Clear logs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char event_message[MAX_LOG_LENGTH];
                printf("Enter the event message: ");
                // Clear the buffer before taking the input
                getchar(); // Consume the newline from previous input
                fgets(event_message, MAX_LOG_LENGTH, stdin);
                // Remove newline character from string
                event_message[strcspn(event_message, "\n")] = 0;
                log_event(event_message);
                break;
            }
            case 2:
                display_logs();
                break;
            case 3:
                clear_logs();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void log_event(const char *event_message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }

    char time_buffer[20];
    get_current_time(time_buffer, sizeof(time_buffer));
    fprintf(log_file, "[%s] %s\n", time_buffer, event_message);
    fclose(log_file);
    printf("Event logged successfully.\n");
}

void get_current_time(char *buffer, size_t buffer_size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void display_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file for reading!\n");
        return;
    }

    char line[MAX_LOG_LENGTH];
    printf("\nEvent Logs:\n");
    while (fgets(line, sizeof(line), log_file)) {
        printf("%s", line);
    }
    fclose(log_file);
}

void clear_logs() {
    if (remove(LOG_FILE) == 0) {
        printf("Logs cleared successfully.\n");
    } else {
        fprintf(stderr, "Error clearing log file!\n");
    }
}