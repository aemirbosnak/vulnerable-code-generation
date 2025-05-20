//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_EVENT_SIZE 256
#define LOG_FILE "event_log.txt"

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} EventLogEntry;

void log_event(const char *event) {
    FILE *log_file;
    EventLogEntry entry;
    struct tm *time_info;
    char timestamp_str[17];

    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    time(&entry.timestamp);
    time_info = localtime(&entry.timestamp);
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", time_info);

    strcpy(entry.event, event);
    strcat(entry.event, " [");
    strcat(entry.event, timestamp_str);
    strcat(entry.event, "]");

    fwrite(&entry, sizeof(EventLogEntry), 1, log_file);

    fclose(log_file);
    printf("Event logged: %s\n", entry.event);
}

int main() {
    char event[MAX_EVENT_SIZE];

    printf("Enter an event to log: ");
    scanf("%s", event);

    log_event(event);

    return 0;
}