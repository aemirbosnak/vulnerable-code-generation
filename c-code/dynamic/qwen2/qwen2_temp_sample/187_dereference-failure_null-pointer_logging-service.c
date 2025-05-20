#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    const char *log_entry = NULL;

    // Simulate fetching a log entry from an external source
    // For demonstration purposes, we'll set it to NULL
    log_entry = NULL;

    // Attempt to log the message
    log_message(log_entry);

    printf("Log entry attempted but failed due to null pointer dereference.\n");

    return 0;
}
