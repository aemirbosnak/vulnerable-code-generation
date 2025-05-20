//Falcon-180B DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000
#define MAX_LOG_ENTRY_SIZE 200
#define LOG_FILE_NAME "event_log.txt"

typedef struct {
    char event_type[50];
    char event_message[MAX_LOG_ENTRY_SIZE];
    time_t event_time;
} EventLogEntry;

void init_log(FILE *log_file) {
    fprintf(log_file, "Event Log Initialized\n");
}

void log_event(FILE *log_file, char *event_type, char *event_message) {
    time_t event_time = time(NULL);
    strftime(event_message + strlen(event_message), MAX_LOG_ENTRY_SIZE - strlen(event_message), " %Y-%m-%d %H:%M:%S", localtime(&event_time));
    fprintf(log_file, "%s: %s\n", event_type, event_message);
}

void close_log(FILE *log_file) {
    fprintf(log_file, "Event Log Closed\n");
    fclose(log_file);
}

int main() {
    FILE *log_file = fopen(LOG_FILE_NAME, "w");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return 1;
    }

    init_log(log_file);

    EventLogEntry event_log[MAX_LOG_SIZE];
    int num_events = 0;

    while (1) {
        char event_type[50];
        printf("Enter event type: ");
        scanf("%s", event_type);

        char event_message[MAX_LOG_ENTRY_SIZE];
        printf("Enter event message: ");
        scanf("%s", event_message);

        log_event(log_file, event_type, event_message);
        strcpy(event_log[num_events].event_type, event_type);
        strcpy(event_log[num_events].event_message, event_message);
        event_log[num_events].event_time = time(NULL);
        num_events++;

        if (num_events >= MAX_LOG_SIZE) {
            close_log(log_file);
            printf("Log file closed\n");
            break;
        }
    }

    return 0;
}