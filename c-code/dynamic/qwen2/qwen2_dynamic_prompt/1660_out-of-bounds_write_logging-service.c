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
    strcpy(entry->buffer, message);
}

int main() {
    LogEntry entry;
    log_message(&entry, "This is a test log message.");
    printf("Log: %s\n", entry.buffer);

    // Intentional out-of-bounds write to demonstrate vulnerability
    log_message(&entry, "This message is too long and will cause an overflow.");

    return 0;
}
