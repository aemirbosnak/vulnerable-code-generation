#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char log_buffer[MAX_LOG_SIZE];
    if (sscanf(message, "%1023s", log_buffer) != 1) {
        fprintf(stderr, "Failed to parse message\n");
        return;
    }
    printf("Logged: %s\n", log_buffer);
}

int main() {
    char input[2048];
    printf("Enter a log message: ");
    fgets(input, sizeof(input), stdin);

    // Simulate processing the input
    for (int i = 0; i < 10; i++) {
        log_message(input);
    }

    return 0;
}
