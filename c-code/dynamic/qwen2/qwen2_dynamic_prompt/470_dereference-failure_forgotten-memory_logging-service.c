#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

typedef struct {
    char *message;
} LogEntry;

void log_message(LogEntry *entry) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", entry->message);
    fclose(file);
}

int main() {
    LogEntry *entry = malloc(sizeof(LogEntry));
    if (entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate logging multiple messages
    for (int i = 0; i < 10; i++) {
        entry->message = malloc(256);
        if (entry->message == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(entry);
            return 1;
        }
        snprintf(entry->message, 256, "Log message %d", i);
        log_message(entry);
        free(entry->message); // Freeing the allocated memory
    }

    // Intentionally forgetting to free the memory pointed by 'entry'
    // This is a deliberate mistake to demonstrate a dereference failure

    return 0;
}
