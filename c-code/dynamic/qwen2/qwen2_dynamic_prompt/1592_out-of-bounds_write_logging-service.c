#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_FILE "log.txt"
#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char buffer[10];
    strcpy(buffer, "This is a test log message.");
    log_message(buffer);

    // Out-of-bounds write example
    char large_buffer[MAX_LOG_SIZE + 1];
    memset(large_buffer, 'A', sizeof(large_buffer));
    large_buffer[sizeof(large_buffer) - 1] = '\0';
    log_message(large_buffer);

    return 0;
}
