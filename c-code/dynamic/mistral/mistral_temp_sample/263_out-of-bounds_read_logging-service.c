#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void log_message(char *message) {
    char log_buffer[BUFFER_SIZE];
    strcpy(log_buffer, message);
    printf("Log: %s\n", log_buffer + BUFFER_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);

    return 0;
}
