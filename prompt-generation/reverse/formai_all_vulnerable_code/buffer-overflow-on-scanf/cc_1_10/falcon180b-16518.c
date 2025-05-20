//Falcon-180B DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOG_SIZE 100
#define LOG_FILE "event.log"

typedef struct {
    char event[50];
    char date[30];
    char time[10];
} log_entry;

void log_event(char* event) {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    char date[30];
    strftime(date, 30, "%Y-%m-%d", timeinfo);
    char time[10];
    strftime(time, 10, "%H:%M:%S", timeinfo);

    FILE* log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    log_entry entry;
    strcpy(entry.event, event);
    strcpy(entry.date, date);
    strcpy(entry.time, time);

    fprintf(log, "%s | %s | %s\n", entry.event, entry.date, entry.time);
    fclose(log);
}

int main() {
    setbuf(stdout, NULL);
    printf("Starting event logger...\n");

    while (1) {
        char event[50];
        printf("Enter an event to log: ");
        scanf("%s", event);
        log_event(event);
        sleep(1);
    }

    return 0;
}