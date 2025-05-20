//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define LOG_FILE "event_log.txt"

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Failed to open log file.\n");
        return;
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

void read_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        fprintf(stderr, "No logs found.\n");
        return;
    }
    
    char line[MAX_LOG_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clear_logs() {
    if (remove(LOG_FILE) == 0) {
        printf("Logs cleared.\n");
    } else {
        fprintf(stderr, "Error clearing logs.\n");
    }
}

int main() {
    int option;
    char event[MAX_LOG_LENGTH];

    while (1) {
        printf("Log Event Program\n");
        printf("1. Log an event\n");
        printf("2. Read logs\n");
        printf("3. Clear logs\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Consume newline
        
        switch (option) {
            case 1:
                printf("Enter event description: ");
                fgets(event, sizeof(event), stdin);
                event[strcspn(event, "\n")] = 0; // Remove newline
                log_event(event);
                printf("Event logged.\n");
                break;
            case 2:
                printf("Reading logs...\n");
                read_logs();
                break;
            case 3:
                clear_logs();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}