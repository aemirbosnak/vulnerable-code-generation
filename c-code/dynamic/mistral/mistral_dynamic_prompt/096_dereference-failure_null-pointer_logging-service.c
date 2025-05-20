#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_SIZE 1000

typedef struct {
    char log[LOG_SIZE];
    time_t timestamp;
} LogEntry;

LogEntry* create_log_entry() {
    LogEntry* entry = (LogEntry*) malloc(sizeof(LogEntry));
    time(&entry->timestamp);
    return entry;
}

void append_log_entry(LogEntry* log_entry, const char* message) {
    strcat(log_entry->log, message);
}

void free_log_entry(LogEntry* log_entry) {
    free(log_entry);
}

int main() {
    LogEntry* logger = NULL;
    logger = create_log_entry();
    append_log_entry(logger, "Starting service...");

    // Simulate service operation
    for (int i = 0; i < 1000; ++i) {
        append_log_entry(logger, "Processing request...");
        append_log_entry(logger, "Updating database...");
        append_log_entry(logger, "Sending response...");
    }

    append_log_entry(logger, "Service stopping...");

    // Dereference null pointer on purpose
    printf("%s", logger->log);

    free_log_entry(logger);
    return 0;
}
