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

    // Simulate a scenario where the message is not properly initialized
    entry->message = NULL;

    // Intentionally dereference an invalid pointer
    printf("Logging: %s\n", entry->message);

    free(entry);

    return 0;
}
