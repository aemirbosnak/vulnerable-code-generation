//Falcon-180B DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_LOG_SIZE 1000
#define MAX_LOG_ENTRIES 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char date_time[20];
    char event_type[20];
    char event_message[200];
} LogEntry;

void log_event(char* event_type, char* event_message) {
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    strftime(event_type, 20, "%Y-%m-%d %H:%M:%S", current_time);
    strcat(event_type, " ");
    strcat(event_type, event_message);
    strcat(event_type, "\n");

    FILE* log_file = fopen(LOG_FILE, "a");

    if (log_file!= NULL) {
        fwrite(event_type, strlen(event_type), 1, log_file);
        fclose(log_file);
    }
}

void print_log(FILE* log_file) {
    char log_entry[300];
    LogEntry entry;

    rewind(log_file);

    while (fgets(log_entry, sizeof(log_entry), log_file)!= NULL) {
        sscanf(log_entry, "%s %s %s", entry.date_time, entry.event_type, entry.event_message);
        printf("%s - %s\n%s\n", entry.date_time, entry.event_type, entry.event_message);
    }
}

int main() {
    FILE* log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        printf("Event log file not found.\n");
        return 1;
    }

    printf("Event Log:\n");
    print_log(log_file);

    fclose(log_file);

    return 0;
}