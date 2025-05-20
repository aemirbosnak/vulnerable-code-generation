//Falcon-180B DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event.log"
#define MAX_LINE 1024
#define TIME_FMT "%d-%m-%Y %H:%M:%S"

typedef struct {
    char *app_name;
    char *event;
    time_t timestamp;
} Event;

void log_event(const char *app_name, const char *event)
{
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error opening log file: %s\n", LOG_FILE);
        exit(1);
    }

    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char timestamp[MAX_LINE];
    strftime(timestamp, MAX_LINE, TIME_FMT, &tm);

    Event event_data = {
       .app_name = app_name,
       .event = event,
       .timestamp = now
    };

    fprintf(log_file, "%s - %s: %s\n", timestamp, event_data.app_name, event_data.event);

    fclose(log_file);
}

int main()
{
    log_event("MyApp", "Started");

    // Simulate some events
    log_event("MyApp", "Event 1");
    log_event("MyApp", "Event 2");
    log_event("MyApp", "Event 3");

    log_event("MyApp", "Stopped");

    return 0;
}