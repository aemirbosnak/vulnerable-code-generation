#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *message;
} LogEntry;

void log_message(LogEntry *entry, const char *msg) {
    entry->message = strdup(msg);
}

void free_log_entry(LogEntry *entry) {
    if (entry->message != NULL) {
        free(entry->message);
        entry->message = NULL; // Freeing the memory
    }
}

int main() {
    LogEntry *log_entries[MAX_LOG_SIZE];
    int num_logs = 0;

    while (1) {
        printf("Enter log message (or 'exit' to quit): ");
        char input[256];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        if (num_logs >= MAX_LOG_SIZE) {
            printf("Log buffer full!\n");
            continue;
        }

        log_entries[num_logs] = malloc(sizeof(LogEntry));
        if (log_entries[num_logs] == NULL) {
            perror("Failed to allocate memory for log entry");
            exit(EXIT_FAILURE);
        }

        log_message(log_entries[num_logs], input);
        num_logs++;
    }

    // Simulate forgetting to free some log entries
    for (int i = 0; i < num_logs - 1; i++) {
        free_log_entry(log_entries[i]);
    }

    // Intentionally forget to free the last log entry
    // This is the forgotten memory vulnerability

    return 0;
}
