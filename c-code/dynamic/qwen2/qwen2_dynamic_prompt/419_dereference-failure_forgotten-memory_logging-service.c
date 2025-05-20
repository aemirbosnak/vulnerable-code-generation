#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "app.log"

typedef struct {
    char *message;
} LogEntry;

void log_message(LogEntry *entry) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", entry->message);
    fclose(file);
}

int main() {
    LogEntry *entry = malloc(sizeof(LogEntry));
    if (entry == NULL) {
        perror("Failed to allocate memory for log entry");
        return EXIT_FAILURE;
    }

    // Simulate logging multiple messages
    for (int i = 0; i < 10; i++) {
        entry->message = malloc(256);
        if (entry->message == NULL) {
            perror("Failed to allocate memory for message");
            free(entry);
            return EXIT_FAILURE;
        }
        snprintf(entry->message, 256, "Log entry %d", i);
        log_message(entry);
        free(entry->message); // Freeing the allocated memory
    }

    // Intentionally forgetting to free the memory pointed by 'entry'
    // This is a deliberate dereference failure (forgotten memory)

    return EXIT_SUCCESS;
}
