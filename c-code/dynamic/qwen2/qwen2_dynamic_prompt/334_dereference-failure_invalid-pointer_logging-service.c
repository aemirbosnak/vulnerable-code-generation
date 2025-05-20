#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "app.log"

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
    const char *log_entry = "Application started";
    log_message(log_entry);

    // Simulate an invalid pointer dereference
    int *ptr = NULL;
    *ptr = 42; // Dereferencing a null pointer

    log_entry = "An error occurred";
    log_message(log_entry);

    return 0;
}
