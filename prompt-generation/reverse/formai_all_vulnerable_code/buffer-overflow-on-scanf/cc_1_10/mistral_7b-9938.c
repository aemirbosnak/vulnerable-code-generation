//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 1024
#define LOG_PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

typedef struct {
    time_t timestamp;
    pid_t pid;
    char event[MAX_EVENT_LEN];
} LogEntry;

void log_event(const char *event) {
    FILE *log_file;
    LogEntry new_entry;

    time_t now;
    struct tm *now_tm;

    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    now = time(NULL);
    now_tm = localtime(&now);

    new_entry.timestamp = now;
    new_entry.pid = getpid();
    strcpy(new_entry.event, event);

    fwrite(&new_entry, sizeof(LogEntry), 1, log_file);

    fprintf(log_file, "%s %ld: %s\n", asctime(now_tm), new_entry.pid, event);
    fclose(log_file);
}

int main(void) {
    char *event = malloc(sizeof(char) * 50);

    printf("Surprise! An event logger has been activated!\n");

    while (1) {
        printf("Enter an event to log: ");
        scanf("%s", event);

        log_event(event);
        printf("Event logged successfully!\n");
    }

    free(event);
    return EXIT_SUCCESS;
}