//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 256
#define LOG_FILE "event_log.txt"

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    
    if (file == NULL) {
        fprintf(stderr, "Error opening log file.\n");
        return;
    }

    // Get the current time
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local);

    // Write the log entry
    fprintf(file, "[%s] %s\n", time_str, event);
    fclose(file);
}

void display_menu() {
    printf("=== Event Logger ===\n");
    printf("1. Log a new event\n");
    printf("2. Exit\n");
    printf("====================\n");
}

int main() {
    char event[MAX_EVENT_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        if (choice == 1) {
            printf("Enter event description: ");
            fgets(event, MAX_EVENT_LENGTH, stdin);
            event[strcspn(event, "\n")] = 0; // Remove the newline character

            log_event(event);
            printf("Event logged successfully!\n");
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}