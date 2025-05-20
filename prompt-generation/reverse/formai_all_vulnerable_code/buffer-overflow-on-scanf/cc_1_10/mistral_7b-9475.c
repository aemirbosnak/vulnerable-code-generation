//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LEN 256
#define LOG_FILE "event.log"

typedef struct {
    char timestamp[32];
    char event[MAX_EVENT_LEN];
} event_log_entry_t;

void create_timestamp(char* timestamp) {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
}

int log_event(const char* event) {
    FILE* log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    event_log_entry_t entry;
    create_timestamp(entry.timestamp);
    strncpy(entry.event, event, MAX_EVENT_LEN);

    fwrite(&entry, sizeof(event_log_entry_t), 1, log_file);

    fclose(log_file);

    return 0;
}

int main(void) {
    char event[MAX_EVENT_LEN];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter event %d: ", i + 1);
        scanf("%s", event);

        if (log_event(event)) {
            perror("Error logging event");
            return 1;
        }
    }

    printf("Logged events successfully.\n");

    return 0;
}