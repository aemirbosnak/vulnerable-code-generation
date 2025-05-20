//Falcon-180B DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "event_log.txt"

typedef struct {
    char event[100];
    time_t timestamp;
} LogEntry;

FILE *logfile;

void init_logger() {
    logfile = fopen(LOG_FILE, "w");
    if (logfile == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }
}

void log_event(char *event) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    LogEntry entry = {
       .event = event,
       .timestamp = now
    };

    fprintf(logfile, "%04d-%02d-%02d %02d:%02d:%02d - %s\n",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec, entry.event);

    if (ftell(logfile) >= MAX_LOG_ENTRIES * 1024) {
        fclose(logfile);
        logfile = fopen(LOG_FILE, "w");
    }
}

int main() {
    init_logger();

    for (int i = 0; i < 1000; i++) {
        char event[100] = {0};
        sprintf(event, "Event %d", i);
        log_event(event);
    }

    fclose(logfile);
    return 0;
}