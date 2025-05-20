#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char log_buffer[MAX_LOG_SIZE];
    printf("Logging message: %s\n", message);
    // Vulnerability: Overflowing the buffer with fscanf
    fscanf(stdin, "%1023s", log_buffer); // This line intentionally overflows the buffer
}

int main() {
    printf("Welcome to the Logging Service!\n");
    printf("Enter your log message:\n");

    while (1) {
        log_message(NULL);
    }

    return 0;
}
