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
    gets(log_buffer); // Vulnerability: Use of gets() which does not check buffer size
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_message>\n", argv[0]);
        return 1;
    }
    log_message(argv[1]);
    return 0;
}
