#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    const char *log_entry = "System startup";
    log_message(log_entry);

    // Simulate a null pointer dereference
    char *buffer = NULL;
    printf("%s\n", buffer); // Dereferencing a null pointer

    log_entry = "System shutdown";
    log_message(log_entry);

    return 0;
}
