#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char log[MAX_LOG_SIZE];
} LogEntry;

void log_message(LogEntry *entry, const char *message) {
    if (entry == NULL || message == NULL) {
        return;
    }
    strncpy(entry->log, message, sizeof(entry->log) - 1);
    entry->log[sizeof(entry->log) - 1] = '\0';
}

void print_log(const LogEntry *entry) {
    if (entry != NULL) {
        printf("Log: %s\n", entry->log);
    } else {
        printf("Error: Null log entry.\n");
    }
}

int main() {
    LogEntry logs[10];

    // Simulate logging messages
    for (int i = 0; i < 10; i++) {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "Message %d", i);
        log_message(&logs[i], buffer);
    }

    // Intentionally access out-of-bounds array element to cause a dereference failure
    log_message(&logs[10], "This should fail"); // Out-of-bounds write

    // Print all logs
    for (int i = 0; i <= 10; i++) { // One extra iteration to trigger the failure
        print_log(&logs[i]);
    }

    return 0;
}
