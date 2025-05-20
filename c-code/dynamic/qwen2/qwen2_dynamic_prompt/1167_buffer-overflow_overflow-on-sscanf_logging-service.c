#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char buffer[MAX_LOG_SIZE];
    if (sscanf(message, "%1023s", buffer) != 1) {
        fprintf(stderr, "Failed to parse message\n");
        return;
    }
    printf("Logged: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);

    return 0;
}
