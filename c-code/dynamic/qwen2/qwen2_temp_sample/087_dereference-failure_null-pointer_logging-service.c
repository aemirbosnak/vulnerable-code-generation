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

    // Simulate an error condition
    void (*func_ptr)(const char *) = NULL;
    func_ptr("This should cause a null pointer dereference");

    log_entry = "Application ended";
    log_message(log_entry);

    return 0;
}
