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
    LogEntry log;
    FILE *file = fopen("log.txt", "r");
    
    if (!file) {
        printf("Failed to open log file.\n");
        return 1;
    }

    while (fgets(log.buffer, sizeof(log.buffer), file)) {
        // Simulate processing the log entry
        printf("%s", log.buffer);
    }

    fclose(file);

    // Out-of-bounds read example
    char *out_of_bounds = log.buffer + sizeof(log.buffer);
    printf("Out-of-bounds read: %s\n", out_of_bounds);

    return 0;
}
