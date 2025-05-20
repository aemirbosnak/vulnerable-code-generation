//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char timestamp[30];
    char event[256];
} Event;

void getCurrentTime(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void logEvent(Event *event, const char *message) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }
    fprintf(fp, "%s: %s\n", event->timestamp, message);
    fclose(fp);
    printf("Event logged: %s\n", message);
}

void displayMenu() {
    printf("\n--- Peaceful Event Logger ---\n");
    printf("1. Log an event\n");
    printf("2. View logged events\n");
    printf("3. Clear all logged events\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

void viewEvents() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open log file for reading.\n");
        return;
    }
    char line[512];
    printf("\n--- Logged Events ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("---------------------\n");
}

void clearEvents() {
    if (remove(LOG_FILE) == 0) {
        printf("All events have been cleared from the log.\n");
    } else {
        fprintf(stderr, "Could not clear log file.\n");
    }
}

int main() {
    Event event;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // Clear newline character

        switch (choice) {
            case 1:
                printf("Enter the event description: ");
                fgets(event.event, sizeof(event.event), stdin);
                event.event[strcspn(event.event, "\n")] = 0;  // Remove newline
                getCurrentTime(event.timestamp, sizeof(event.timestamp));
                logEvent(&event, event.event);
                break;
            case 2:
                viewEvents();
                break;
            case 3:
                clearEvents();
                break;
            case 4:
                printf("Exiting the peaceful event logger. Take care!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}