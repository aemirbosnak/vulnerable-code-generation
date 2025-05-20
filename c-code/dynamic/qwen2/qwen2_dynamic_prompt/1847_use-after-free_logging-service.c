#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *log_message;
} LogEntry;

void log_message(LogEntry *entry, const char *message) {
    entry->log_message = (char *)malloc(MAX_LOG_SIZE);
    if (entry->log_message == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(entry->log_message, message, MAX_LOG_SIZE - 1);
    entry->log_message[MAX_LOG_SIZE - 1] = '\0';
}

void print_log(const LogEntry *entry) {
    printf("Log: %s\n", entry->log_message);
}

int main() {
    LogEntry *entry = (LogEntry *)malloc(sizeof(LogEntry));
    if (entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    log_message(entry, "This is a test log message.");
    print_log(entry);

    // Free the memory
    free(entry->log_message);
    entry->log_message = NULL; // Set to NULL after freeing

    // Use-after-free vulnerability
    print_log(entry); // This will access freed memory

    free(entry); // Double free

    return 0;
}
