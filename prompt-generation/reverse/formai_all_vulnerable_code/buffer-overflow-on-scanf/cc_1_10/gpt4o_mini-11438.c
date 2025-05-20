//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum log entry size and buffer size
#define MAX_LOG_ENTRY_SIZE 256
#define MAX_LOG_BUFFER_SIZE 1024
#define LOG_FILE "event_log.txt"

// Function prototypes
void get_current_time(char *buffer, size_t size);
void log_event(const char *event);
void read_log();
void clear_log();
void display_menu();
void handle_user_input(int choice);

int main() {
    int user_choice;

    // Infinite loop for menu interaction
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        handle_user_input(user_choice);
    }

    return 0;
}

void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char timestamp[20];
    get_current_time(timestamp, sizeof(timestamp));

    // Write the timestamp and the event to the log file
    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
    printf("Event logged: %s\n", event);
}

void read_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char log_entry[MAX_LOG_ENTRY_SIZE];
    printf("\n--- Event Log ---\n");
    while (fgets(log_entry, sizeof(log_entry), file)) {
        printf("%s", log_entry);
    }
    fclose(file);
    printf("--- End of Log ---\n\n");
}

void clear_log() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Could not clear log file");
        return;
    }
    fclose(file);
    printf("Log cleared successfully.\n");
}

void display_menu() {
    printf("\n*** Event Logger Menu ***\n");
    printf("1. Log an event\n");
    printf("2. Read log\n");
    printf("3. Clear log\n");
    printf("4. Exit\n");
}

void handle_user_input(int choice) {
    char event[MAX_LOG_BUFFER_SIZE];

    switch (choice) {
        case 1:
            printf("Enter event description (max %d characters): ", MAX_LOG_BUFFER_SIZE);
            getchar(); // Clear the newline from previous input
            fgets(event, sizeof(event), stdin);
            // Remove newline character if present
            event[strcspn(event, "\n")] = 0;
            log_event(event);
            break;

        case 2:
            read_log();
            break;

        case 3:
            clear_log();
            break;

        case 4:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}