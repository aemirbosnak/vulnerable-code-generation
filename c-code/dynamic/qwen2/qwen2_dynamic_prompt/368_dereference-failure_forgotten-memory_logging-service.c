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
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    int *ptr = NULL;
    *ptr = 42; // Dereference null pointer

    log_message("This is a test log message");

    free(ptr); // Freeing unallocated memory

    return 0;
}
