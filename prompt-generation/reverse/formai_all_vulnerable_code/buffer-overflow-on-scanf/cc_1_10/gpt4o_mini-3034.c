//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 256
#define LOG_FILE "system_events.log"

typedef struct {
    char event[256];
    time_t timestamp;
} Event;

Event eventLog[MAX_EVENTS];
int eventCount = 0;

void logEvent(const char *event) {
    if (eventCount < MAX_EVENTS) {
        strncpy(eventLog[eventCount].event, event, sizeof(eventLog[eventCount].event));
        eventLog[eventCount].timestamp = time(NULL);
        eventCount++;
    } else {
        printf("Error: Event log is full.\n");
    }
}

void writeLogToFile() {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    for (int i = 0; i < eventCount; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&eventLog[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        fprintf(file, "[%s] %s\n", buffer, eventLog[i].event);
    }

    fclose(file);
}

void displayMenu() {
    printf("System Event Logger\n");
    printf("1. Log Event\n");
    printf("2. View Logs\n");
    printf("3. Clear Logs\n");
    printf("4. Exit\n");
}

void clearLogs() {
    eventCount = 0;
    printf("Event log has been cleared.\n");
}

void viewLogs() {
    printf("Displaying logged events:\n");
    for (int i = 0; i < eventCount; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&eventLog[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("[%s] %s\n", buffer, eventLog[i].event);
    }

    if (eventCount == 0) {
        printf("No events logged.\n");
    }
}

int main() {
    int choice;
    char event[256];

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event, sizeof(event), stdin);
                event[strcspn(event, "\n")] = 0; // Remove newline
                logEvent(event);
                printf("Event logged successfully!\n");
                break;
            case 2:
                writeLogToFile();
                viewLogs();
                break;
            case 3:
                clearLogs();
                break;
            case 4:
                printf("Exiting... Thank you for using the Event Logger!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}