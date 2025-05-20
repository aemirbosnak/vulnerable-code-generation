//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256
#define COMMAND_LENGTH 10

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove the newline character

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void view_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Log file does not exist or could not be opened.\n");
        return;
    }
    
    char buffer[MAX_EVENT_LENGTH + 50]; // Extra space for timestamp and formatting
    printf("Event Log:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void clear_logs() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file for clearing.\n");
        return;
    }
    fclose(file); // Just opening and closing truncates the file
    printf("Log file cleared.\n");
}

int main() {
    char command[COMMAND_LENGTH];
    char event[MAX_EVENT_LENGTH];
    
    while (1) {
        printf("\nCommand (log/view/clear/exit): ");
        scanf("%s", command);

        if (strcmp(command, "log") == 0) {
            printf("Enter the event to log: ");
            getchar(); // consume newline character left by scanf
            fgets(event, sizeof(event), stdin);
            event[strcspn(event, "\n")] = 0; // Trim newline character from input
            log_event(event);
            printf("Event logged: %s\n", event);
        } else if (strcmp(command, "view") == 0) {
            view_logs();
        } else if (strcmp(command, "clear") == 0) {
            clear_logs();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the event logger.\n");
            break;
        } else {
            printf("Unknown command. Please use log/view/clear/exit.\n");
        }
    }
    
    return 0;
}