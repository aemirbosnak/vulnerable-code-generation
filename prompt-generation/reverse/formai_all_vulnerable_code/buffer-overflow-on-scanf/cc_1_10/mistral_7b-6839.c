//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LEN 256
#define LOG_FILE "event_log.txt"

typedef struct {
    char time[20];
    char event[MAX_EVENT_LEN];
} EventLog;

void log_event(const char *event) {
    FILE *log_file;
    EventLog current_log;
    time_t now;

    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    time(&now);
    strftime(current_log.time, sizeof(current_log.time), "%Y-%m-%d %H:%M:%S", localtime(&now));

    strcpy(current_log.event, event);

    fwrite(&current_log, sizeof(EventLog), 1, log_file);
    fclose(log_file);

    printf("Event logged: %s\n", event);
}

int main() {
    int i;

    for (i = 0; i < MAX_EVENTS; i++) {
        char event[MAX_EVENT_LEN];
        printf("Enter event %d: ", i+1);
        scanf("%s", event);

        if (strlen(event) > MAX_EVENT_LEN - 1) {
            printf("Error: event length exceeds maximum\n");
            break;
        }

        log_event(event);
    }

    printf("Logging completed.\n");

    return EXIT_SUCCESS;
}