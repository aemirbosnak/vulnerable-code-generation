//Falcon-180B DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_LINE_SIZE 1024

typedef struct {
    time_t timestamp;
    char event[MAX_LINE_SIZE];
} Event;

void log_event(const char* event) {
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm);

    Event e = {
       .timestamp = now,
       .event = event
    };

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return;
    }

    fprintf(log_file, "%s: %s\n", timestamp, e.event);
    fclose(log_file);
}

int main() {
    log_event("Program started");

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Log an event\n");
        printf("2. View event log\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char event[MAX_LINE_SIZE];
            printf("Enter event to log:\n");
            scanf("%s", event);
            log_event(event);
            break;
        }
        case 2: {
            FILE* log_file = fopen(LOG_FILE, "r");
            if (log_file == NULL) {
                printf("Log file is empty\n");
            } else {
                char line[MAX_LINE_SIZE];
                while (fgets(line, sizeof(line), log_file)!= NULL) {
                    printf("%s", line);
                }
                fclose(log_file);
            }
            break;
        }
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}