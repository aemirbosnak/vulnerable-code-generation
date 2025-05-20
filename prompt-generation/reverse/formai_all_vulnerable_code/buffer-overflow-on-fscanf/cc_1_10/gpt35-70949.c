//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define EVENT_LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 100
#define MAX_TIMESTAMP_LEN 30

// function to log events
void log_event(char *event) {
    // get current timestamp
    time_t now;
    struct tm *t;
    char timestamp[MAX_TIMESTAMP_LEN];
    time(&now);
    t = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    // open the event log file for writing (append mode)
    FILE *log_file;
    log_file = fopen(EVENT_LOG_FILE, "a");

    // write the event and timestamp to the log file
    fprintf(log_file, "[%s] %s\n", timestamp, event);

    // close the log file
    fclose(log_file);
}

// function to read the event log file
void read_event_log() {
    // open the event log file for reading
    FILE *log_file;
    log_file = fopen(EVENT_LOG_FILE, "r");

    // read and print each event from the log file
    char event[MAX_EVENT_LEN];
    char timestamp[MAX_TIMESTAMP_LEN];
    while (fscanf(log_file, "[%[^]]] %[^\n]\n", timestamp, event) != EOF) {
        printf("%s: %s\n", timestamp, event);
    }

    // close the log file
    fclose(log_file);
}

// main function to test the event logger
int main() {
    // log some events
    log_event("System started up.");
    log_event("User logged in.");
    log_event("File opened successfully.");

    // read and print the event log
    printf("Event Log:\n");
    read_event_log();

    return 0;
}