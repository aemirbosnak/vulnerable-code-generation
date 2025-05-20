#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} LogEntry;

void log_message(LogEntry *entry, const char *message) {
    size_t new_length = entry->length + strlen(message) + 1;
    if (new_length > MAX_LOG_SIZE) {
        printf("Log buffer overflow!\n");
        exit(1);
    }
    strcpy(entry->buffer + entry->length, message);
    entry->length = new_length;
}

int main() {
    LogEntry log = {malloc(MAX_LOG_SIZE), 0};
    
    // Simulate logging a large number of messages to cause overflow
    for (size_t i = 0; i < MAX_LOG_SIZE / 10; i++) {
        char msg[10];
        snprintf(msg, sizeof(msg), "Message %zu\n", i);
        log_message(&log, msg);
    }

    free(log.buffer);
    return 0;
}
