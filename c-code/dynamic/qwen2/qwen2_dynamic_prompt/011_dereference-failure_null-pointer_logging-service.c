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
    if (entry == NULL || message == NULL) {
        fprintf(stderr, "Error: Null pointer encountered.\n");
        return;
    }
    entry->log_message = (char *)malloc(MAX_LOG_SIZE * sizeof(char));
    if (entry->log_message == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }
    strncpy(entry->log_message, message, MAX_LOG_SIZE - 1);
    entry->log_message[MAX_LOG_SIZE - 1] = '\0';
}

void print_log(const LogEntry *entry) {
    if (entry == NULL || entry->log_message == NULL) {
        fprintf(stderr, "Error: Null pointer encountered.\n");
        return;
    }
    printf("Log: %s\n", entry->log_message);
}

int main() {
    LogEntry *entry = NULL;
    log_message(entry, "This is a test log message.");
    print_log(entry);

    free(entry->log_message); // This will cause a null pointer dereference if not checked
    return 0;
}
