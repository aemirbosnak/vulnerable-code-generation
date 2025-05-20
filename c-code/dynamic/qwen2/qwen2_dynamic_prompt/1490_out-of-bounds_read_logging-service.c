#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_SIZE 1024

typedef struct {
    char buffer[LOG_SIZE];
} LogEntry;

void log_message(LogEntry *entry, const char *message) {
    if (strlen(message) >= sizeof(entry->buffer)) {
        entry->buffer[sizeof(entry->buffer) - 1] = '\0';
    } else {
        strcpy(entry->buffer, message);
    }
}

int main() {
    LogEntry logs[10];

    // Simulate logging messages
    for (int i = 0; i < 10; i++) {
        snprintf(logs[i].buffer, sizeof(logs[i].buffer), "Log entry %d", i);
    }

    // Intentionally read out-of-bounds to demonstrate vulnerability
    printf("Reading from out-of-bounds: %s\n", logs[9].buffer + 1024);

    return 0;
}
