//Falcon-180B DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LOG_FILE_SIZE 100000 // 100 KB
#define LOG_FILE_NAME "event_log.txt"

typedef struct {
    char event_type[50];
    char event_description[200];
    time_t timestamp;
} Event;

void log_event(Event event) {
    FILE *log_file;
    log_file = fopen(LOG_FILE_NAME, "a");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(log_file, "Event Type: %s\n", event.event_type);
    fprintf(log_file, "Event Description: %s\n", event.event_description);
    fprintf(log_file, "Timestamp: %s\n", ctime(&event.timestamp));
    fprintf(log_file, "\n");

    fclose(log_file);
}

void check_log_file_size() {
    struct stat log_file_stat;
    int log_file_size = 0;

    stat(LOG_FILE_NAME, &log_file_stat);
    log_file_size = log_file_stat.st_size;

    if (log_file_size >= MAX_LOG_FILE_SIZE) {
        printf("Warning: Log file size exceeds limit.\n");
        truncate(LOG_FILE_NAME, 0);
    }
}

int main() {
    Event event;

    while (1) {
        printf("Enter event type (up to 50 characters): ");
        scanf("%s", event.event_type);

        printf("Enter event description (up to 200 characters): ");
        scanf("%[^\n]", event.event_description);

        event.timestamp = time(NULL);
        log_event(event);

        check_log_file_size();
    }

    return 0;
}