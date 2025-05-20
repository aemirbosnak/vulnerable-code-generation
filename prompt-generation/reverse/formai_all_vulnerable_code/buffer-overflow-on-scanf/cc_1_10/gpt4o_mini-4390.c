//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256
#define LOG_ENTRY_SIZE 512

typedef struct {
    char message[BUFFER_SIZE];
    time_t timestamp;
} LogEntry;

void log_event(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "🚨 Shock: Failed to open log file! Something is terribly wrong!\n");
        return;
    }

    LogEntry entry;
    strncpy(entry.message, message, BUFFER_SIZE);
    entry.timestamp = time(NULL);
    
    char formatted_time[100];
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", localtime(&entry.timestamp));
    
    fprintf(file, "[%s] %s\n", formatted_time, entry.message);
    fclose(file);
    printf("✅ Event logged: %s\n", message);
}

void display_events() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        fprintf(stderr, "🚨 Shock: Can't read from log file! It vanished into thin air!\n");
        return;
    }
    
    char line[LOG_ENTRY_SIZE];
    printf("📜 Log Entries:\n");
    
    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("🗑️ Log cleared successfully! But, wait... are you sure?\n");
    } else {
        fprintf(stderr, "🚨 Shock: Unable to clear log file! Should we call for reinforcements?\n");
    }
}

void show_menu() {
    printf("\n==================== EVENT LOGGER ====================\n");
    printf("1. Log an Event\n");
    printf("2. Display Log Events\n");
    printf("3. Clear Log\n");
    printf("0. Exit\n");
    printf("======================================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char event_message[BUFFER_SIZE];

    printf("🌀 Welcome to the Shocking Event Logger! Prepare for the unexpected!\n");

    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("📝 Enter the event message: ");
                fgets(event_message, sizeof(event_message), stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove trailing newline
                log_event(event_message);
                break;
            case 2:
                display_events();
                break;
            case 3:
                clear_log();
                break;
            case 0:
                printf("🚪 Exiting... What a journey it has been!\n");
                exit(0);
            default:
                fprintf(stderr, "🚨 Shock: Invalid choice! How did this happen?!\n");
        }
        sleep(1); // Adding a pause so the shock settles down... 😱
    }

    return 0;
}