//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 256
#define LOG_FILE "event_log.txt"

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local);

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void view_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char line[MAX_EVENT_LENGTH + 30]; // To include the timestamp
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("Log cleared successfully.\n");
    } else {
        perror("Error clearing log file");
    }
}

void display_menu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log an Event\n");
    printf("2. View Log\n");
    printf("3. Clear Log\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char event[MAX_EVENT_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the event (max %d characters): ", MAX_EVENT_LENGTH);
                fgets(event, sizeof(event), stdin);
                event[strcspn(event, "\n")] = '\0'; // Remove the newline character
                log_event(event);
                printf("Event logged successfully!\n");
                break;
            case 2:
                view_log();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting the logger. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}