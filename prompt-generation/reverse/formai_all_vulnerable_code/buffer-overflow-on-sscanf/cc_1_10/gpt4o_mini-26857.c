//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENTS 100

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventType;

const char *eventTypeToString(EventType type) {
    switch (type) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

void logEvent(EventType type, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }
    
    char time_buffer[20];
    timestamp(time_buffer, sizeof(time_buffer));
    
    fprintf(file, "[%s] [%s]: %s\n", time_buffer, eventTypeToString(type), message);
    fclose(file);
}

void displayLogs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Failed to read log file");
        return;
    }

    char line[256];
    printf("\n--- Event Log ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
    printf("------------------\n");
}

void handleUserInput() {
    char input[256];
    printf("Enter event type (info/warning/error) and a message (CTRL+D to exit):\n");
    
    while (fgets(input, sizeof(input), stdin)) {
        char type[10];
        char message[240];
        if (sscanf(input, "%s %[^\n]", type, message) == 2) {
            EventType eventType;
            if (strcmp(type, "info") == 0) {
                eventType = INFO;
            } else if (strcmp(type, "warning") == 0) {
                eventType = WARNING;
            } else if (strcmp(type, "error") == 0) {
                eventType = ERROR;
            } else {
                printf("Unknown event type! Please use info/warning/error.\n");
                continue;
            }
            logEvent(eventType, message);
            printf("Logged event of type %s: %s\n", type, message);
        } else {
            printf("Invalid input format! Please enter event type followed by a message.\n");
        }
    }
}

int main() {
    printf("Welcome to the Curious Event Logger!\n");
    printf("This program logs your events into a file with timestamps.\n");
    printf("You can log up to %d events.\n\n", MAX_EVENTS);
    
    // Main loop for user input
    handleUserInput();
    
    printf("\nWould you like to see the logged events? (yes/no): ");
    char response[4];
    scanf("%3s", response);
    
    if (strcmp(response, "yes") == 0) {
        displayLogs();
    } else {
        printf("Thank you for using the Event Logger! Goodbye!\n");
    }
    
    return 0;
}