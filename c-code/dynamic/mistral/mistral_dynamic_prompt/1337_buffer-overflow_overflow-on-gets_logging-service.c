#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_BUFFER_SIZE 1024

void log_message(char *message) {
    char log_buffer[LOG_BUFFER_SIZE];
    strcpy(log_buffer, "Log: ");
    strcat(log_buffer, message);

    // deliberately unsafe code to introduce buffer overflow vulnerability
    printf(log_buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);

    return 0;
}
