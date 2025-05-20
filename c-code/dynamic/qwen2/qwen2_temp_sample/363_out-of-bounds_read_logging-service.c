#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(char *message) {
    char log[MAX_LOG_SIZE];
    int i;

    // Simulate reading from an untrusted source
    for (i = 0; message[i] != '\0' && i < MAX_LOG_SIZE; i++) {
        log[i] = message[i];
    }
    log[i] = '\0'; // Null-terminate the string

    // Vulnerability: Out-of-bounds read
    printf("Log: %s\n", log);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);

    return 0;
}
