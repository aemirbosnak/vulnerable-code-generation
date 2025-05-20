//Falcon-180B DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT_LOG_SIZE 1000
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_message[200];
    time_t event_time;
} EventLog;

int main() {
    FILE *log_file;
    EventLog event_log[MAX_EVENT_LOG_SIZE];
    int event_count = 0;
    int max_event_count = 0;

    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (1) {
        printf("Enter event type (max 50 characters): ");
        scanf("%s", event_log[event_count].event_type);

        printf("Enter event message (max 200 characters): ");
        scanf("%s", event_log[event_count].event_message);

        event_log[event_count].event_time = time(NULL);

        fprintf(log_file, "Event: %s\nMessage: %s\nTimestamp: %s\n",
                event_log[event_count].event_type,
                event_log[event_count].event_message,
                ctime(&event_log[event_count].event_time));

        fflush(log_file);
        event_count++;

        if (event_count >= MAX_EVENT_LOG_SIZE) {
            max_event_count = MAX_EVENT_LOG_SIZE;
        } else {
            max_event_count = event_count;
        }

        rewind(log_file);
        for (int i = 0; i < max_event_count; i++) {
            fprintf(stdout, "Event: %s\nMessage: %s\nTimestamp: %s\n",
                    event_log[i].event_type,
                    event_log[i].event_message,
                    ctime(&event_log[i].event_time));
        }
    }

    fclose(log_file);
    return 0;
}