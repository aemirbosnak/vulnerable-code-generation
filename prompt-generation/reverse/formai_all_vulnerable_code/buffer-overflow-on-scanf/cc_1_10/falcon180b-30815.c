//Falcon-180B DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 100

typedef struct {
    char message[MAX_LOG_ENTRY_LENGTH];
    time_t timestamp;
} LogEntry;

int append_log_entry(LogEntry *log, char *message) {
    if (log->timestamp == 0) {
        log->timestamp = time(NULL);
    }
    strncpy(log->message, message, MAX_LOG_ENTRY_LENGTH - 1);
    log->message[MAX_LOG_ENTRY_LENGTH - 1] = '\0';
    return 0;
}

void print_log_entries(LogEntry *log, int count) {
    printf("Log Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", ctime(&log[i].timestamp), log[i].message);
    }
}

int main() {

    LogEntry log[MAX_LOG_ENTRIES];
    int log_entry_count = 0;

    while (1) {
        char input[MAX_LOG_ENTRY_LENGTH];
        printf("Enter a message to log (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        append_log_entry(&log[log_entry_count], input);
        log_entry_count++;

        if (log_entry_count >= MAX_LOG_ENTRIES) {
            log_entry_count = 0;
        }
    }

    print_log_entries(log, log_entry_count);

    return 0;
}