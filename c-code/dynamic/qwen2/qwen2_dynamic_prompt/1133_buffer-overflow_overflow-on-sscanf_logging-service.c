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
        fprintf(stderr, "Error parsing message\n");
        return;
    }
    printf("Logged: %s\n", log_buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);

    return 0;
}
