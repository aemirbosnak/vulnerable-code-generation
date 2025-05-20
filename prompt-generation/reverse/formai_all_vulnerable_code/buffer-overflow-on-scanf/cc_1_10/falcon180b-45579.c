//Falcon-180B DATASET v1.0 Category: System event logger ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_description[200];
    time_t event_time;
} EventLog;

void log_event(EventLog *event_log, char *event_type, char *event_description) {
    strcpy(event_log->event_type, event_type);
    strcpy(event_log->event_description, event_description);
    event_log->event_time = time(NULL);
}

void write_to_file(EventLog *event_log) {
    FILE *file;
    file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }
    fprintf(file, "Event Type: %s\n", event_log->event_type);
    fprintf(file, "Event Description: %s\n", event_log->event_description);
    fprintf(file, "Event Time: %s", ctime(&event_log->event_time));
    fclose(file);
}

int main() {
    EventLog event_log;
    char event_type[50];
    char event_description[200];

    printf("Event Logger\n");
    while (1) {
        printf("\nEnter event type (max 50 characters): ");
        scanf("%s", event_type);
        printf("Enter event description (max 200 characters): ");
        scanf("%[^\n]", event_description);
        log_event(&event_log, event_type, event_description);
        write_to_file(&event_log);
        printf("\nEvent logged successfully.\n");
    }

    return 0;
}