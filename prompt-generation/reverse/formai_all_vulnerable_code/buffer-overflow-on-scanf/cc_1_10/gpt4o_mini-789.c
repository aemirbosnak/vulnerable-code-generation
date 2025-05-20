//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event.log"
#define MAX_EVENT_LENGTH 256
#define MAX_BUFFER_SIZE 512

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    // Get the current time
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character

    // Prepare the log entry
    char log_entry[MAX_BUFFER_SIZE];
    snprintf(log_entry, sizeof(log_entry), "[%s] %s\n", time_str, event);

    // Write to the log
    fputs(log_entry, file);
    fclose(file);
}

void display_menu() {
    printf("\n=== Event Logger ===\n");
    printf("1. Log an event\n");
    printf("2. Show log entries\n");
    printf("3. Clear log file\n");
    printf("4. Exit\n");
    printf("=====================\n");
    printf("Please select an option: ");
}

void show_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    printf("\n=== Event Log Entries ===\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
    printf("==========================\n");
}

void clear_log_file() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Failed to clear log file");
        return;
    }
    fclose(file);
    printf("Log file cleared successfully!\n");
}

int main() {
    while (1) {
        display_menu();

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline from the input buffer

        char event[MAX_EVENT_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter the event description: ");
                fgets(event, sizeof(event), stdin);
                // Remove the newline character if present
                event[strcspn(event, "\n")] = '\0';
                log_event(event);
                printf("Event logged successfully!\n");
                break;
            case 2:
                show_logs();
                break;
            case 3:
                clear_log_file();
                break;
            case 4:
                printf("Exiting the logger. Have a great day!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
        sleep(1); // Adding a brief pause for user experience
    }

    return 0;
}